#include <iostream>
#include <math.h>
#include <algorithm> //su dung ham swap
using namespace std;

float trungbinhcong( int Arr[], int n);
bool ktsonguyento( int Arr[], int n);
int dsnt(int a[],int n);
bool ktsochinhphuong(int Arr[], int n);
int dscp(int a[],int n);
bool ktsohoanchinh(int Arr[],int n);
int dshc(int a[],int n);
int demcapsobangm(int Arr[],int n);
void sapxeptangdan(int a[],int n);
void readfromfile(FILE *p,int *&Arr,int &n);

int main()
{	
	FILE *fi = fopen("D:\\baitap\\NUM.INP.txt", "rt");
	if (fi == NULL)
	{
		cout << "khong mo dc file";
		return 0;
	}
	int n; 
	int *A;
	readfromfile(fi, A, n);
	int demsonguyento=dsnt(A,n);			
	int demsohoanchinh=dshc(A,n);
	int demsochinhphuong=dscp(A,n);
	int capsobangm=demcapsobangm(A,n);
	float trungbinh=trungbinhcong(A,n);
	cout<<"Da luu vao file";
	FILE* fo = fopen ("D:\\baitap\\NUM.OUT.txt","w+t");
	fprintf(fo,"Bai 14: %.1f\n",trungbinh); //%.1f lam tron so thap phan
	fprintf(fo,"Bai 15: %d %d %d\n",demsonguyento,demsochinhphuong,demsohoanchinh);
	fprintf(fo,"Bai 16: %d\n",capsobangm);
	fprintf(fo,"Bai 18: ");
	sapxeptangdan(A,n);
	for(int i=1;i<n+1;i++)
	{
			fprintf(fo,"%d ",A[i]);
	}		
	fclose(fi);
	fclose(fo);
	delete[] A;
	return 0;
}

bool ktsohoanchinh(int n)
{
	int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) return true; 
    return false;
}
int dshc(int a[],int n)
{
	int d=0;
	for (int i=1;i<n+1;i++)
	{
		if (ktsohoanchinh(a[i]))
		d++;
	}
	return d;
}
bool ktsochinhphuong(int n) 
{
	if (n>3)
	{
		if (n == int(sqrt(double(n)))*int(sqrt(double(n))))
			return true;                              
	}
	return false;	
}
int dscp(int a[],int n)
{
	int d=0;
	for (int i=1;i<n+1;i++)
	{
		if (ktsochinhphuong(a[i]))
		d++;
	}
	return d;
}
bool ktsonguyento(int n)
{
	if (n<2)
	{
		return false;
	}
	for (int i=2;i<= sqrt(n);i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int dsnt(int a[],int n)
{
	int d=0;
	for (int i=1;i<n+1;i++)
	{
		if (ktsonguyento(a[i]))
		d++;
	}
	return d;
}
float  trungbinhcong( int Arr[], int n)
{
	int sum=0;
	for(int i=1;i<n+1;i++)
	{ 
		sum+= Arr[i];
		
	}
	return ((float)sum/n);
	
}        
void readfromfile(FILE *p , int *&Arr, int &n)
{

	fscanf(p, "%d", &n);
	Arr = new int[n]; 
	for (int i = 0; i <= n; i++)
	fscanf(p, "%d", &Arr[i]);

}
int demcapsobangm(int Arr[],int n)
{
	int d=0;
	for(int i=1;i<n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{	
			if (Arr[i]+Arr[j] == Arr[0])
			{
				d++;
			}			
										
		}
	
	}
	return d;
}
void sapxeptangdan(int a[],int n)
{
	

    for(int i = 1; i < n  ; i++)
	{
        for(int j = i + 1; j < n + 1   ; j++)
		{ 
            if(a[i] > a[j])
			{
               swap(a[i],a[j]);       
            }
        }
    }
   
}


