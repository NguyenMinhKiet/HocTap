#include <iostream>
using namespace std;
//Dinh Nghia MAX 
#define MAX(x1, x2) (((x1) > (x2)) ? (x1) : (x2)) 

int max(int *arr, int n);

int main()
{
  int arr[] = {21,78,97,53,10};
  int a = max(arr, 5);
  cout <<a<<endl;
  return 0;
}


int max(int *arr, int n)
{
  if (n == 2)
  {
    return MAX(arr[0], arr[1]);
  }

  return MAX(arr[n - 1], max(arr, n - 1));
}
//So sanh vi tri cuoi trong mang v� goi lai max tai vi tri do cho toi khi n=2