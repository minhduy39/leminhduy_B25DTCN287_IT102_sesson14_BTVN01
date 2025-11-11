#include <stdio.h>

int tinh_tong(int a, int b) {
    return a + b;
}

int main() {
    int number1 = 5, number2 = 3;
    int ket_qua = tinh_tong(number1, number2);
    
    printf("Tong cua %d và %d là: %d\n", number1, number2, ket_qua);
    return 0;
}
