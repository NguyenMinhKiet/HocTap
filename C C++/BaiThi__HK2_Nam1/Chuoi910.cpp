#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int demsotu(char *s);
int soluongkytumoitu(char *s);
                                                                                                                                                                                                                                                                                                                                                                                                     


int main()
{
	char s[100];
    cout<<"nhap chuoi: ";
    //nhap chuoi = ham gets
  	gets(s);

	cout<<"So tu trong chuoi la:"<<demsotu(s);
	cout<<"\nSo luong ky tu trong moi tu cua chuoi S: "<<soluongkytumoitu(s);
	return 0;
}




int demsotu(char *s)
{
	int dem=0;
	if(s[0]!=' ')
		dem=1;
	for( int i=1;i<strlen(s);i++)
	{
		if(s[i]==' ' && s[i+1]!=' ')
			dem++;
	}
	return dem;
}

int soluongkytumoitu(char *s)
{	
	int demkt=0;
	if (s[0] != ' ')
		demkt=1;
	for (int i=1;i<strlen(s);i++)
	{	//chay cho toi khi thay s[i]== ' ' thi bo qua tang them gia tri i		
		if (s[i] != ' ')
		{
			demkt++;
		}	
		while (s[i] == ' ')
		{	
			cout<<demkt<<" ";						
			demkt = 1;
			i++;
		}
	}
 	return demkt;
}

