#include<stdio.h>
// int get_max (int a[], int n){
//    int max = a[0];
//    for (int i = 1; i < n; i++)
//       if (a[i] > max)
//          max = a[i];
//    return max;
// }
int Digit(int n, int k){
    int value = 1;
    for (int i = 0 ; i<k ; i++)
        value*=10;
    return (n / value) % 10;
}
void radix_sort (int a[], int n, int NOP){
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
   int i, n, a[10];
   printf ("Enter the number of items to be sorted: ");
   scanf ("%d", &n);
   printf ("Enter items: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &a[i]);
   }
   radix_sort (a, n, 1);
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   printf ("\n");
   return 0;
}
