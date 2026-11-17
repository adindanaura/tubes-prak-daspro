#include <stdio.h>

void tampilkanTampilanAwal(int stokAir, int stokKopi, int stokSusu,
                           int tingkatKotor) {
  printf("\n====================================================\n");
  printf("       COFFEE MAKER SIMULATOR - MESIN OTOMATIS      \n");
  printf("====================================================\n");
  printf(" [STATUS BAHAN BAKU SAAT INI]\n");
  printf("  * Air        : %d ml\n", stokAir);
  printf("  * Kopi       : %d gram\n", stokKopi);
  printf("  * Susu       : %d ml\n", stokSusu);
  printf("  * Kebersihan : %d/5 ", tingkatKotor);

  if (tingkatKotor >= 5) {
    printf("(LOCKDOWN - PERLU DICUCI!)\n");
  } else {
    printf("(SIAP OPERASI)\n");
  }
  printf("----------------------------------------------------\n");
}