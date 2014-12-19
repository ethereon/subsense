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
    SSContext(void* img_data, int width, int height)
    {
        this->imgSize = cv::Size2i(width, height);
        cv::Mat img(imgSize, CV_8UC3, img_data);
        subsense.initialize(img, cv::Mat(this->imgSize,CV_8UC1,cv::Scalar_<uchar>(255)));
    }
    
    BackgroundSubtractorSuBSENSE subsense;
    cv::Size2i imgSize;
};

SSContext* ss_create(void* img_data, int width, int height)
{
    return new SSContext(img_data, width, height);
}

void ss_apply(SSContext* ctx, void* img_data, void* output)
{
    cv::Mat input_img(ctx->imgSize, CV_8UC3, img_data);
    cv::Mat output_img(ctx->imgSize, CV_8UC1, output);
    ctx->subsense(input_img, output_img);
}

void ss_destroy(SSContext* ctx)
{
    delete ctx;
}
