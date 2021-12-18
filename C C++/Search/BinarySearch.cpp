#include <iostream>
using namespace std;
// tìm dạng nhị phân (phải có thứ tự )


// Mô tả thuật toán:
// Chia đôi mảng và xét xem giá trị giữa có = giá trị cần tìm hay không nếu có -> xuất ra giá trị giữa (mid), 
// nếu không tiếp tục xét giá trị cần tìm nằm bên phải hay bên trái mảng 
// sau đó tiếp tục thực hiện chia bảng và tìm giá trị


// Dạng 1: tìm vị trí trong mảng có thứ tự.


int Bsearch(int array[], int quantity, int lookfor)
{
    int mid;
    int left = 0; //giá trị đầu
    int right = quantity-1 ; //giá trị cuối   
    while ( left <= right ) // nếu còn giá trị giữa thì thực hiện
    {   
        mid = (left+right)/2; 
        if (lookfor == array[mid]) // nếu giá trị cần tìm = giá trị tại vị trí mid -> trả ra kết quả
            return mid;                
        if (lookfor < array[mid]) // nếu giá trị cần tìm < giá trị tại vị trí mid -> cho giá trị cuối = giá trị tại vị trí mid - 1
            right = mid - 1;
        else
            left = mid + 1;       // nếu giá trị cần tìm > giá trị tại vị trí mid -> cho giá trị đầu = giá trị tại vị trí mid + 1          
    }   
    return -1; //nếu không tìm thấy trả về giá trị -1;
}
// Dạng 2: Đệ quy tìm vị trí cần đặt giá trị -> sử dụng kèm Binary Insertion Sort
int BinarySearch(int *array, int left, int right, int lookfor) 
{
    if (right<=left) // nếu không còn giá trị cuối thì thực hiện
        return lookfor>array[left] ? left+1 : left; // nếu giá trị cần tìm > giá trị đầu (Khi ko con giá trị nào tồn tại bên phải Giá trị đầu) -> trả ra vị trí cần đặt là giá trị đầu (left) + 1
    int mid = (left+right)/2;
    if(array[mid]==lookfor) // nếu giá trị giữa = giá trị cần tìm -> trả ra giá trị cần đặt là giá trị giữa (mid) + 1
        return mid+1;
    if(lookfor > array[mid]) // nếu giá trị cần tìm > giá trị giữa :
        return BinarySearch(array,mid+1,right,lookfor); // gọi lại hàm BinarySearch với giá trị đầu (left) là giá trị giữa (mid) + 1
    return BinarySearch(array,left,mid-1,lookfor); // gọi lại hàm BinarySearch với giá trị cuối (left) là giá trị giữa (mid) - 1

}

int main(){
    int quantity = 5;
    int array[] = {1,3,5,7,9};
    for (int i=0; i<quantity; i++)
        cout<<Bsearch(array,quantity,array[i]);
    return 0;   
}