#include<stdio.h>
#define MAX 100
void cau1(void)
{
    FILE* fi = fopen("test.txt","wt");
    char c,buf[MAX];
    printf("nhap noi dung: ");
    //Flush stdin neu la \n thi bo qua
    while ((c = getchar()) == '\n');
    ungetc(c, stdin);
    fgets(buf,MAX,stdin);
    printf("Mang da nhap: %s",buf);
    fputs(buf,fi);
    fclose(fi);
}
void cau2(void)
{
    FILE* fi = fopen("test.txt","rt");
    char buf[MAX];
    int i = 0;
    while(fscanf(fi,"%c",&buf[i++]) != EOF);
    printf("Du lieu trong file : %s",buf);
    fclose(fi);
}
void cau3(void)
{
    FILE* fi = fopen("test.txt","a");
    char c,buf[MAX];
    printf("nhap noi dung: ");
    //Flush stdin neu la \n thi bo qua
    while ((c = getchar()) == '\n');
    ungetc(c, stdin);
    fgets(buf,MAX,stdin);
    printf("Mang da them: %s",buf);
    fputs(buf,fi);
    fclose(fi);
}
void cau4(void)
{
    FILE* fi = fopen("test.txt","r");
    char buf[MAX];
    int i = 0;
    while(fscanf(fi,"%c",&buf[i++]) != EOF);
    char x;
    int tmp = i;
    char c;
    printf("Nhap ky tu can tim : ");
    while ((c = getchar()) == '\n');
    ungetc(c, stdin);
    scanf("%c",&x);
    for(i=0;i<tmp;i++){
        if (buf[i] == x){
            printf("Co\n");
            break;
        }      
        if (i == tmp)
            printf("Khong co\n");
    }
    fclose(fi);
}
int main() {
    char chon;
    printf("Chon: ");
    scanf(" %c",&chon);
    switch (chon)
    {
        case '1':
            cau1();
            break; 
        case '2':
            cau2();
            break;
        case '3':
            cau3();
            break;
        case '4':
            cau4();
            break;
    }
    return 0;
}
