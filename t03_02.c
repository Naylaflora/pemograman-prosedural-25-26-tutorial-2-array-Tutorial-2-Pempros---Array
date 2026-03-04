#include <stdio.h>
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN
#include <float.h>  // Diperlukan untuk DBL_MAX

int main() {
    int n;

    // Membaca jumlah baris masukan berikutnya (n)
    scanf("%d", &n);

    // Array untuk menyimpan n bilangan bulat
    // Alokasi dinamis atau VLA (Variable Length Array)
    // VLA didukung di C99, namun mungkin tidak di semua compiler C++.
    // Untuk kompabilitas maksimal, bisa menggunakan alokasi dinamis (malloc).
    // Karena ini project C sederhana dan biasanya GCC mendukung VLA, kita gunakan VLA.
    int numbers[n]; 

    int min_val = INT_MAX; // Inisialisasi nilai terkecil dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai terbesar dengan nilai integer minimum

    // Membaca n baris masukan berikutnya dan mencari nilai terkecil serta terbesar
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    double min_avg_pair = DBL_MAX; // Inisialisasi rata-rata pasangan terendah dengan nilai double maksimum

    // Menghitung rata-rata terendah dari setiap pasangan nilai berturut-turut
    // Perhitungan hanya dilakukan jika ada setidaknya 2 angka untuk membentuk pasangan
    if (n >= 2) {
        for (int i = 0; i < n - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            if (current_avg < min_avg_pair) {
                min_avg_pair = current_avg;
            }
        }
    }

    // Menampilkan hasil sesuai spesifikasi Tugas 2
    printf("%d\n", min_val); // Nilai terkecil
    printf("%d\n", max_val); // Nilai terbesar

    // Menampilkan rata-rata pasangan terendah.
    // Jika n < 2, tidak ada pasangan, maka output 0.00 sebagai penanda tidak ada rata-rata yang dapat dihitung.
    if (n >= 2) {
        printf("%.2f\n", min_avg_pair); // Rata-rata terendah dengan 2 digit presisi
    } else {
        printf("0.00\n"); // Placeholder jika tidak ada pasangan
    }

    return 0; // Mengakhiri program dengan sukses
}
