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

#ifndef FUTEXLOCK_INCLUDED_
#define FUTEXLOCK_INCLUDED_

#include <sys/cdefs.h>

/////////////////////////////////////////////////////////// c interface

__BEGIN_DECLS

typedef volatile int futexlock_t;

#define FUTEXLOCK_INITIALIZER 0

void futexlock_lock(futexlock_t* lock);
void futexlock_unlock(futexlock_t* lock);

// returns nonzero on success
int futexlock_trylock(futexlock_t* lock);

__END_DECLS

/////////////////////////////////////////////////////////// cpp helper

#ifdef __cplusplus

class auto_futexlock {
public:
    auto_futexlock(futexlock_t* lock):
        m_lock(lock)
    {
        if (m_lock) {
            futexlock_lock(m_lock);
        }
    }
    ~auto_futexlock() {
        unlock();
    }
    void unlock() {
        if (m_lock) {
            futexlock_unlock(m_lock);
            m_lock=0;
        }
    }
private:
    auto_futexlock(const auto_futexlock&);
    auto_futexlock& operator=(const auto_futexlock&);
private:
    futexlock_t* m_lock;    
};

#endif // __cplusplus

///////////////////////////////////////////////////////////

#endif // FUTEXLOCK_INCLUDED_

