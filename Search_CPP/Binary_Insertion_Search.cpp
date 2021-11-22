#include <iostream>
using namespace std;
//BinarySearch Đọc chú thích tại file BinarySearch.cpp
int BinarySearch(int *array, int left, int right, int lookfor) 
{
    int mid;
    if (right<=left) 
        return lookfor>array[left] ? left+1 : left;
    mid = (left+right)/2;
    if(array[mid]==lookfor) 
        return mid+1;
    if(lookfor > array[mid]) 
        return BinarySearch(array,mid+1,right,lookfor);
    return BinarySearch(array,left,mid-1,lookfor);

} 
// sắp xếp nhị phân của mảng a có số phần tử n
void BinaryInsertionSort(int a[],int n){    
    int i, j, k, x;
    for (i = 1; i < n; ++i) {
        j = i - 1;
        x = a[i]; 
        k = BinarySearch(a, 0, j, x);  // tìm vị trí cần đặt của giá trị   
        while(j >= k){ // mỗi khi vị trí cuối >= vị trí cần đặt thì thực hiện
            a[j+1] = a[j]; // gán giá trị trước = giá trị sau
            j--; // giảm dần để tìm chính xác từ cuối lên đầu 1 cách chính xác
        }         
        a[k] = x; // gán giá trị cần đặt vào vị trí vừa tìm được
    }    
}

int main(){
    int n = 6;
    int a[] = { 3,   1,  2,  4,  5,  4   };
    BinaryInsertionSort(a,n);
    for (int  j = 0 ; j<n  ;  j++)
        cout<<a[j]<<" ";
    return 0;

}

