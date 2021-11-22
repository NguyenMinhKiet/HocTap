#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>
//ham tinh thoi gian chay
float time_diff(struct timeval *start,struct timeval *end){
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int main(int argc,char* argv[]){
	struct timeval start;
	struct timeval end;
	if (argc!=2){
		printf("Nhap 1 tham so");
		return 1;
	}
	int tmp = atoi(argv[1]);
	if(tmp<0){
		printf("Nhap so duong");
		return 2;
	}
	pid_t pid;
	gettimeofday(&start,NULL);
	pid = fork();

	// Child Process
	int max = tmp;
	if(pid==0){
		while (tmp>0){
			if(tmp == 1){
				printf("%d. ",tmp);
				break;
			}
			if (tmp > max) max = tmp;
			if(tmp%2 == 0){		
				printf("%d, ",tmp);
				tmp = tmp/2;
			}
			else{
				printf("%d, ",tmp);
				tmp = 3*tmp+1;
			}
			
		}
		printf("Max = %d\n",max);
	}

	// Parent Process
	if(pid>0){
		int status;
		int waitnum = wait(&status);
		gettimeofday(&end,NULL);
		printf("Thoi gian hoan thanh: %f giay\n",time_diff(&start,&end));
		return 0;
	}
}