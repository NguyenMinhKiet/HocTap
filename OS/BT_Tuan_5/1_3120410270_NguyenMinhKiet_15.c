#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//hàm cộng các phần tử của n
int SumNumber(int n)
{
    int sum = 0, tmp;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main(int argc, char *argv[])
{
    int n = -1;
    int a[300000];
    int dem = 0;
    //kiểm tra số lượng tham số đầu vào
    if (argc != 4)
    {
        printf("Thieu tham so");
        return 1;
    }
    int num = atoi(argv[1]);
    // nếu sai điều kiện -> nhập lại số đầu
    if (num < 0 || num > 40)
    {
        printf("--------Phan tu dau nam tu 0 -> 40-----------\n");
        printf("--------mo chuong trinh theo thu tu---------\n");
        printf("(0->40) (Input File Name) (Output File Name)\n");
        return 2;
    };
    //  khai báo con trỏ FILE và mở FILE để đọc
    FILE *input = fopen(argv[2], "rt");
    // kiểm tra File tồn tại
    if (!input)
    {
        printf("File %s khong ton tai", argv[2]);
        return 3;
    }
    //đọc đến cuối file thì dừng lại
    while (fscanf(input, "%d", &a[++n]) != EOF)
        ;
    // mở file ghi
    FILE *output = fopen(argv[3], "wt");
    for (int i = 0; i < n; i++)
        if (SumNumber(a[i]) == atoi(argv[1]))
        {
            fprintf(output, "%d\n", a[i]);
            dem++;
        }

    printf("Tong so luong thoa man dieu kien la %d", dem);
    // đóng 2 file đã mở
    fclose(input);
    fclose(output);
    return 0;
}