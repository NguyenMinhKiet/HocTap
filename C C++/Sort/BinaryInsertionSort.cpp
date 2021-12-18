#include <iostream>
using namespace std;
 

// int binarySearch(int a[], int item,
//                 int low, int high)
// {
//     if (high <= low)
//         return (item > a[low]) ?
//                 (low + 1) : low;
 
//     int mid = (low + high) / 2;
 
//     if (item == a[mid])
//         return mid + 1;
 
//     if (item > a[mid])
//         return binarySearch(a, item,
//                             mid + 1, high);
//     return binarySearch(a, item, low,
//                         mid - 1);
// }
int Bsearch(int array[], int lookfor, int left, int right) 
{
    if (right<=left) 
        return lookfor>array[left] ? (left+1) : left;
    int mid = (left+right)/2;
    if(array[mid]==lookfor) 
        return mid+1;
    if(lookfor > array[mid]) 
        return Bsearch(array,lookfor,mid+1,right);
    return Bsearch(array,lookfor,left,mid-1);

}
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inseretd
        loc = Bsearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;       
        }
        a[loc] = selected;
    }
}
 
// Driver Code
int main()
{
    int a[]  = { 3,1,2,4,5,4 };
    int n = sizeof(a) / sizeof(a[0]), i;
    
    insertionSort(a, n);
 
   cout <<"Sorted array: \n";
  for (i = 0; i < n; i++)
       cout << a[i]<<" ";
 
    return 0;
}