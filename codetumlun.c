#include <stdio.h>
#include <math.h>
#include "time.h"
#include  <string.h>
// // int main (){
// //     int n;
// //     int tong=0;
// //     int i=0;
// //     printf ("Enter N number:");
// //     scanf ("%d",&n);
// //     while (i<=n){
// //         tong= i+ tong;
// //         i++;
// //     }
// //     printf ("Tong :%d",tong);
// // }
// #include <stdio.h>

// struct StaffInfo {  // More descriptive name
//     char first_name[100];
//     char last_name[100];
//     int age;
//     char gender[100];  // Consider using a char for single character (M/F)
//     float phoneNumber; // Corrected variable name
//     long ID;
// };

// int main() {
//     struct StaffInfo staff; // Corrected variable name
//     int choose;
// do {
//     printf("*********Enter Staff Information********\n");  // Consistent formatting
//     printf ("Press 1 to input staff information:\n");
//     printf ("Press 0 to exit:\n");
//     scanf ("%d",&choose);

// if (choose ==1){
// printf("Enter first name: ");
//     scanf("%s", staff.first_name);

//     printf("Enter last name: ");
//     scanf("%s", staff.last_name);

//     printf("Enter age: ");
//     scanf("%d", &staff.age); // Address of age for correct input

//     printf("Enter phone number: ");
//     scanf("%f", &staff.phoneNumber); // Address of phoneNumber

//     printf("Enter ID: ");
//     scanf("%ld", &staff.ID); // Address of ID

//     printf("\nStaff Information:\n");

//     printf("First name: %s\n", staff.first_name);
//     printf("Last name: %s\n", staff.last_name);
//     printf("Age: %d\n", staff.age);
//     printf("Gender: %s\n", staff.gender);  // Assuming gender input is handled elsewhere
//     printf("Phone number: %.2f\n", staff.phoneNumber); // Format for two decimal places
//     printf("ID: %ld\n", staff.ID);
// }
// }
// while (choose ==1);

//     return 0;
// }
// struct phanso
// {
//     int tuso;
//     int mauso;
// };
// void rutgonphanso (struct phanso *ps){
//   int a= ps->tuso;
//   int b= ps->mauso;
//   int uscl=1;
//   a= abs(a);
//   b= abs(b);
//   if (a==0 || b==0){
//     uscl =(a+b);
//   }
//   else {
//     while (a!=b){
//         if (a>b){
//             a=a-b;
//         }
//         else {
//             b=b-a;
//         }
//     }
//     uscl=a;
//   }
//   ps->tuso/=uscl;
//   ps->mauso/=uscl;
// }
// void inputphanso(struct phanso *ps){
// printf ("Nhap vao tu so:");
// scanf ("%d",&ps->tuso);
// do {
// printf ("Nhap vao mau so:");
// scanf ("%d",&ps->mauso);
// }while (ps->mauso ==0);
// if (ps->mauso <0){
//     ps->tuso *= -1;
//     ps->mauso *=-1;
// }

// }

// void printPhanso( struct phanso ps){
//     rutgonphanso(&ps);
// printf ("%d/%d",ps.tuso,ps.mauso);
// }
// void congtru2phanso (struct phanso ps1, struct phanso ps2){
//     struct phanso ketqua;
//     ketqua.tuso= ps1.tuso*ps2.mauso+ps2.tuso*ps1.mauso;
//     ketqua.mauso=ps1.mauso*ps2.mauso;
// }
// int main (){
// struct phanso ps1,ps2;
// inputphanso (&ps1);
// printf ("Phan so vua nhap la :");
// printPhanso(ps1);
// return 0;
// }
void hienthiDSSV (struct Sinhvien*,int);
void hienthitencot();
struct hoten
{
    char ho[20];
    char tendem[21];
    char ten[20];
};
struct Monhoc
{
    float diem_toan;
    float diem_anh;
    float diem_van;
    float diem_tbc;
};
struct Sinhvien
{
    int id;
    struct hoten Hovaten;
    int tuoi;
    char gioi_tinh[10];
    struct Monhoc Diem_mon_hoc;
};

