#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <Windows.h>

    typedef HANDLE pthread_t;
    typedef HANDLE pthread_mutex_t;
    typedef int pthread_attr_t;

    int pthread_create(pthread_t *t, pthread_attr_t *attr, void *(*fn)(void *), void *arg);
    int pthread_mutex_init(pthread_mutex_t *lock, void *unused);
    int pthread_mutex_destroy(pthread_mutex_t *lock);
    int pthread_mutex_lock(pthread_mutex_t *lock);
    int pthread_mutex_unlock(pthread_mutex_t *lock);
    int pthread_join(pthread_t *t, void **ret);

#ifdef __cplusplus
}
#endif
