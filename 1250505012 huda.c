#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Sayýsal bir deðeri 6-bitlik (00xxxx BCD) formatýnda gösterir.
void print_six_bit_binary(int val) {
    int i; // <-- Hata veren deðiþkeni burada tanýmladýk
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

    // Girdilerin rakam olup olmadýðýný kontrol et.
    if (!isdigit(char1) || !isdigit(char2)) {
        printf("\n** HATA: Sadece tek haneli rakam karakteri girin! **\n");
        return 1;
    }

    // Karakterleri sayýya dönüþtür.
    num1 = char1 - '0';
    num2 = char2 - '0';

    // Toplama iþlemini yap.
    sum = num1 + num2;

    printf("\nToplam: %d\n", sum);

    // Kýsýtlama kontrolü.
    if (sum > 9) {
        printf("\n** HATA: Toplam tek haneyi (9'u) asti. **\n");
    } else {
        printf("6-Bit Kodlama: ");
        print_six_bit_binary(sum);
        printf("\n");
    }

    return 0;
}
