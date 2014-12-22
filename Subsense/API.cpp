//
//  API.cpp
//  Subsense
//
//  Created by Saumitro Dasgupta on 12/18/14.
//  Copyright (c) 2014 Saumitro Dasgupta. All rights reserved.
//

#include "API.h"
#include "BackgroundSubtractorSuBSENSE.h"
#include <opencv2/opencv.hpp>

struct SSContext
{
    SSContext() : subsense(nullptr) {}
    ~SSContext()
    {
        if(subsense!=nullptr)
        {
            delete subsense;
        }
    }
    
    BackgroundSubtractorSuBSENSE* subsense;
    cv::Size2i imgSize;
};

SSContext* ss_create(void* img_data,
                     int width,
                     int height,
                     float lbsp_thresh,
                     size_t desc_dist_thresh_offset,
                     size_t min_color_dist_thresh,
                     size_t num_bg_samples,
                     size_t num_req_bg_samples,
                     size_t num_samples_for_moving_avg)
{
    SSContext* ctx = new SSContext();
    ctx->imgSize = cv::Size2i(width, height);
    cv::Mat img(ctx->imgSize, CV_8UC3, img_data);
    ctx->subsense = new BackgroundSubtractorSuBSENSE(lbsp_thresh,
                                                     desc_dist_thresh_offset,
                                                     min_color_dist_thresh,
                                                     num_bg_samples,
                                                     num_req_bg_samples,
                                                     num_samples_for_moving_avg);
    ctx->subsense->initialize(img, cv::Mat());
    return ctx;
}

void ss_apply(SSContext* ctx, void* img_data, void* output)
{
    cv::Mat input_img(ctx->imgSize, CV_8UC3, img_data);
    cv::Mat output_img(ctx->imgSize, CV_8UC1, output);
    ctx->subsense->apply(input_img, output_img);
}

void ss_destroy(SSContext* ctx)
{
    delete ctx;
}
