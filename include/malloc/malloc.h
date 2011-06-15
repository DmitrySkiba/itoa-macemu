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

#ifndef _MALLOC_ZONE_INCLUDED_
#define _MALLOC_ZONE_INCLUDED_

#include <stddef.h>
#include <sys/cdefs.h>

__BEGIN_DECLS


typedef struct _malloc_zone_t {
    /* TODO */
} malloc_zone_t;

malloc_zone_t* malloc_default_zone(void);

malloc_zone_t* malloc_create_zone(size_t start_size,unsigned int flags);
void malloc_destroy_zone(malloc_zone_t* zone);

void* malloc_zone_malloc(malloc_zone_t* zone,size_t size);
void* malloc_zone_calloc(malloc_zone_t* zone,size_t num,size_t size);
void* malloc_zone_valloc(malloc_zone_t* zone,size_t size);
void* malloc_zone_realloc(malloc_zone_t* zone,void* ptr,size_t size);
void* malloc_zone_memalign(malloc_zone_t* zone,size_t align,size_t size);
void malloc_zone_free(malloc_zone_t* zone,void* ptr);

malloc_zone_t* malloc_zone_from_ptr(const void *ptr);

void malloc_set_zone_name(malloc_zone_t* zone,const char* name);
const char* malloc_get_zone_name(malloc_zone_t* zone);

size_t malloc_size(const void* ptr);
size_t malloc_good_size(size_t size);


__END_DECLS

#endif /* _MALLOC_ZONE_INCLUDED_ */
