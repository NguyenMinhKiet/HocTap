#include <iostream>
using namespace std;
void nhapmang(int **arr, int m, int n);
int tong(int **arr,int m,int n);

int main()
{
    int n,m;
    cout<<"Nhap m = ";
    cin>>m;
    cout<<"Nhap n = ";
    cin>>n;
    //khai bao so dong
    int **arr = new int *[m];
    for (int i = 0; i < n; i++)
    //khai bao so cot                                                                                                                                                                                                 
		arr[i] = new int[n];

    nhapmang(arr,m,n);
    cout<<"kq = "<<tong(arr,m,n);
    return 0;
}
void nhapmang(int **arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "phan tu thu a[" << i << "][" << j << "]" << endl;
			cin >> arr[i][j];
		}
	}
}
int tong(int **arr,int m,int n)
{
    int sum = 0;
    for (int i = 0 ; i<m ; i++)
    {
        for (int j = 0 ; j<n ; j++)
        {
            sum = sum + arr[i][j];
        }
    }
    return sum;
}