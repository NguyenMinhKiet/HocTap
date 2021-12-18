#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct arr{
	int n; // so luong phan tu
	int *array; // luu cac phan tu
	int count;
	int *arrayprime;
	char *fileputpath;
	float avgsum;
};

void* funct1(void* argv){
	printf("Thread 1 : Begin\n");
	struct arr *tmp = (struct arr*) argv;
	int sum = 0;
	for(int i=0;i<tmp->n;i++){
		sum += tmp->array[i];
	}
	tmp->avgsum = sum*1.0/tmp->n;
	printf("Thread 1 : End\n");
}

void* funct2(void* argv){
	printf("Thread 2 : Begin\n");
	struct arr *tmp = (struct arr*) argv;
	int k;
	for(int i=0;i<tmp->n;i++)
		for(int j=i+1;j<tmp->n;j++)
			if(tmp->array[i] > tmp->array[j]){
				k = tmp->array[i];
				tmp->array[i] = tmp->array[j];
				tmp->array[j] = k;
			}
	printf("Thread 2 : End\n");
}

int isPrime(int number){
	if(number<2) return 1;
	for(int i=2;i<number/2;i++){
		if(number%i==0)
			return 1;
	}
	return 0;
}

void* funct3(void* argv){
	printf("Thread 3 : Begin\n");
	struct arr *tmp = (struct arr*) argv;
	int k=0;
	tmp->count = 0;
	for(int i=0;i<tmp->n;i++){
		if(isPrime(tmp->array[i]) == 0){
			tmp->arrayprime[k] = tmp->array[i];
			k++;
			tmp->count++;	
		}
	}
	printf("Thread 3 : End\n");
}

void* funct4(void* argv){
	printf("Thread 4 : Begin\n");
	struct arr *tmp = (struct arr *) argv;
	FILE* fo = fopen(tmp->fileputpath,"wt");
	fprintf(fo,"Trung binh cong: %.1f\n",tmp->avgsum);
	fprintf(fo,"Mang tang dan: ");
	for(int i=0;i<tmp->n;i++){
		fprintf(fo,"%d ",tmp->array[i]);
	}
	fprintf(fo,"\nSo nguyen to : ");
	for(int i=0;i<tmp->count;i++){
		fprintf(fo,"%d ",tmp->arrayprime[i]);
	}
	fprintf(fo,"\n");
	fclose(fo);
	printf("Thread 4 : End\n");
}

int main (int argc, char* argv[]){
	//kiem tra dau vao
	if (argc != 3){
		printf("Thieu Phan Tu\n");
		return 1;
	}
	FILE* fi = fopen (argv[1],"rt");
	if (!fi){
		printf("File %s khong ton tai\n",argv[1]);
		return 2;
	}

	printf("Main Thread Begin\n");
	int i = 0;
	struct arr a;
	int tmp,count = 0;

	//Dem so phan tu trong file de cap phat
	while(fscanf(fi,"%d",&tmp) != EOF){
		count++;
	}

	a.n = count;

	//cap phat bo nho cho struct
	a.array = (int *) malloc(a.n * sizeof(int));
	a.arrayprime = (int *) malloc(a.n/2 * sizeof(int));
	a.fileputpath = (char *) malloc(strlen(argv[1]) * sizeof(char));

	strcpy(a.fileputpath,argv[2]);

	printf("Mang da nhan = ");
	//di chuyen con tro file ve dau file 
	fseek(fi,0,SEEK_SET);
	while(fscanf(fi,"%d",&a.array[i])!=EOF){
		printf("%d ",a.array[i]);
		i++;
	}
	printf("\n");
	pthread_t thread1,thread2,thread3,thread4;
	pthread_create(&thread1,NULL,funct1,&a);
	pthread_create(&thread2,NULL,funct2,&a);
	pthread_create(&thread3,NULL,funct3,&a);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_create(&thread4,NULL,funct4,&a);
	pthread_join(thread4,NULL);
	printf("Main Thread End\n");
	fclose(fi);
	free(a.array);
	free(a.arrayprime);
	free(a.fileputpath);
	return 0;
}