/*
   This file is part of the OpenMV project.
   Copyright (c) 2013-2016 Kwabena W. Agyeman <kwagyeman@openmv.io>
   This work is licensed under the MIT license, see the file LICENSE for details.

   Interface for using extra frame buffer RAM as a stack.

*/
#ifndef __FB_ALLOC_H__
#define __FB_ALLOC_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *fb_alloc(uint32_t size); // FIXME
void *fb_alloc0(uint32_t size); // FIXME
void *fb_alloc_all(uint32_t *size); // returns pointer and sets size
void fb_free();
void fb_alloc_fail();

#endif /* __FF_ALLOC_H__ */
