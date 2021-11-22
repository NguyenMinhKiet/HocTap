#include<stdio.h>
#include<string.h>
typedef struct SinhVien
{
 char Mssv[20];
 char HovaTen[50];
 char Lop[10];
 char Nganh[11];
 char GioiTinh[7];
 float DiemCSDL;
 float DiemCTDL;
 float DiemKTLT;
 float DiemTB;
} SV;
void Nhap(SV &sv)
{
 printf("\nMoi nhap ma sinh vien= "); gets(sv.Mssv); gets(sv.Mssv);
 printf("\nMoi nhap ho ten sinh vien= "); gets(sv.HovaTen);
 printf("\nMoi nhap lop cua sinh vien= "); gets(sv.Lop);
 printf("\nMoi nhap nghanh cua sinh vien= "); gets(sv.Nganh);
 printf("\nMoi nhap gioi tinh sinh vien= "); gets(sv.GioiTinh);
 printf("\nMoi nhap diem mon CSDL= "); scanf("%f", &sv.DiemCSDL);
 printf("\nMoi nhap diem mon CTDL= "); scanf("%f", &sv.DiemCTDL);
 printf("\nMoi nhap diem mon KTLT= "); scanf("%f", &sv.DiemKTLT);
 sv.DiemTB = (sv.DiemCSDL + sv.DiemCTDL + sv.DiemKTLT) / 3;
}
void DongDauTien()
{
  printf("\n%c",218);
  for(int i=0;i<5;i++)
   printf("%c",196);
  printf("%c", 194);
  for(int i=0;i<19;i++)
   printf("%c",196);
  printf("%c", 194);
  for(int i=0;i<9;i++)
   printf("%c",196);
  printf("%c", 191);
}
void DongGiua()
{
  printf("\n%c",195);
  for(int i=0;i<5;i++)
   printf("%c",196);
  printf("%c", 197);
  for(int i=0;i<19;i++)
   printf("%c",196);
  printf("%c", 197);
  for(int i=0;i<9;i++)
   printf("%c",196);
  printf("%c", 180);
}
void DongCuoi()
{
  printf("\n%c",192);
  for(int i=0;i<5;i++)
   printf("%c",196);
  printf("%c", 193);
  for(int i=0;i<19;i++)
   printf("%c",196);
  printf("%c", 193);
  for(int i=0;i<9;i++)
   printf("%c",196);
  printf("%c", 217);
}
void Xuat(SV sv)
{
 rewind(stdin);
 printf("\nMssv = %s",sv.Mssv);
 printf("\tHo ten = %s",sv.HovaTen);
 printf("\tLop = %s",sv.Lop);
 printf("\tNganh = %s",sv.Nganh);
 printf("\tGioi tinh = %s",sv.GioiTinh); 
 printf("\tDiem mon csdl = %.1f",sv.DiemCSDL);
 printf("\tDiem mon ctdl = %.1f",sv.DiemCTDL);
 printf("\tDiem mon ktlt = %.1f",sv.DiemKTLT);
 printf("\tDiem TB: %.1f",sv.DiemTB);
}
struct Node
{
 SV info;
 Node* pNext; 
};
typedef Node *PtrNode;
void Init(PtrNode &pHead)
{
 pHead = NULL; 
}
bool IsEmpty(PtrNode pHead)
{
 return pHead==NULL; 
}
//Tao mot node moi tu du lieu la SV
PtrNode CreateNode (SV x) 
{
 PtrNode p = new Node;
 p->info = x;
 p->pNext=NULL;
 return p;
}
//chen phan tu moi pNew vao cuoi danh sach
void InsertLast(PtrNode &pHead, PtrNode pNew)
{
 if(IsEmpty(pHead)) //neu danh sach rong thi
 pHead = pNew; //phan tu moi pNew chinh la phan tu dau tien
 else //nguoc lai
 {
 PtrNode p = pHead; //di tim phan tu cuoi cung cua DS => duyet tu dau
 while( p->pNext != NULL) //trong khi chua phai la phan tu cuoi cung thi
 p = p->pNext ;  //qua phan tu ke
 p->pNext = pNew; //gan phan tu moi pNew vao sau phan tu cuoi cung
 }
}
//them nhieu SV vao cuoi DS: (co the la 1 Sv, co the la nhieu SV)
void AddStudent(PtrNode &pHead) 
{
 int n;
 SV sv;
 printf("\nSo luong sinh vien can them: ");
 scanf("%d", &n);
 for(int i = 1; i <= n; i++) 
 {
 Nhap(sv);
 PtrNode pTmp = CreateNode(sv);
 InsertLast(pHead, pTmp);
 }
}
void Input(PtrNode &pHead)
{
 SV x; //int -> SV ????????
 Init(pHead);
 int n; printf("Moi nhap so luong sinh vien n= "); scanf("%d", &n);
 for(int i=0; i<n ; i++)
 {
 printf("\nMoi nhap thong tin sinh vien thu %d: ", i+1);
 Nhap(x);
 PtrNode pNew = CreateNode(x);
 InsertLast(pHead, pNew);
 }
}
void ShowList(PtrNode pHead)
{
 Node *p = pHead; //duyet tu dau DS 
 int i=0;
 while (p!=NULL) //trong khi chua het DS
 {
 printf("\n Thong tin sinh vien thu %d: ", i+1);
 Xuat(p->info);
 p = p->pNext; 
 i++; 
 }
}
void Swap(SV &x,SV &y){
 SV t=x;
 x=y;
 y=t;
}
void InterchangeSort(PtrNode pHead)
{
   for(PtrNode p = pHead; p->pNext!=NULL; p=p->pNext)//duyet tu dau DS cho den phan tu ap cuoi p
     for(PtrNode q=p->pNext; q!=NULL; q=q->pNext) //duyet tu phan tu sau p cho den het DS q
  if(p->info.DiemTB > q->info.DiemTB)       //neu phan tu dung truoc p> phan tu sau q thi
  Swap(p->info,q->info); //Hoan vi p->info va q->info
}
int SVDuDiemQuaMonCTDL(PtrNode pHead )
{
 int count = 0;
 Node* p = pHead;
 while (p != NULL)
 {
 if (p->info.DiemCTDL >= 4)
 count++;
 p = p->pNext;
 }
 return count;
}
PtrNode TimSVTheoTen(PtrNode pHead , char k[] )
{
    PtrNode p=pHead;
    while (p!=NULL)
    {
        if(strcmp(k,p->info.HovaTen)==0)  
 return p;   
        p=p->pNext;  
    }
    return NULL;
}
int SVKha(PtrNode pHead)
{
 int count = 0;
 Node* p = pHead;
 while (p != NULL)
 {
 if (p->info.DiemTB >= 7)
 count++;
 p = p->pNext;
 }
 return count;
}
//sap xep theo ma so sinh vien
void SortList(PtrNode &pHead)
{
 for(Node *pTmp=pHead;pTmp->pNext!=NULL;pTmp=pTmp->pNext)
   for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
     if(strcmp(pTmp2->info.Mssv , pTmp->info.Mssv)>0) 
      Swap(pTmp2->info, pTmp->info);
}
//tinh trung binh cua tat ca cac sinh vien
float TinhDiemTrungBinh(PtrNode pHead)
{ 
 float s = 0;
 int dem=0;
 Node *p= pHead;
 while(p)
 {
 s+=p->info.DiemTB;
 dem++;
 p=p->pNext;
 }
 return s/dem;
}
//ham tim sinh vien nganh ke toan
PtrNode TimKeToan(PtrNode pHead)
{
 PtrNode p = pHead;
 while (p != NULL)
 {
 if (strcmpi("Ke toan", p->info.Nganh) == 0)
 return p;
 p = p->pNext;
 }
 return NULL; 
}
//Danh sach sinh vien co diem CSDL = 0
void DSSvDiemCSDL0(PtrNode pHead)
{
 Node *p = pHead;
 while (p != NULL)
 {
 if (p->info.DiemCSDL == 0)
 Xuat(p->info);
 p = p->pNext;
 }
}
//tim node dung truoc node X can xoa
PtrNode searchBeforeX(PtrNode phead, char x[])
{
 PtrNode p = phead; //int i=0;
 while(p->pNext) //while(p->next!=NULL)    while(i<n-1)
 {
 if(strcmp( p->pNext->info.HovaTen,x) == 0) //if(a[i+1] == x)
 return p; //return i
 p=p->pNext; //i++;
 }
 return NULL; //return -1;
}
void deleteHead(PtrNode &phead){
 PtrNode pDel = phead; //gan phan tu pDel la phan tu dau
 phead = phead->pNext;  //cap nhat con tro dau DS
 delete pDel; //xoa phan tu pDel
}
void deleteX(PtrNode &phead,char x[]){
 if(strcmp( phead->info.HovaTen,x) == 0)
 deleteHead(phead);
 else
 {
 PtrNode p = searchBeforeX(phead,x);
 if(p)
 {
 PtrNode pSau1 = p->pNext; //pSau1 la phan tu dung sau p ma ta se xoa
 PtrNode pSau2 = pSau1->pNext; //pSau2 sau node pSau1
 p->pNext = pSau2; //cach ly pSau1 ra khoi DS
 delete pSau1; //xoa pSau1
 }
 } 
}
//dem SV nu va gioi
int SVGioiVaNu (PtrNode pHead)
{
    PtrNode p;
    int dem=0; 
    p=pHead; 
    while (p!=NULL)
    {       
        if(p->info.DiemCSDL>=8 && p->info.DiemCTDL>=8 && p->info.DiemKTLT>=8 && strcmp(p->info.GioiTinh,"nu")==0)  
 dem++;
        p=p->pNext;
    }
    return dem;
}
void DanhSachSVDiemCTDLGioi(PtrNode pHead)
{
 Node *p = pHead;
 while (p != NULL)
 {
 if (p->info.DiemCTDL >= Xuat(p->info));
 p = p->pNext;
 }
}
PtrNode TimMax(PtrNode pHead)
{
 PtrNode pM = pHead;  
 PtrNode p = pM->pNext; 
 while (p != NULL)  
 {
 if (p->info.DiemKTLT > pM->info.DiemKTLT)
 pM = p;
 p = p->pNext;
 }
 return pM;
}
void DongDauTienMenu()
{
  printf("\n%c",218);
  for(int i=0;i<60;i++)
   printf("%c",196);
  printf("%c", 191);
}
void DongGiuaMenu()
{
  printf("%c",195);
  for(int i=0;i<60;i++)
   printf("%c",196);
  printf("%c", 180);
}
void DongCuoiMenu()
{
  printf("\n%c",192);
  for(int i=0;i<60;i++)
   printf("%c",196);
  printf("%c", 217);
}
int Menu(int &n){
 DongDauTienMenu();
 printf("\n%c============================= MENU =========================%c\n",179,179);
 DongGiuaMenu();
 printf("\n%c 1 - Them sinh vien.                                        %c\n",179,179);
 DongGiuaMenu();
 printf("\n%c 2 - Xoa sinh vien khoi danh sach.%c",179,179);
 printf(" 3 - Tinh diem trung binh.\n"); 
 printf(" 4 - Sap xep danh sach sinh vien theo diem trung binh.\n");
 printf(" 5 - Tim cac sinh vien co diem CTDL >=8.\n");
 printf(" 6 - Tim sinh vien diem 0 mon co so du lieu.\n");
 printf(" 7 - Tim sinh vien theo ten sinh vien.\n");
 printf(" 8 - Sinh vien du diem qua mon CTDL.\n");
 printf(" 9 - So sinh vien dat loai kha .\n");
 printf(" 10- Tim sinh vien hoc nganh ke toan.\n");
 printf(" 11- Sinh vien dat loai gioi la nu.\n");
 printf(" 12- Sap xep danh sach sinh vien theo mssv .\n"); 
 printf(" 13- Thoat .\n"); 
 DongCuoiMenu();
 printf("\n============================================================\n");
 printf(" >> Chon chuc nang: " );
 scanf("%d", &n);
 return n; 
}
void Xuly(PtrNode pHead, int chon)
{
 float kq;
 PtrNode d;
 switch(chon) 
 {
 case 1: AddStudent(pHead);
 ShowList(pHead);
 break;
 case 2: char x[50];
 printf("\nTen sinh vien can xoa: ");
 fflush(stdin); gets(x);
 deleteX(pHead,x);
 printf("\nDanh sach sau khi xoa = "); ShowList(pHead);
 break;
 case 3: kq = TinhDiemTrungBinh(pHead);
 printf("\nDiem TB ca DS: %.2f", kq);
 break;
 case 4: printf("\n Danh sach sinh vien sau khi sap xep diem trung binh ");
 InterchangeSort(pHead);
 ShowList(pHead); 
 break;
 case 5: printf("\nDssv co diem CTDL >= 8");
 DanhSachSVDiemCTDLGioi(pHead);
 break;
 case 6: printf("\nDanh sach sv nao 0 diem mon CSDL!");
 DSSvDiemCSDL0(pHead);
 break;
 case 7: char k[20];
 printf("\n===Cau 7: Nhap ten sv can tim: ");
 fflush(stdin); gets(k);
 d=TimSVTheoTen(pHead,k);
 if(d==NULL)printf("Khong tim thay sinh vien ten %s trong danh sach",k);
 else
 { 
 printf("Sinh vien ten %s trong danh sach la: ",k);  
 Xuat(d->info);  
 }
 break; 
 case 8: printf("\nSo sinh vien du diem qua mon la:%d",SVDuDiemQuaMonCTDL(pHead));
 break;
 case 9: printf("\nSo sinh vien kha la:%d",SVKha(pHead));
 break;
 case 10:d = TimKeToan(pHead);
 if (d == NULL)
 printf("\nKhong tim thay sv hoc nganh 'Ke toan'!");
 else
 {
 printf("\nDa tim thay sv hoc nganh 'Ke toan':");
 Xuat(d->info);
 }
 break;
 case 11:printf("\nSo luong nu hsg la: %d",SVGioiVaNu(pHead));
 break;
 case 12:SortList(pHead);
 ShowList(pHead);
 DongCuoi(); 
 break;
 default: printf("Ban nhap sai chuc nang, moi nhap lai...\n");
 }
}
int main()
{
    //PtrNode pHead;
    //Input(pHead); 
 int chon;
 do 
 {
 Menu(chon);
 if(  chon ==  13)
 break; 
 //Xuly(pHead,chon);
 }while(1);
 return 0;
}