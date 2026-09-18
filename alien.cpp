#include <iostream>

int hitungPanjang(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char pesan[1000];
    std::cout << "Masukkan pesan asli (Huruf Kapital): ";
    std::cin >> pesan;

    int panjang = hitungPanjang(pesan);
    char hasil[1000];

    if (panjang > 0) {
        hasil[0] = pesan[0];
    }

    for (int i = 1; i < panjang; ++i) {
        int val_sekarang = pesan[i] - 'A' + 1;
        int val_sebelum = pesan[i - 1] - 'A' + 1;

        int val_baru = val_sekarang + val_sebelum;

        while (val_baru > 26) {
            val_baru -= 26;
        }

        hasil[i] = (char)(val_baru - 1 + 'A');
    }
    hasil[panjang] = '\0'; 

    std::cout << "Pesan sandi: " << hasil << "\n";

    return 0;
}