#include <stdio.h>

#define MERAH   "\033[1;31m"
#define HIJAU   "\033[1;32m"
#define KUNING  "\033[1;33m"
#define BIRU    "\033[1;36m"
#define RESET   "\033[0m"

#define JUMLAH_BAHAN 4

// Struct: satu "paket" data untuk satu bahan
struct Bahan {
    char nama[20];
    char satuan[5];
    int stok;        // stok saat ini
    int stokMinimum; // di bawah ini dianggap menipis
    int kapasitas;   // stok maksimal gudang
};

// Parameter bertipe pointer (*) supaya function bisa mengubah data aslinya
void tampilStok(struct Bahan *daftar, int jumlah);
void cekStokMenipis(struct Bahan *daftar, int jumlah);
void isiUlangBahan(struct Bahan *daftar, int jumlah);

int main() {
    // Array of struct: data awal tiap bahan
    struct Bahan gudang[JUMLAH_BAHAN] = {
        {"Kopi", "g",  500, 100, 1000},
        {"Air",  "ml", 5000, 1000, 10000},
        {"Susu", "ml", 800, 300, 3000},
        {"Gula", "ml", 150, 200, 1000}   // sengaja di bawah minimum
    };

    int menu;

    do {
        printf("\n%s=========================================%s\n", KUNING, RESET);
        printf("%s   MODUL 2: MANAJEMEN STOK BAHAN        %s\n", KUNING, RESET);
        printf("%s=========================================%s\n", KUNING, RESET);
        printf("1. Lihat Stok Bahan\n");
        printf("2. Cek Stok Menipis\n");
        printf("3. Isi Ulang Bahan\n");
        printf("0. Keluar\n");
        printf("Pilih menu (0-3): ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                tampilStok(gudang, JUMLAH_BAHAN);
                break;
            case 2:
                cekStokMenipis(gudang, JUMLAH_BAHAN);
                break;
            case 3:
                isiUlangBahan(gudang, JUMLAH_BAHAN);
                break;
            case 0:
                printf("%sTerima kasih! Keluar dari modul 2.%s\n", HIJAU, RESET);
                break;
            default:
                printf("%sPilihan tidak ada! Coba lagi.%s\n", MERAH, RESET);
                break;
        }
    } while (menu != 0);

    return 0;
}

// Menampilkan semua bahan beserta statusnya
void tampilStok(struct Bahan *daftar, int jumlah) {
    int i;

    printf("\n%s--- DAFTAR STOK BAHAN ---%s\n", KUNING, RESET);
    printf("%-3s %-8s %-10s %-8s %s\n", "No", "Bahan", "Stok", "Min", "Status");

    for (i = 0; i < jumlah; i++) {
        struct Bahan *p = &daftar[i];  // p menunjuk ke bahan ke-i

        printf("%-3d %-8s %-4d %-5s %-8d ", i + 1, p->nama, p->stok, p->satuan, p->stokMinimum);

        if (p->stok < p->stokMinimum) {
            printf("%sMENIPIS%s\n", MERAH, RESET);
        } else {
            printf("%sAMAN%s\n", HIJAU, RESET);
        }
    }
}

// Menampilkan hanya bahan yang stoknya di bawah minimum
void cekStokMenipis(struct Bahan *daftar, int jumlah) {
    int i, ada = 0;

    printf("\n%s--- CEK STOK MENIPIS ---%s\n", KUNING, RESET);

    for (i = 0; i < jumlah; i++) {
        struct Bahan *p = &daftar[i];

        if (p->stok < p->stokMinimum) {
            printf("%s[PERINGATAN] %s tinggal %d%s (minimum %d%s)%s\n",
                   MERAH, p->nama, p->stok, p->satuan, p->stokMinimum, p->satuan, RESET);
            ada = 1;
        }
    }

    if (!ada) {
        printf("%sSemua stok bahan masih aman.%s\n", HIJAU, RESET);
    }
}

// Menambah stok bahan pilihan, tidak boleh melebihi kapasitas
void isiUlangBahan(struct Bahan *daftar, int jumlah) {
    int pilih, tambah, ruangKosong;
    struct Bahan *p;

    tampilStok(daftar, jumlah);

    printf("\nPilih bahan yang diisi ulang (1-%d): ", jumlah);
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > jumlah) {
        printf("%s[ERROR] Nomor bahan tidak valid!%s\n", MERAH, RESET);
        return;
    }

    p = &daftar[pilih - 1];
    ruangKosong = p->kapasitas - p->stok;

    printf("Jumlah isi ulang %s (%s), maksimal %d: ", p->nama, p->satuan, ruangKosong);
    scanf("%d", &tambah);

    if (tambah <= 0) {
        printf("%s[ERROR] Jumlah harus lebih dari 0!%s\n", MERAH, RESET);
    } else if (tambah > ruangKosong) {
        printf("%s[GAGAL] Melebihi kapasitas gudang (%d%s)!%s\n", MERAH, p->kapasitas, p->satuan, RESET);
    } else {
        p->stok += tambah;  // mengubah data asli lewat pointer
        printf("%s[SUKSES] Stok %s sekarang %d%s.%s\n", HIJAU, p->nama, p->stok, p->satuan, RESET);
    }
}