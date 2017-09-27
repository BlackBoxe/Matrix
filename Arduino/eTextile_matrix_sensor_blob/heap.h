#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdint.h>
#include <stddef.h>

#define HEAP_INIT_SIZE 0x10000
#define HEAP_MAX_SIZE 0xF0000
#define HEAP_MIN_SIZE 0x10000

#define MIN_ALLOC_SZ 4

#define MIN_WILDERNESS 0x2000
#define MAX_WILDERNESS 0x1000000

#define BIN_COUNT 9
#define BIN_MAX_IDX (BIN_COUNT - 1)

typedef unsigned int uint;
// typedef uint16_t uint;

typedef struct node_t {
  uint hole;
  uint size;
  struct node_t *next;
  struct node_t *prev;
} node_t;

typedef struct footer {
  node_t *header;
} footer_t;

typedef struct bin {
  node_t *head;
} bin_t;

typedef struct heap {
  uint start;
  uint end;
  bin_t *bins[BIN_COUNT];
} heap_t;

// static uint overhead = sizeof(footer_t) + sizeof(node_t);
#define OVERHEAD ((uint)(sizeof(footer_t) + sizeof(node_t)))

void init_heap(heap_t *heap, uint start);
void *heap_alloc(heap_t *heap, size_t size);
void heap_free(heap_t *heap, void *p);
uint expand(heap_t *heap, size_t sz);
void contract(heap_t *heap, size_t sz);
uint get_bin_index(size_t sz);
void create_foot(node_t *head);
footer_t *get_foot(node_t *head);
node_t *get_wilderness(heap_t *heap);

#endif // __HEAP_H__

