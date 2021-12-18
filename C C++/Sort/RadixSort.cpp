#include <iostream>
using namespace std;
// get value at location k of n
int Digit(int n, int k){
    int value = 1;
    for (int i = 0 ; i<k ; i++)
        value*=10;
    return (n / value) % 10;
}
// void RadixSort(int A[], int n, int k){
//     int B[10][10],BB[10], m,  jj = 0;
//     for (int t = 0 ; t < k ; t++){
//         for (int i = 0 ; i < n ; i++)
//             BB[i] = 0;
//         for (int j = 0 ; j < k ; j++){
//             for (int i = 0; i<n ; i++){
//                 m = Digit(A[i],j);
//                 B[m][BB[m]] = A[j]; // B[9][0] = 9, B[1][0] = 1, B[1][1] = 1, 
//                 BB[m]++;     
//             }
            
//         } 
//         int i = 0;
//         for (int h = 0 ; h < 10; h++)
//             for (int x = 0 ; x <BB[h] ; x++){
//                 A[i] = B[h][x];
//                 i++ ;
//             }
               
//     }
// }
void RadixSort (int a[], int n, int NOP){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, pass;
 
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++)
         bucket_cnt[i] = 0;
      
      // 4 2 1 2 3 5 6
      for (i = 0; i < n; i++){
         r = Digit(a[i],0); // lấy giá trị đầu tiên trong số thứ a[i]
         bucket[r][bucket_cnt[r]] = a[i]; 
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }

      printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}

int main (){
    int a[] = {9,1,1,4,5,6,7,8};
    RadixSort(a,8,1);
    for(int i = 0 ; i < 8 ; i++)
        cout<<a[i]<<" ";
}