#include <stdio.h>
#include <string.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"  
#define COLOR_GREEN   "\033[1;32m"  
#define COLOR_YELLOW  "\033[1;33m"  
#define COLOR_BLUE    "\033[1;34m" 
#define COLOR_MAGENTA "\033[1;35m"  
#define COLOR_CYAN    "\033[1;36m"  

void prosesSeduh(char namaKopi[], int gula);
void buatKopiStandar();
void buatCustomBlend();

void prosesSeduh(char namaKopi[], int gula) {
    printf("\n%s========================================%s\n", COLOR_CYAN, COLOR_RESET);
    printf("    %sPROSES PEMBUATAN: %s%s\n", COLOR_YELLOW, namaKopi, COLOR_RESET);
    printf("%s========================================%s\n", COLOR_CYAN, COLOR_RESET);

    for (int step = 1; step <= 4; step++) {
        if (step == 1) {
            printf("%s[1/4]%s Menggiling biji kopi pilihan...\n", COLOR_BLUE, COLOR_RESET);
        } else if (step == 2) {
            printf("%s[2/4]%s Memanaskan air ke suhu optimal...\n", COLOR_BLUE, COLOR_RESET);
        } else if (step == 3) {
            printf("%s[3/4]%s Extraction process (ekstraksi kopi)...\n", COLOR_BLUE, COLOR_RESET);
        } else if (step == 4) {
            if (gula == 0) {
                printf("%s[4/4]%s Tanpa penambahan gula (0%% - Black Coffee)...\n", COLOR_BLUE, COLOR_RESET);
            } else {
                printf("%s[4/4]%s Menambahkan takaran gula (%d%%)...\n", COLOR_BLUE, COLOR_RESET, gula);
            }
        }
    }

    printf("\n%s>>> SUCCESS! Kopi %s kamu siap dinikmati! <<<%s\n\n", COLOR_GREEN, namaKopi, COLOR_RESET);
}

