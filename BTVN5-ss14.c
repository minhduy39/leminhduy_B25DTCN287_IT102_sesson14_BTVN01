#include <stdio.h>

long long giai_thua(int n) {
    if (n < 0) {
        return -1; 
    }
    
    long long ket_qua = 1;
    int i;
    for ( i = 1; i <= n; i++) {
        ket_qua *= i;
    }
    return ket_qua;
}

int main() {
    int so;
    printf("Nhap so nguyen khong am: ");
    scanf("%d", &so);
    
    long long ket_qua = giai_thua(so);
    
    if (ket_qua == -1) {
        printf("So am khong co giai thua!\n");
    } else {
        printf("%d! = %lld\n", so, ket_qua);
    }
    
    return 0;
}
