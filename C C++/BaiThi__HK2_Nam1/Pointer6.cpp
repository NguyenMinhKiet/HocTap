#include <iostream>
using namespace std;
void max(int *arr, int n)
{
    int ln=0;
    int dem=0;
    
    for (int i = 0; i<n ; i++)
    {             
        if ( arr[i] > ln )
        {
            ln = arr[i];                          
        }             
    }
    for (int j = 0; j<n ; j++)
    {
        if (arr[j] == ln)
        dem++;
    }
    cout<<"So lon nhat cua day: "<<ln<<endl;
    cout<<"Co "<<dem<<" so = "<<ln;
}
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
    max(arr,n);
    return 0;
}