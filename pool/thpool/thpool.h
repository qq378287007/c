#ifndef THPOOL_H
#define THPOOL_H

#include <stdint.h>

#include "c_list.h"
#include "m_vector.h"

#ifdef WIN32
#include "lib/pthread.h"
#else
#include <pthread.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef void *(*task_func)(void *);

    typedef struct
    {
        void *(*fn)(void *);
        void *arg;
    } Task;

    typedef struct
    {
        pthread_t _thread;
        int _busy;
        YC_List *_task;
        pthread_mutex_t _lock;
    } mthread;

    typedef struct
    {
        // 线程列表
        LineTable *_threads;
        // 任务队列
        YC_List *_tasks;

        pthread_mutex_t _lock;
    } thPool;

    thPool *thpool_create(int num);
    void add_Task(thPool *pool, Task *task);
    void thpool_release(thPool *pool);

#ifdef __cplusplus
}
#endif

#endif // THPOOL_H