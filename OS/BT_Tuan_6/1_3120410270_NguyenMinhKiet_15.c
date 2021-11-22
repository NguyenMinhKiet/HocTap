#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

//ham chuyen ky tu thanh so nguyen
int CharToInt(char num){
	return (int)num - 48;
}

int main(int argc,char* argv[]){
	if (argc!=2){
		printf("Nhap 1 tham so");
		return 1;
	}
	if (strlen(argv[1]) < 20){
		printf("Nhap Tham so duong >= 20 chu so");
		return 2;
	}

	//khai bao bien n = do dai cua tham so argv[1]
	int n = strlen(argv[1]);
	char str[n];
	//Copy argv[1] sang str
	strcpy(str,argv[1]);
	if(str[0] == '-'){
		printf("Nhap tham so duong");
		return 3;
	}
	pid_t pid;
	pid = fork();

	// Child Process
	if(pid==0){
		FILE* fo = fopen ("/home/sv/Code/Tuan06/out1.txt","wt");
		//chay tu cuoi ve truoc -> tim duoc so dao nguoc
		for(int i=n-1;i>=0;i--)			
			fprintf(fo,"%c",str[i]);
		fclose(fo);
	}

	// Parent Process
	if(pid>0){
		char a[n];
		int b[n];
		int sum = 0;
		int status;
		int waitnum = wait(&status);
		printf("Parent process. waiting num = %d, status = %d\n",waitnum,status);
		FILE* fi = fopen ("/home/sv/Code/Tuan06/out1.txt","rt");
		if (!fi){
			printf("Khong ton tai file");
			return 4;
		}
		int i = -1;
		while(fscanf(fi,"%c",&a[++i]) != EOF);
		for (int i = 0;i<n;i++)
			sum += CharToInt(a[i]); // chuyen char thanh int = ASCII 
		printf("Tong = %d\n",sum);
		fclose(fi);
		return 0;
	}
}
