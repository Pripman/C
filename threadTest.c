#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void *thread_func(void *Params)
{
	int *p = (int *)Params;
	printf("Hello from thread: %d/%d\n", *p, *(p+1));
	return NULL;
}

int main(int argc, char *argv[])
{
	int n =atoi(argv[1]);
	int params[2];
	params[1] = n;
	int i = 1;
	while(i <= n){
		params[0] = i;
		pthread_t x_thread;
		pthread_create(&x_thread, NULL, thread_func, &params);
		pthread_join(x_thread, NULL);
		i++;
	}	

	return 0;
}
