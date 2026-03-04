#include <stdio.h>
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN

int main() {
    int n;

    // Membaca jumlah baris masukan berikutnya (n)
    scanf("%d", &n);

    int current_val;
    int min_val = INT_MAX; // Inisialisasi nilai terkecil dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai terbesar dengan nilai integer minimum

    // Membaca n baris masukan berikutnya dan mencari nilai terkecil serta terbesar
    for (int i = 0; i < n; i++) {
        scanf("%d", &current_val);
        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    // Menampilkan hasil sesuai spesifikasi Tugas 1
    printf("%d\n", min_val); // Nilai terkecil
    printf("%d\n", max_val); // Nilai terbesar

    return 0; // Mengakhiri program dengan sukses
} 
