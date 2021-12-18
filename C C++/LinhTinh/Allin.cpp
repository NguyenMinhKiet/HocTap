#include <iostream>
#include <fstream>

using namespace std;

struct array
{
    int n;
    int *a;
};

array readfromfile(string filelocation, char kind);
void outPutArray(array p);
array writetofile(string filelocation, char kind);


int main()
{	
    array fi = readfromfile("D:\\HocTap\\Data Structures and Algorithms\\dockhongso",1); 
    outPutArray(fi);
    
    if (fi.a) delete[] fi.a;
    return 0;
}



array readfromfile(string filelocation,char kind)
{
    array p;
    p.a = NULL;
   

    ifstream fileinput(filelocation);
    if (fileinput.fail())
    {
        cout<<"Fail to open this file";
        return p;
    }   
    else 
        cout<<"File is opened\n";   
   p.n = 0;  
   int j ;
   while (fileinput>> j)
    {     
        
          p.n++;         
    }
    cout<<"p.n = "<<p.n<<"\n";
    p.a = new int[p.n];
    if (!p.a)
    {
        cout<<"not enough memory";
        fileinput.close();
        return p;
    }
    fileinput.close();
    fileinput.open(filelocation);
    //Cần chuyển con trỏ về đầu file
    int k;
    p.n=0;
    while (fileinput>>k)
    {        
     
       p.a[p.n++] = k;
       
    }
    fileinput.close();
   return p;


}

    void outPutArray(array p)
{   
    for(int i = 0; i < p.n ; i++)
    {
        cout<<"a["<<i<<"] = "<<p.a[i]<<endl;
    }
}






