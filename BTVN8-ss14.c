#include <stdio.h>
#include <stdbool.h>

bool la_so_hoan_hao(int n) {
    if (n <= 1) {
        return false; 
    }
    
    int tong_uoc = 1; 
    int i;
    for ( i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            tong_uoc += i;
            if (i != n / i) { 
                tong_uoc += n / i;
            }
        }
    }
    
    return tong_uoc == n;
}

int main() {
    int a, b;
    
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    
    printf("\nKet qua kiem tra:\n");
    if (la_so_hoan_hao(a)) {
        printf(" %d la so hoan hao\n", a);
    } else {
        printf(" %d khong phai so hoan hao\n", a);
    }
    
    if (la_so_hoan_hao(b)) {
        printf(" %d la so hoan hao\n", b);
    } else {
        printf(" %d khong phai so hoan hao\n", b);
    }
    
    return 0;
}
