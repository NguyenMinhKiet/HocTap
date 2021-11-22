#include <iostream>
using namespace std;

// void sortArrayAB(int a[], int b[], int c[], int n, int m)
// {
//     //pro
//     int s = n + m;
//     c = new int[s];
//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m)
//     {
//         if (a[i] < b[j])
//             c[k++] = a[i++];
//         else
//             c[k++] = b[j++];
//     }
//     while (i < n)
//         c[k++] = a[i++];
//     while (j < m)
//         c[k++] = b[j++];         
// }

// void MergeSort(int a[], int l, int r){
//     int mid;
//     if(l<r){
//         mid = (l+r)/2;
//         MergeSort(a,l,mid);
//         MergeSort(a,mid+1,r);
//     }

// }
void Merge(int a[], int left, int mid, int right)
{
	int *temp; // Khoi tao mang tam de sap xep
	int i = left; // Vi tri phan tu dau tien cua mang con ben trai
	int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai

	temp = new int[right - left + 1]; // Khoi tao so luong phan tu cua mang tam

	for (int k = 0; k <= right - left; k++)
	{
		// Kiem phan tu cua mang con ben trai va ben phai
		if (a[i] < a[j]) 
		{
			// Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
			temp[k] = a[i]; 
			i++; // Vi tri phan tu tiep theo cua mang
		}
		else // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
		{
			temp[k] = a[j];
			j++; // Vi tri phan tu tiep theo cua mang
		}

		// Kiem tra mang con ben trai con phan tu nao khong
		if (i == mid + 1) 
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		// Kiem tra mang con ben phai con phan tu nao khong
		if (j == right + 1) 
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh
		a[left + k] = temp[k];
	delete temp;
}

// left, right la bien trai va bien phai cua mang
void MergeSort(int a[], int left, int right)
{
	if (right > left)
	{
		int mid; // Phan tu o giua
		mid = (left + right) / 2;
		MergeSort(a, left, mid); // Goi de quy mang con ben trai
		MergeSort(a, mid + 1, right); // Goi de quy mang con ben phai
		Merge(a, left, mid, right); // Goi ham so sanh hai mang con
	}
}

int main()
{
	int a[10], n = 10;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap so " << i + 1 << ": ";
		cin >> a[i];
	}

	MergeSort(a, 0, 9);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}