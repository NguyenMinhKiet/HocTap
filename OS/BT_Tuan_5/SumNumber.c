#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sum = 0, a;
    if (argc != 2){
        printf("Nhap 1 so");
        return 1;
    }
    int n = atoi(argv[1]);
     while (n>0){
         a = n%10;
         sum+=a;
         n/=10;
    }
   printf("Tong cac chu so cua %s = %d",argv[1],sum);
   return 0;
}
//đếm từng số
// int getSumChar(const char *str){
//     int sum = 0;
//     int n = strlen(str);
//     for (int i = 0; i < n;i++){
//         sum += (int)str[i] - 48; // -48 - cho mã ASII
//     }
//     return sum;
// }