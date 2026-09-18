#include <iostream>

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai sistem awal (K): ";
    std::cin >> k;


    int* astronot = new int[n];
    for (int i = 0; i < n; ++i) {
        astronot[i] = i + 1;
    }

    int sisa = n;
    int idx = 0;

    std::cout << "Urutan eliminasi: ";
    while (sisa > 1) {
        int langkah = k - 1;
        
        while (langkah > 0) {
            idx = (idx + 1) % n;
            if (astronot[idx] != 0) {
                langkah--;
            }
        }

        int tereliminasi = astronot[idx];
        std::cout << tereliminasi << " ";
        
        astronot[idx] = 0;
        sisa--;

        if (tereliminasi % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }
        if (k < 2) k = 2;

        while (sisa > 0 && astronot[idx] == 0) {
            idx = (idx + 1) % n;
        }
    }
    std::cout << "\n";

    for (int i = 0; i < n; ++i) {
        if (astronot[i] != 0) {
            std::cout << "Astronot terakhir yang bertahan: " << astronot[i] << "\n";
            break;
        }
    }

    delete[] astronot;
    return 0;
}
