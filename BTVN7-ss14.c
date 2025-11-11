#include <stdio.h>
#include <stdbool.h>

bool la_so_nguyen_to(int n) {
    if (n < 2) {
        return false;
    }
    int i;
    for ( i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int so;
    printf("Nhap so can kiem tra: ");
    scanf("%d", &so);
    
    if (la_so_nguyen_to(so)) {
        printf("%d là so nguyen to\n", so);
    } else {
        printf("%d khong phai la so nguyen to\n", so);
    }
    
    return 0;
}
