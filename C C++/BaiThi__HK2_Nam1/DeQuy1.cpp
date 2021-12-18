#include <iostream>
using namespace std;
float Dequy(int n);

int main ()
{
	int n;
	cout<<"Nhap n = ";
	cin>>n;
	cout<<"s= "<<Dequy(n)<<endl;

	return 0;
}
float Dequy(int n)
{	
	if (n == 1)
	 {return 1;}

 	return ((float)1/n)+Dequy(n-1);
}
