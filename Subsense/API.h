//
//  API.h
//  Subsense
//
//  Created by Saumitro Dasgupta on 12/18/14.
//  Copyright (c) 2014 Saumitro Dasgupta. All rights reserved.
//

#ifndef __Subsense__API__
#define __Subsense__API__

#include "BackgroundSubtractorSuBSENSE.h"

#ifdef __cplusplus
extern "C"
{
#endif
    
extern BackgroundSubtractorSuBSENSE* ss_create(void* img_data, int width, int height);

extern void ss_destroy(BackgroundSubtractorSuBSENSE* subsense);
    
#ifdef __cplusplus
}
#endif

#endif /* defined(__Subsense__API__) */
