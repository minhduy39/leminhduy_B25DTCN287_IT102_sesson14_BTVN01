#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int n = 0;
void nhapMang();
void inMang();
void themPhanTu();
void suaPhanTu();
void xoaPhanTu();
void sapXepMenu();
void sapXepGiamDan();
void sapXepTangDan();
void timKiemMenu();
int timKiemTuyenTinh(int x);
int timKiemNhiPhan(int x);
void sapXepTangDan(); 

int main() {
    int luaChon;
    
    do {
        printf("\n=== MENU QUAN LY MANG ===\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6:
                sapXepMenu();
                break;
            case 7:
                timKiemMenu();
                break;
            case 8:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon tu 1-8.\n");
        }
    } while(luaChon != 8);
    
    return 0;
}

void nhapMang() {
    printf("Nhap so phan tu (toi da %d): ", MAX);
    scanf("%d", &n);
    
    if(n < 0 || n > MAX) {
        printf("So phan tu khong hop le!\n");
        n = 0;
        return;
    }
    
    printf("Nhap gia tri cho cac phan tu:\n");
    int i;
    for( i = 0; i < n; i++) {
        printf(" arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Da nhap thanh cong %d phan tu!\n", n);
}

void inMang() {
    if(n == 0) {
        printf("Mang dang rong!\n");
        return;
    }
    
    printf("Cac phan tu trong mang:\n");
    int i;
    for( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu() {
    if(n >= MAX) {
        printf("Mang da day, khong the them phan tu moi!\n");
        return;
    }
    
    int viTri, giaTri;
    printf("Nhap vi tri can them (0 - %d): ", n);
    scanf("%d", &viTri);
    
    if(viTri < 0 || viTri > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    
    printf("Nhap gia tri can them: ");
    scanf("%d", &giaTri);
    int i;
    for( i = n; i > viTri; i--) {
        arr[i] = arr[i-1];
    }
    
    arr[viTri] = giaTri;
    n++;
    
    printf("Da them phan tu %d vao vi tri %d!\n", giaTri, viTri);
}

void suaPhanTu() {
    if(n == 0) {
        printf("Mang rong, khong co phan tu de sua!\n");
        return;
    }
    
    int viTri, giaTriMoi;
    printf("Nhap vi tri can sua (0 - %d): ", n - 1);
    scanf("%d", &viTri);
    
    if(viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    
    printf("Phan tu hien tai tai vi tri %d: %d\n", viTri, arr[viTri]);
    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTriMoi);
    
    arr[viTri] = giaTriMoi;
    printf("Da cap nhat phan tu tai vi tri %d thanh %d!\n", viTri, giaTriMoi);
}

void xoaPhanTu() {
    if(n == 0) {
        printf("Mang rong, khong co phan tu de xoa!\n");
        return;
    }
    
    int viTri;
    printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
    scanf("%d", &viTri);
    
    if(viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    
    printf("Da xoa phan tu %d tai vi tri %d!\n", arr[viTri], viTri);
    int i;
    for( i = viTri; i < i - 1; i++) {
        arr[i] = arr[i+1];
    }
    
    n--;
}

void sapXepMenu() {
    int luaChon;
    
    do {
        printf("\n=== MENU SAP XEP ===\n");
        printf("a. Giam dan\n");
        printf("b. Tang dan\n");
        printf("c. Quay lai menu chinh\n");
        printf("Lua chon cua ban: ");
        
        char chon;
        scanf(" %c", &chon);
        
        switch(chon) {
            case 'a':
            case 'A':
                sapXepGiamDan();
                printf("Da sap xep giam dan!\n");
                inMang();
                break;
            case 'b':
            case 'B':
                sapXepTangDan();
                printf("Da sap xep tang dan!\n");
                inMang();
                break;
            case 'c':
            case 'C':
                return;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(1);
}

void sapXepGiamDan() {
	int i,j;
    for( i = 0; i < n - 1; i++) {
        for( j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepTangDan() {
	int i,j;
    for( i = 0; i < n - 1; i++) {
        for( j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void timKiemMenu() {
    if(n == 0) {
        printf("Mang rong, khong the tim kiem!\n");
        return;
    }
    
    int luaChon, giaTri, ketQua;
    
    do {
        printf("\n=== MENU TIM KIEM ===\n");
        printf("a. Tim kiem tuyen tinh\n");
        printf("b. Tim kiem nhi phan\n");
        printf("c. Quay lai menu chinh\n");
        printf("Lua chon cua ban: ");
        
        char chon;
        scanf(" %c", &chon);
        
        switch(chon) {
            case 'a':
            case 'A':
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                ketQua = timKiemTuyenTinh(giaTri);
                if(ketQua != -1) {
                    printf("Tim thay %d tai vi tri %d\n", giaTri, ketQua);
                } else {
                    printf("Khong tim thay %d trong mang!\n", giaTri);
                }
                break;
            case 'b':
            case 'B':
                printf("Can mang duoc sap xep tang dan de tim kiem nhi phan!\n");
                printf("Ban co muon sap xep mang khong? (1: Co, 0: Khong): ");
                int sapXep;
                scanf("%d", &sapXep);
                
                if(sapXep == 1) {
                    sapXepTangDan();
                    printf("Da sap xep mang tang dan!\n");
                    inMang();
                }
                
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                ketQua = timKiemNhiPhan(giaTri);
                if(ketQua != -1) {
                    printf("Tim thay %d tai vi tri %d\n", giaTri, ketQua);
                } else {
                    printf("Khong tim thay %d trong mang!\n", giaTri);
                }
                break;
            case 'c':
            case 'C':
                return;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(1);
}

int timKiemTuyenTinh(int x) {
	int i;
    for( i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int timKiemNhiPhan(int x) {
    int left = 0;
    int right = n - 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
