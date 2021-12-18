#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void Sort(int a[],int n){
	int x,j;
	for(int i=1;i<n;i++){
		x = a[i];
		j = i-1;
		while(x<a[j] && j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}

int *a;
int *b;
int n;

void* funct1(void* argv){
	printf("Thread 1 : Begin\n");
	Sort(a,n/2);	
	printf("Thread 1 : End\n");
}

void* funct2(void* argv){
	printf("Thread 2 : Begin\n");
	Sort(b,n/2);
	printf("Thread 2 : End\n");
}

void* funct3(void* argv){
	printf("Thread 3 : Begin\n");
	FILE* fo = fopen("output.txt","wt");
	int i = 0, j = 0;
	//merge
	while(i<n/2 && j<n/2)
	{
		if(a[i]<b[j]){
			fprintf(fo,"%d ",a[i]);
			i++;
		}
		else{
			fprintf(fo,"%d ",b[j]);
			j++;
		}
	}
	//Neu a hoac b con gia tri -> ghi het vao file
	if(a != NULL){
		while(i<n/2){
			fprintf(fo,"%d ",a[i]);
			i++;
		}	
	}
	else if (b != NULL){
		while(j<n/2){
			fprintf(fo,"%d ",b[j]);
			j++;
		}	
	}
	fclose(fo);
	printf("Thread 3 : End\n");
}

int main(int argc, char* argv[]){
	//Kiem tra dau vao
	if (argc != 2){
		printf("Thieu Phan Tu");
		return 1;
	}
	FILE* fi = fopen (argv[1],"rt");
	if (!fi){
		printf("File khong ton tai");
		return 2;
	}

	int tmp,count = 0;
	//Dem so phan tu trong file de cap phat
	while(fscanf(fi,"%d",&tmp) != EOF){
		count++;
	}
	//Cap phat bo nho
	n = count;
	printf("n = %d\n",n);
	a = (int *) malloc(n/2 * sizeof(int));
	b = (int *) malloc(n/2 * sizeof(int));

	//chuyen con tro file ve dau file
	fseek(fi,0,SEEK_SET);
	printf("Main Thread : Begin\n");

	//doc du lieu vao mang a b
	for(int i=0;i<n/2;i++){
		fscanf(fi,"%d",&a[i]);
	}
	for(int j=0;j<n/2;j++){
		fscanf(fi,"%d",&b[j]);		
	}

	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,funct1,NULL);
	pthread_create(&thread2,NULL,funct2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_create(&thread3,NULL,funct3,NULL);
	pthread_join(thread3,NULL);
	printf("Main Thread : End\n");
	fclose(fi);
	free(a);
	free(b);
	return 0;
}