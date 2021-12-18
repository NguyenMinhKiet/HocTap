#include <iostream>
using namespace std;
void vitrixoa(int *arr, int n, int k);


int main()
{
    int n;
    cout<<"Nhap n = ";
    cin>>n;
    //khai bao so phan tu arr
    int *arr = new int [n];
    for (int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    int k;
    do
    {
        cout<<"Nhap vi tri can xoa tu 0 -> "<<n-1<<" : ";
        cin>>k;
    }
    while ( k > n-1);
    vitrixoa(arr,n,k);
    return 0;
}

void vitrixoa(int *arr, int n, int k)
{
    for (int i = k; i<n ; i++)
    {
        arr[i]=arr[i+1];
        
    }
    cout<<"Mang sau khi xoa: ";
    for (int j = 0; j<n-1 ; j++)
    {
        cout<<arr[j]<<" ";
    }
    
}