#include <iostream>
using namespace std;
int x(int n);


int main()
{
	int n=5;
	cout<<"x["<<n<<"] = "<<x(n)<<endl;
	return 0;
}

int x(int n)
{	
	while (n == 1 || n == 2)
	{
		return 1;
	}
	return x(n-1) + (n-1)*x(n-2);
}