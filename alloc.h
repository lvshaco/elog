#ifndef __alloc_h__
#define __alloc_h__

#ifdef USE_SHACO_MALLOC
#include <stdlib.h>
void *sh_malloc(size_t size);
void *sh_realloc(void *ptr, size_t size);
void *sh_calloc(size_t nmemb, size_t size);
void  sh_free(void *ptr);
#else
#include <stdlib.h>
#define sh_malloc   malloc
#define sh_realloc  realloc
#define sh_calloc   calloc
#define sh_free     free
#endif

#endif
