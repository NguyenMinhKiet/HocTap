#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
//kiem tra so
int isPNumber(char* input){
	for(int i=0;i<strlen(input);i++){
		if(input[0] == '-')
			return 3;		
		if(isdigit(input[i]) == 0)	
			return 4;
	}		
	return 0;
}

void* thread1 (void* arg){
	int *tmp = (int *) arg;
	int fact = 1;
	for (int i=2;i<=(*tmp);i++){
		fact = fact * i;
	}
	*tmp = fact; // cap nhat gia tri con tro tmp 
	printf("Thread 1 factorial: %d\n",*tmp);
}


void* thread2 (void* arg){
	int *tmp = (int *) arg;
	int sum=0;
	sum = *tmp*(*tmp+1)/2;
	printf("Thread 2 sum: %d\n",sum);
}

int main (int argc,char* argv[]){
	//kiem tra tham so
	if (argc!=2){
		printf("Nhap 1 tham so\n");
		return 1;
	}
	if (isPNumber(argv[1]) != 0){
		printf("Nhap tham so la 1 so nguyen duong\n");
		return 2;
	}

	
	pthread_t tid1,tid2;
	int n = atoi(argv[1]);
	printf("Begin\n");
	pthread_create(&tid1,NULL,thread1,&n);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,NULL,thread2,&n);
	pthread_join(tid2,NULL);
	printf("End\n");
}