#include "pthread.h"

struct _w32thread
{
	void *(*fn)(void *);
	void *arg;
};

static DWORD WINAPI w32launcher(LPVOID arg)
{
	struct _w32thread *info = arg;
	info->fn(info->arg);
	free(info);
	return 0;
}

int pthread_create(pthread_t *t, pthread_attr_t *attr, void *(*fn)(void *), void *arg)
{
	struct _w32thread *info = calloc(1, sizeof(*info));
	if (!info)
		return -1;
	info->fn = fn;
	info->arg = arg;
	*t = CreateThread(NULL, 0, w32launcher, info, 0, NULL);
	if (*t == NULL)
		return -1;
	return 0;
}

int pthread_mutex_init(pthread_mutex_t *lock, void *unused)
{
	*lock = CreateMutex(NULL, FALSE, NULL);
	if (*lock == NULL)
		return -1;
	return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *lock)
{
	if (*lock)
	{
		CloseHandle(*lock);
		*lock = NULL;
	}
	return 0;
}

int pthread_mutex_lock(pthread_mutex_t *lock)
{
	if (WaitForSingleObject(*lock, INFINITE) != WAIT_OBJECT_0)
		return -1;
	return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *lock)
{
	if (!ReleaseMutex(*lock))
		return -1;
	return 0;
}

int pthread_join(pthread_t *t, void **ret)
{
	if (WaitForSingleObject(*t, INFINITE) != WAIT_OBJECT_0)
		return -1;
	CloseHandle(*t);
	return 0;
}

#if 1

#include <stdio.h>
void *thread_func(void *arg)
{
	printf("data: %d\n", *(int *)arg);
	return NULL;
}

int main()
{
	pthread_t t;
	int arg = 1;
	pthread_create(&t, NULL, thread_func, &arg);
	pthread_join(&t, NULL);
	return 0;
}

#endif