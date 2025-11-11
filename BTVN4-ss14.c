#include <stdio.h>

void in_mang_nguyen(int arr[], int n) {
    printf("Cac phan tu trong mang: ");
    int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int mang1[] = {1, 2, 3, 4, 5};
    int mang2[] = {10, 20, 30, 40};
    
    in_mang_nguyen(mang1, 5);
    in_mang_nguyen(mang2, 4);
    
    return 0;
}
