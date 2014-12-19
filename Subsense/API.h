//
//  API.h
//  Subsense
//
//  Created by Saumitro Dasgupta on 12/18/14.
//  Copyright (c) 2014 Saumitro Dasgupta. All rights reserved.
//

#ifndef __Subsense__API__
#define __Subsense__API__

#ifdef __cplusplus
extern "C"
{
#endif
    
struct SSContext;
    
extern SSContext* ss_create(void* img_data, int width, int height);

extern void ss_apply(SSContext* ctx, void* img_data, void* output);

extern void ss_destroy(SSContext* ctx);
    
#ifdef __cplusplus
}
#endif

#endif /* defined(__Subsense__API__) */
