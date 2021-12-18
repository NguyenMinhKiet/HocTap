#include <iostream>

using namespace std;

int main() 
{

    int i = 1;
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int arr[n];
    arr[0] = 0;
    int kq = 0;
    while (i <= n) 
	{
        if (i < 3) 
		{
            kq =  1;
        } 
		else 
		{
            kq = arr[i-1] + (i-1)*arr[i-2];
        }

        arr[i] = kq; 
        i++; 
    }
  
    cout << " x[" << n << "] = " << kq << '\n'; // chinh la ket qua
    return 0;
}
//luu mang tu 0 toi n -> kq 