void buatKopiStandar() {
    int pilihanMenu, levelGula;
    char namaKopi[30];

    printf("\n%s--- SMART COFFEE MAKER MENU ---%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("1. Americano\n");
    printf("2. Espresso\n");
    printf("3. Cafe Latte\n");
    printf("4. Caramel Macchiato\n");
    printf("5. Dirty Matcha\n");
    printf("Pilih Kopi (1-5): ");
    scanf("%d", &pilihanMenu);

    if (pilihanMenu == 1) {
        strcpy(namaKopi, "Americano");
    } else if (pilihanMenu == 2) {
        strcpy(namaKopi, "Espresso");
    } else if (pilihanMenu == 3) {
        strcpy(namaKopi, "Cafe Latte");
    } else if (pilihanMenu == 4) {
        strcpy(namaKopi, "Caramel Macchiato");
    } else if (pilihanMenu == 5) {
        strcpy(namaKopi, "Dirty Matcha");
    } else {
        printf("%sPilihan menu tidak valid!%s\n\n", COLOR_RED, COLOR_RESET);
        return;
    }

    printf("\nPilih Level Gula:\n");
    printf("0. 0%%   (No Sugar)\n");
    printf("1. 25%%  (Less Sugar)\n");
    printf("2. 50%%  (Normal Sugar)\n");
    printf("3. 100%% (Extra Sugar)\n");
    printf("Pilih Level Gula (0-3): ");
    int pilGula;
    scanf("%d", &pilGula);

    if (pilGula == 0) {
        levelGula = 0;
    } else if (pilGula == 1) {
        levelGula = 25;
    } else if (pilGula == 2) {
        levelGula = 50;
    } else if (pilGula == 3) {
        levelGula = 100;
    } else {
        printf("%sPilihan gula tidak valid! Pembuatan dibatalkan.%s\n\n", COLOR_RED, COLOR_RESET);
        return; 
    }

    prosesSeduh(namaKopi, levelGula);
}

void buatCustomBlend() {
    int gramKopi, mlAir, mlSusu, levelGula;
    char namaCustom[40] = "Custom Blend";

    printf("\n%s--- RACIK KOPI CUSTOM BLEND ---%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("Masukkan takaran Kopi (gram) [0 - 40]: ");
    scanf("%d", &gramKopi);

    printf("Masukkan takaran Air (ml)    [0 - 250]: ");
    scanf("%d", &mlAir);

    printf("Masukkan takaran Susu (ml)   [0 - 150]: ");
    scanf("%d", &mlSusu);

    printf("Masukkan level Gula (%%)      [0 - 100]: ");
    scanf("%d", &levelGula);

    printf("\n%s========================================%s\n", COLOR_MAGENTA, COLOR_RESET);
    printf("     %sHASIL ANALISIS & EVALUASI RACIKAN%s     \n", COLOR_YELLOW, COLOR_RESET);
    printf("%s========================================%s\n", COLOR_MAGENTA, COLOR_RESET);

    printf("1. Bahan Cair & Kopi : ");
    if (gramKopi < 0 || gramKopi > 40 || mlAir < 0 || mlAir > 250 || mlSusu < 0 || mlSusu > 150) {
        printf("%s[INPUT INVALID] Nilai minus atau melebihi kapasitas wadah!%s\n", COLOR_RED, COLOR_RESET);
    } else if (gramKopi == 0 || mlAir == 0) {
        printf("%s[BAHAN TIDAK VALID] Kopi atau air tidak boleh 0!%s\n", COLOR_RED, COLOR_RESET);
    } else if (mlAir < (gramKopi * 3)) {
        printf("%s[TERLALU PEKAT] Air terlalu sedikit, ekstraksi tersumbat!%s\n", COLOR_RED, COLOR_RESET);
    } else if (gramKopi > 25) {
        printf("%s[EXTRA STRONG] Rasa kopi sangat pahit dan pekat.%s\n", COLOR_YELLOW, COLOR_RESET);
    } else if (mlAir > 200 && gramKopi < 12) {
        printf("%s[WATERY] Kopi terlalu encer karena air kebanyakan.%s\n", COLOR_YELLOW, COLOR_RESET);
    } else {
        printf("%s[PAS] Perbandingan air dan kopi sudah ideal.%s\n", COLOR_GREEN, COLOR_RESET);
    }

    printf("2. Kadar Gula        : ");
    if (levelGula < 0 || levelGula > 100) {
        printf("%s[INPUT INVALID] Level gula harus di antara 0%% - 100%%!%s\n", COLOR_RED, COLOR_RESET);
    } else if (levelGula > 90) {
        printf("%s[SIRUP GULA] Gula %d%% terlalu ekstrem! Ini sirup, bukan kopi.%s\n", COLOR_RED, levelGula, COLOR_RESET);
    } else if (levelGula > 60) {
        printf("%s[TERLALU MANIS] Gula %d%% mendominasi rasa asli kopi.%s\n", COLOR_YELLOW, levelGula, COLOR_RESET);
    } else if (levelGula == 0) {
        printf("%s[NO SUGAR] Kopi murni tanpa gula (Pahit Alami).%s\n", COLOR_CYAN, COLOR_RESET);
    } else {
        printf("%s[PAS] Takaran gula %d%% manisnya seimbang.%s\n", COLOR_GREEN, levelGula, COLOR_RESET);
    }

    printf("3. Status Akhir      : ");
    int statusBerhasil = 1;

    if (gramKopi < 0 || gramKopi > 40 || mlAir < 0 || mlAir > 250 || mlSusu < 0 || mlSusu > 150 || levelGula < 0 || levelGula > 100) {
        printf("%s[KOPI GAGAL] Input bernilai negatif atau melebihi batas maksimal!%s\n", COLOR_RED, COLOR_RESET);
        statusBerhasil = 0;
    } else if (gramKopi == 0 || mlAir == 0 || mlAir < (gramKopi * 3)) {
        printf("%s[KOPI GAGAL] Rasio air & kopi tidak memungkinkan diseduh!%s\n", COLOR_RED, COLOR_RESET);
        statusBerhasil = 0;
    } else if (levelGula > 90) {
        printf("%s[KOPI GAGAL] Kebanyakan gula, mesin menolak seduh sirup!%s\n", COLOR_RED, COLOR_RESET);
        statusBerhasil = 0;
    } else if (gramKopi >= 12 && gramKopi <= 20 && mlAir >= 120 && mlAir <= 180 && levelGula >= 20 && levelGula <= 50) {
        printf("%s[PERFECT BLEND] Golden Ratio Kopi, Air, dan Gula!%s\n", COLOR_GREEN, COLOR_RESET);
    } else {
        printf("%s[LAYAK MINUM] Racikan siap diproses.%s\n", COLOR_CYAN, COLOR_RESET);
    }

    printf("%s----------------------------------------%s\n", COLOR_MAGENTA, COLOR_RESET);

    if (statusBerhasil == 1) {
        prosesSeduh(namaCustom, levelGula);
    } else {
        printf("\n%s[PROSES DIBATALKAN] Silakan coba atur ulang takaran kamu.%s\n\n", COLOR_RED, COLOR_RESET);
    }
}

int main() {
    int pilihanUtama;
    int jalan = 1;

    while (jalan == 1) {
        printf("%s=========================================%s\n", COLOR_CYAN, COLOR_RESET);
        printf("     %sSMART COFFEE MAKER - MENU UTAMA%s     \n", COLOR_YELLOW, COLOR_RESET);
        printf("%s=========================================%s\n", COLOR_CYAN, COLOR_RESET);
        printf("1. Pesan Kopi Standar\n");
        printf("2. Racik Custom Blend Sendiri\n");
        printf("3. Keluar\n");
        printf("Pilih Menu (1-3): ");
        scanf("%d", &pilihanUtama);

        switch (pilihanUtama) {
            case 1:
                buatKopiStandar();
                break;
            case 2:
                buatCustomBlend();
                break;
            case 3:
                printf("\n%sTerima kasih telah menggunakan Smart Coffee Maker!%s\n", COLOR_GREEN, COLOR_RESET);
                jalan = 0;
                break;
            default:
                printf("\n%sMenu tidak tersedia! Silakan masukan angka 1-3.%s\n\n", COLOR_RED, COLOR_RESET);
        }
    }

    return 0;
}