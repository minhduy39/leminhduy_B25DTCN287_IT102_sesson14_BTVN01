#include <stdio.h>

int tim_so_lon_nhat(int arr[], int n) {
    if (n <= 0) {
        return -1; 
    }
    
    int max = arr[0]; 
    int i;
    for ( i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    int mang1[] = {1, 5, 3, 9, 2};
    int mang2[] = {-5, -2, -10, -1};
    int mang3[] = {42};
    
    int n1 = sizeof(mang1) / sizeof(mang1[0]);
    int n2 = sizeof(mang2) / sizeof(mang2[0]);
    int n3 = sizeof(mang3) / sizeof(mang3[0]);
    
    printf("Mang 1: So lon nhat là %d\n", tim_so_lon_nhat(mang1, n1));
    printf("Mang 2: So lon nhat là %d\n", tim_so_lon_nhat(mang2, n2));
    printf("Mang 3: So lon nhat là %d\n", tim_so_lon_nhat(mang3, n3));
    
    return 0;
}
