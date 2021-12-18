#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//kiem tra so
int isPNumber(char *input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[0] == '-')
			return 3;
		if (isdigit(input[i]) == 0)
			return 4;
	}
	return 0;
}
//kiem tra so nguyen to
int isPrime(int number)
{
	if (number < 2)
		return 1;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return 2;
	}
	return 0;
}
int n;
void *thread1(void *arg)
{

	printf("Thread 1 start : %ld\n", pthread_self());
	printf("thread 1 end : ");
	FILE *f = fopen("thread.txt", "a");
	for (int i = 2; i <= n; i++)
	{
		if (isPrime(i) == 0)
		{
			fprintf(f, "(Thread 1) : %d ", i);
			printf("%d ", i);
		}
	}
	fclose(f);
	printf("\n");
}

void *thread2(void *arg)
{
	printf("Thread 2 start : %ld\n", pthread_self());
	printf("thread 2 end : ");
	FILE *f = fopen("thread.txt", "a");
	for (int i = 0; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			fprintf(f, "(Thread 2) : %d ", i);
			printf("%d ", i);
		}
	}
	fclose(f);
	printf("\n");
}

int main(int argc, char *argv[])
{
	//kiem tra tham so
	if (argc != 2)
	{
		printf("Nhap 1 tham so\n");
		return 1;
	}
	if (isPNumber(argv[1]) != 0)
	{
		printf("Nhap tham so la 1 so nguyen duong\n");
		return 2;
	}

	// main thread
	pthread_t tid1, tid2;
	n = atoi(argv[1]);
	printf("Main thread: Begin\n");
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("Main thread: End\n");
}