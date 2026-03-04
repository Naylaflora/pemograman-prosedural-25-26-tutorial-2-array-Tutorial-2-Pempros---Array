#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX dan DBL_MIN

int main() {
    int n;
    
    // Membaca nilai n
    scanf("%d", &n);

    int current_num;
    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer

    double min_avg_consecutive = DBL_MAX; // Inisialisasi dengan nilai maksimum double
    double max_avg_consecutive = DBL_MIN; // Inisialisasi dengan nilai minimum double
    
    int prev_num = 0; // Untuk menyimpan nilai sebelumnya dalam perhitungan rata-rata
    
    // Loop untuk membaca n baris masukan berikutnya
    for (int i = 0; i < n; i++) {
        scanf("%d", &current_num);

        // Update nilai terkecil dan terbesar (Tugas 1)
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Perhitungan rata-rata berurutan (Tugas 2 dan Tugas 3)
        if (i > 0) { // Hanya mulai menghitung rata-rata setelah ada dua angka
            double current_avg = (double)(prev_num + current_num) / 2.0;

            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
        prev_num = current_num; // Simpan angka saat ini sebagai angka sebelumnya untuk iterasi berikutnya
    }

    // Menampilkan hasil keluaran sesuai spesifikasi
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", min_avg_consecutive);
    printf("%.2f\n", max_avg_consecutive);

    return 0;
}
