//Cấu trúc rẽ nhánh
#include <iostream>
using namespace std;
int main(){
    int n;
    do{
          cout<<"Nhap lua chon 2->4: ";
          cin>>n;
    }
    while(n<2 || n>4);
    //Lựa chọn
    switch(n){
        case 2:{
            cout<<"Hai";
            break;
        }
        case 3:{
            cout<<"Ba";
            break;
        }
        case 4:{
            cout<<"Bon";
            break;       
         }
    }
    return 0;
}