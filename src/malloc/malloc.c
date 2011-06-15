/*
 * Copyright (C) 2011 Dmitry Skiba
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <malloc/malloc.h>
#include <malloc.h>

static malloc_zone_t default_zone;

malloc_zone_t* malloc_default_zone(void) {
    return &default_zone;
}

malloc_zone_t* malloc_create_zone(size_t start_size,unsigned int flags) {
    return malloc_default_zone();
}

void malloc_destroy_zone(malloc_zone_t* zone) {
    /*noop*/
}

void* malloc_zone_malloc(malloc_zone_t* zone,size_t size) {
    return malloc(size);
}

void* malloc_zone_calloc(malloc_zone_t* zone,size_t num,size_t size) {
    return calloc(num,size);
}

void* malloc_zone_valloc(malloc_zone_t* zone,size_t size) {
    return valloc(size);
}

void* malloc_zone_realloc(malloc_zone_t* zone,void* ptr,size_t size) {
    return realloc(ptr,size);
}

void* malloc_zone_memalign(malloc_zone_t* zone,size_t align,size_t size) {
    return memalign(align,size);
}

void malloc_zone_free(malloc_zone_t* zone,void* ptr) {
    free(ptr);
}

malloc_zone_t* malloc_zone_from_ptr(const void *ptr) {
    return malloc_default_zone();
}

void malloc_set_zone_name(malloc_zone_t* zone,const char* name) {
    /*noop*/
}

const char* malloc_get_zone_name(malloc_zone_t* zone) {
    return "fake zone";
}

size_t malloc_size(const void* ptr) {
     extern size_t dlmalloc_usable_size(void*);
     return dlmalloc_usable_size((void*)ptr);
}

size_t malloc_good_size(size_t size) {
    return size;
}
