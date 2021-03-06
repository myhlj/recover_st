#include <stdio.h>
//解决空转问题
#include <pthread.h>

#define max 10000
pthread_mutex_t the_mutex;//互斥量
pthread_cond_t condc,condp;//条件变量
int buffer=0;

void *producer(void* ptr)
{
	int i;
	for(i=1;i<=max;i++)
	{
		pthread_mutex_lock(&the_mutex);//获得一个锁
		while(buffer != 0)
		{
			pthread_cond_wait(&condp,&the_mutex);//阻塞以等待一个信号,阻塞生产者线程
		}
		buffer = i;
		printf("producer:%d\n",buffer);
		pthread_cond_signal(&condc);//唤醒消费者线程
		pthread_mutex_unlock(&the_mutex);//释放互斥量
	}
	pthread_exit(0);
}


void* consumer(void* ptr)
{
	int i;
	for(i=1;i<=max;i++)
	{
		pthread_mutex_lock(&the_mutex);//获得一个锁或者阻塞
		while(buffer==0)
		{
			pthread_cond_wait(&condc,&the_mutex);//阻塞以等待一个信号,阻塞消费者线程
		}

		buffer = 0;
		printf("consumer:%d\n",buffer);
		pthread_cond_signal(&condp);//向另一个线程发信号唤醒线程,唤醒生产者线程
		pthread_mutex_unlock(&the_mutex);//释放互斥量
	}

	pthread_exit(0);
}

int main(int argc,char** argv)
{
	pthread_t pro,con;
	pthread_mutex_init(&the_mutex,0);//创建一个互斥量
	pthread_cond_init(&condc,0);//创建一个条件变量
	pthread_cond_init(&condp,0);//创建一个条件变量
	pthread_create(&con,0,consumer,0);//创建线程
	pthread_create(&pro,0,producer,0);//创建线程
	pthread_join(pro,0);//等待一个特定的线程结束
	pthread_join(con,0);
	pthread_cond_destroy(&condc);//撤销条件变量
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);//撤销互斥量
	return 0;
}