void nhaphoaten(struct hoten *ten)
{
    printf("Ho: ");
    scanf("%s", ten->ho);
    printf("Ten Dem: ");
    getchar();
    gets(ten->tendem);
    printf("Ten: ");
    scanf("%s", ten->ten);
}
void nhapdiem(struct Monhoc *Diem_mon_hoc)
{
    printf("Toan: ");
    scanf("%f", &Diem_mon_hoc->diem_toan);
    printf("Van: ");
    scanf("%f", &Diem_mon_hoc->diem_van);
    printf("Anh: ");
    scanf("%f", &Diem_mon_hoc->diem_anh);
    Diem_mon_hoc->diem_tbc = (Diem_mon_hoc->diem_toan + Diem_mon_hoc->diem_van + Diem_mon_hoc->diem_anh) / 3;
    //  printf ("Diem trung binh Cong: &f");
}
struct Sinhvien nhapSV()
{
    struct Sinhvien sv;
    printf("Enter student ID:");
    scanf("%d", &sv.id);
    nhaphoaten(&sv.Hovaten);
    printf("Enter Tuoi: ");
    scanf("%d", &sv.tuoi);
    printf("Enter gioi tinh: ");
    scanf("%s", sv.gioi_tinh);
    nhapdiem(&sv.Diem_mon_hoc);
    return sv;
}
void sapxeptheoten(struct Sinhvien *ds, int slsv)
{ // dung bubble sort
    for (int i = 0; i < slsv; i++)
    {
        for (int j = slsv - 1; j > i; j--)
        {
            if (strcmp(ds[j].Hovaten.ten, ds[j - 1].Hovaten.ten) < 0)
            {
                struct Sinhvien sv = ds[j];
                ds[j] = ds[j - 1];
                ds[j - 1] = sv;
            }
        }
    }
}
void sapxeptheodiem(struct Sinhvien *ds, int slsv)
{ // dung bubble sort
    for (int i = 0; i < slsv; i++)
    {
        for (int j = slsv - 1; j > i; j--)
        {
            if (ds[j].Diem_mon_hoc.diem_tbc > ds[j].Diem_mon_hoc.diem_tbc)
            {
                struct Sinhvien sv = ds[j];
                ds[j] = ds[j - 1];
                ds[j - 1] = sv;
            }
        }
    }
}
void timtheoten(struct Sinhvien *ds, int slsv)
{
    char ten[30];
    int timsv = 0;
    printf("Nhap ten can tim: ");
    scanf("%s", &ten);

    hienthitencot();
    for (int i = 0; i < slsv; i++)
    {
        if (strcmp(ten, ds[i].Hovaten.ten) == 0)
        {
            hienthitensinhvien(ds[i]);
            timsv = 1;
        }
    }
    if (timsv == 0)
    {
        printf("Khong co thong in sinh vien %s trong danh sach\n", ten);
    }
}
void docfile(struct Sinhvien *ds, int *slsv)
{
    FILE *fout = fopen("Sinh Vien.txt", "r");
    int i=0;
    if (fout){
    for (;;)
    {
        struct Sinhvien sv;
        fscanf(fout, "%10d %10s %20s[^\n] %10s %-0d %10s %10f %10f %10f %10f\n ", &sv.id, sv.Hovaten.ho, sv.Hovaten.tendem, sv.Hovaten.ten, &sv.tuoi, sv.gioi_tinh, &sv.Diem_mon_hoc.diem_toan, &sv.Diem_mon_hoc.diem_van, &sv.Diem_mon_hoc.diem_anh, &sv.Diem_mon_hoc.diem_tbc);
    if(feof(fout)){
        break;
    }
    ds[i++]=sv;
    }
    }
    fclose(fout);
    *slsv=i;
}
void hienthitensinhvien(struct Sinhvien sv)
{
    printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n ", sv.id, sv.Hovaten.ho, sv.Hovaten.tendem, sv.Hovaten.ten, sv.tuoi, sv.gioi_tinh, sv.Diem_mon_hoc.diem_toan, sv.Diem_mon_hoc.diem_van, sv.Diem_mon_hoc.diem_anh, sv.Diem_mon_hoc.diem_tbc);
}
void hienthitencot()
{
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n ", "Ma SV", "Ho", "Ten Dem", "Ten", "Tuoi", "Gioi Tinh", "Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
}
void hienthidssv(struct Sinhvien *ds, int slsv)
{
    hienthitencot();
    for (int i = 0; i < slsv; i++)
    {
        hienthitensinhvien(ds[i]);
    }
    printf ("----------------------------------------------\n");
}
int main()
{
    struct Sinhvien danh_sach_sinh_vien[100];
    int slsv = 0;
    docfile (danh_sach_sinh_vien,&slsv);
    printf ("\n Danh sach sinh vien hien thoi!");
    hienthidssv(danh_sach_sinh_vien,slsv);
    int choose;
    do
    {
        printf("********** Trang thong tin sinh vien **********");
        printf("\n*********Menu**********");
        printf("\n1.Them sinh vien vao danh sach");
        printf("\n2.Hien thi danh sach sinh vien");
        printf("\n3.Sap sep danh sach sinh vien");
        printf("\n4.Sap sap theo diem giam dan");
        printf("\n5.Tim sinh vien theo ten");
        printf("\n6.In thong tin ra file");
        printf("\n0Thoat khoi chuong trinh");
        printf("\nAn lua chon: ");
        scanf("%d", &choose);
        struct Sinhvien sv;
        switch (choose)
        {
        case 0:
            break;
        case 1:
            sv = nhapSV();
            danh_sach_sinh_vien[slsv++] = sv;
            break;
        case 2:
            hienthitencot();
            for (int i = 0; i < slsv; i++)
            {
                hienthitensinhvien(danh_sach_sinh_vien[i]);
            }
            break;
        case 3:
            sapxeptheoten(danh_sach_sinh_vien, slsv);
            hienthitencot();
            for (int i = 0; i < slsv; i++)
            {
                hienthitensinhvien(danh_sach_sinh_vien[i]);
            }
            break;
        case 4:
            sapxeptheodiem(danh_sach_sinh_vien, slsv);
            hienthitencot();
            for (int i = 0; i < slsv; i++)
            {
                hienthitensinhvien(danh_sach_sinh_vien[i]);
            }
            break;
        case 5:
            timtheoten(danh_sach_sinh_vien, slsv);
            break;
        case 6:
            docfile(danh_sach_sinh_vien, &slsv);
            break;
        default:
            printf("Loi nhap lua chon, vui long nhap lai:\n");
            break;
        }
    } while (choose);

    return 0;
}
