//a[], b[] da dc sap xep,  a[], b[] => c[]
//tach a[] thanh cac duong chay nho hon


// hàm time() => chạy lấy cái sau trừ cái trước

// asctime()

// clock()

// ctime()

// divtime()


#include <iostream>

using namespace std;

void sortArrayAB(int a[], int b[], int c[], int n, int m);

int main()
{
}

void sortArrayAB(int a[], int b[], int c[], int n, int m)
{
    //pro

    int s = n + m;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];          

    //noob

    // for(int k = 0; k < s; k++){
    //     if(i<n && j<m){
    //         if(a[i] <= b[j]){
    //             c[k] = a[i];
    //             i++;
    //         } else{
    //             c[k] = b[j];
    //             j++;
    //         }
    //     } else if(i < n){
    //         c[k] = a[i];
    //         i++;
    //     } else{
    //         c[k] = b[j];
    //         j++;
    //     }
    // }
}

void splitArray(int a[], int n){
    //pro
    int i = 0, start = 0, end = 0;
    while(i<n){
        start = i;
        while(i<n-1&&a[i]<=a[i+1]){i++;}
        end = i;
        i++;
    }


    //noob + wrong somewhere X))

    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         int p = j+1;
    //         if(a[j] < a[p]){
    //             start = i;
    //             end = p;
    //         } else break;
    //     }
    // }


    //pro with counting number of comparsion and assignment

    // void splitArray(int a[], int n){
    // int i = 0, start = 0, end = 0;
    // int count1 = 3, count2 = 0;
    // while(i<n){
    //     count2++;
    //     start = i;
    //     count1++;
    //     while(i<n-1&&a[i]<=a[i+1]){count2+=2;i++;count1++;}
    //     if(i<n-1)count2+=2;
    //     else count2++;
    //     end = i;
    //     i++;
    //     count1+=2;
    // }
    // count2++;
}


