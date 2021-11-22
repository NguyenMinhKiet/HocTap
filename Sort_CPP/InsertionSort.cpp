#include <iostream>
using namespace std;
void InsertionSort(int *a,int n);


int main(){
    int n,x;
    int *a = new int [n];
    cout<<"Nhap n: ";cin>>n;
    for (int i=0; i<n ; i++)
        cin>>a[i];
    InsertionSort(a,n);
    for (int i=0; i<n ; i++)
        cout<<a[i]<<" ";
    
    return 0;
}

void InsertionSort(int *a,int n){
    int x,j;
    for (int i=1;i<n;i++){
        x = a[i];
        j = i-1;
        while ( x < a[j] && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }

}
