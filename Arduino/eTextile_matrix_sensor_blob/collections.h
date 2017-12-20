/* This file is part of the OpenMV project.
   Copyright (c) 2013-2017 Ibrahim Abdelkader <iabdalkader@openmv.io> & Kwabena W. Agyeman <kwagyeman@openmv.io>
   This work is licensed under the MIT license, see the file LICENSE for details.
*/

#ifndef __COLLECTIONS_H__
#define __COLLECTIONS_H__

#define IM_LOG2_2(x)    (((x) &                0x2ULL) ? ( 2                        ) :             1) // NO ({ ... }) !
#define IM_LOG2_4(x)    (((x) &                0xCULL) ? ( 2 +  IM_LOG2_2((x) >>  2)) :  IM_LOG2_2(x)) // NO ({ ... }) !
#define IM_LOG2_8(x)    (((x) &               0xF0ULL) ? ( 4 +  IM_LOG2_4((x) >>  4)) :  IM_LOG2_4(x)) // NO ({ ... }) !
#define IM_LOG2_16(x)   (((x) &             0xFF00ULL) ? ( 8 +  IM_LOG2_8((x) >>  8)) :  IM_LOG2_8(x)) // NO ({ ... }) !
#define IM_LOG2_32(x)   (((x) &         0xFFFF0000ULL) ? (16 + IM_LOG2_16((x) >> 16)) : IM_LOG2_16(x)) // NO ({ ... }) !
#define IM_LOG2(x)      (((x) & 0xFFFFFFFF00000000ULL) ? (32 + IM_LOG2_32((x) >> 32)) : IM_LOG2_32(x)) // NO ({ ... }) !

#define CHAR_BITS (sizeof(char) * 8)
#define CHAR_MASK (CHAR_BITS - 1)
#define CHAR_SHIFT IM_LOG2(CHAR_MASK)


#define FRAME_ROW_PTR(imagePtr, y) \
  ({ \
    __typeof__ (imagePtr) _imagePtr = (imagePtr); \
    __typeof__ (y) _y = (y); \
    ((uint8_t*)_imagePtr->dataPtr) + (_imagePtr->w * _y); \
  })

#define GET_FRAME_PIXEL(rowPtr, x) \
  ({ \
    __typeof__ (rowPtr) _rowPtr = (rowPtr); \
    __typeof__ (x) _x = (x); \
    _rowPtr[_x]; \
  })

#define BITMAP_ROW_INDEX(imagePtr, y) \
  ({ \
    __typeof__ (imagePtr) _imagePtr = (imagePtr); \
    __typeof__ (y) _y = (y); \
    _imagePtr->w * _y; \
  })

#define BITMAP_INDEX(rowIndex, x) \
  ({ \
    __typeof__ (rowIndex) _rowIndex = (rowIndex); \
    __typeof__ (x) _x = (x); \
    _rowIndex + _x; \
  })

#define PIXEL_THRESHOLD(pixel, pThreshold) \
  ({ \
    __typeof__ (pixel) _pixel = (pixel); \
    __typeof__ (pThreshold) _pThreshold = (pThreshold); \
    _pThreshold <= _pixel; \
  })

#define IM_MAX(a,b) \
  ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; \
  })

#define IM_MIN(a,b) \
  ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; \
  })
////////////// Lifo //////////////

typedef struct lifo {
  size_t len;      // Number of elements
  size_t data_len; // Size of an element
  size_t index;    //
  char* data;
} lifo_t;

void lifo_alloc_all(lifo_t* ptr, size_t* siZe, size_t data_len);
void lifo_free(lifo_t* ptr);

size_t lifo_size(lifo_t *ptr);

void lifo_enqueue(lifo_t *ptr, void* data);
void lifo_dequeue(lifo_t *ptr, void* data);

////////////// Image stuff //////////////

typedef struct image {
  int w;
  int h;
  uint8_t* dataPtr;
} image_t;

////////////// Bitmap //////////////

typedef struct {
  size_t siZe;
  char* data;
} bitmap_t;

void bitmap_bit_set(char* arrayPtr, int index);
char bitmap_bit_get(char* arrayPtr, int index);
void bitmap_clear(char* arrayPtr);
void bitmap_print(char* arrayPtr);

typedef struct xylf {
  int16_t x, y, l, r;
} xylf_t;

////////////// Blob //////////////

typedef struct point {
  uint16_t x;
  uint16_t y;
  uint16_t z;
} point_t;

typedef struct blob {
  int8_t UID; // if no ID set UID = -1
  point_t centroid;
  uint32_t pixels;
  boolean isDead;
  struct blob* next_ptr;
} blob_t;

typedef struct list {
  blob_t* head_ptr;
  blob_t* tail_ptr;
  int8_t index;
} list_t;

////////////// list //////////////

void list_init(list_t* ptr);
void list_alloc_all(list_t* dst, blob_t* blobs);
void list_push_back(list_t* dst, blob_t* blob);
void list_save_blobs(list_t* dst, list_t* src);
void list_copy_blob(blob_t* blobA, blob_t* blobB, size_t blobSize);
void list_clear_blobs(list_t* src);

blob_t* list_pop_front(list_t* src);
blob_t* list_read_blob(list_t* src, uint8_t index);
blob_t* list_get_blob(list_t* src, uint8_t index);

void find_blobs(
  image_t* input_ptr,
  char* bitmap_ptr,
  const int rows,
  const int cols,
  const int pixelThreshold,
  const unsigned int minBlobPix,
  const unsigned int maxBlobPix,
  list_t* freeBlobList_ptr,
  list_t* blobs_ptr,
  list_t* oldBlobsToUpdate_ptr,
  list_t* blobsToUpdate_ptr,
  list_t* blobsToAdd_ptr,
  list_t* outputBlobs_ptr
);

////////////// Iterators //////////////
int8_t list_size(list_t* ptr);
blob_t* iterator_start_from_head(list_t* src);
blob_t* iterator_next(blob_t* src);

#endif /*__COLLECTIONS_H__*/
