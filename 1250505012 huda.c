#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Say�sal bir de�eri 6-bitlik (00xxxx BCD) format�nda g�sterir.
void print_six_bit_binary(int val) {
    int i; // <-- Hata veren de�i�keni burada tan�mlad�k
    printf("00");
    for (i = 3; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

int main() {
    char char1, char2;
    int num1, num2, sum;

    // Girdileri karakter olarak al.
    printf("Ilk rakami (0-9) girin: ");
    scanf(" %c", &char1);
    printf("Ikinci rakami (0-9) girin: ");
    scanf(" %c", &char2);

    // Girdilerin rakam olup olmad���n� kontrol et.
    if (!isdigit(char1) || !isdigit(char2)) {
        printf("\n** HATA: Sadece tek haneli rakam karakteri girin! **\n");
        return 1;
    }

    // Karakterleri say�ya d�n��t�r.
    num1 = char1 - '0';
    num2 = char2 - '0';

    // Toplama i�lemini yap.
    sum = num1 + num2;

    printf("\nToplam: %d\n", sum);

    // K�s�tlama kontrol�.
    if (sum > 9) {
        printf("\n** HATA: Toplam tek haneyi (9'u) asti. **\n");
    } else {
        printf("6-Bit Kodlama: ");
        print_six_bit_binary(sum);
        printf("\n");
    }

    return 0;
}
