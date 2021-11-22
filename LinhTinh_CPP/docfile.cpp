#include <iostream>
#include <fstream>
 
using namespace std;
 
struct array{
    int n;
    int *a;
};
 
 
array readFromFile(string fileInputPath, char kind);
void outPutArray(array p);
 
 
int main(){
    array t = readFromFile("D:\\HocTap\\Data Structures and Algorithms\\filecoso.INP", 1);
    if(t.n < 0 || !t.a){
        cout<<"Cannot read data from file!"<<endl;
        exit(0);
    }
    outPutArray(t);
    delete[] t.a;
    return 0;
}
 
array readFromFile(string fileInputPath, char kind){
    array p;
    p.n = -1;
    p.a = NULL;
    
    ifstream fileInput(fileInputPath);
    if(fileInput.fail()){
        cout<<"Failed to open this file!"<<endl;
        return p;
    } else{
        cout<<"File is opened!"<<endl;
    }
    int tmp;
    fileInput>>tmp;
    if(tmp <= 0){
        cout<<"\n Data is error!";
        fileInput.close();
        return p;
    }
    p.n = tmp;
    p.a = new int[tmp];
    if(!p.a){
        cout<<"Not enough memory!\n";
        fileInput.close();
        exit(0);
    }
    p.n = 0;
    while(!fileInput.eof()){
        fileInput>>tmp;
        p.a[p.n++] = tmp;
    }
    
    
    fileInput.close();
    return p;
   
}
 
void outPutArray(array p){
    for(int i = 0; i < p.n; i++){
        cout<<"a["<<i<<"] = "<<p.a[i]<<endl;
    }
}

