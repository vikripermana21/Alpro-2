// Dengan Separator

// Algoritma
/*
- DEFINE STRUCT
- DEFINE variable *filePtr with FILE type
- DEFINE sum, sum_all and current variable

- OPEN FILE

  IF(EOF(FILE))
    PRINT : FILE KOSONG
  ELSE
    READ FILE
    CURRENT = KEY
    DO
      SUM = 0
      WHILE(!EOF(FILE) && current === KEY)
        SUM += KEY.QTY
        SUM_ALL += KEY.QTY
        READ FILE
      ENDWHILE
      PRINT : JUMLAH PEMINJAMAN ${CURRENT} : ${SUM}
      WHILE(!EOF(FILE) && current !== KEY)
        current = KEY
      ENDWHILE
    WHILE(!EOF(FILE))
      PRINT : JUMLAH SELURUH PINJAMAN : ${SUM_ALL}

    FILE CLOSE
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
 struct {char kode_buku[10]; int qty; int harga;} pinjam;
 FILE *Pinjaman;
 int sum, sum_all;
 char current [10];
 Pinjaman = fopen("dataPinjam2.dat","rb");

 sum_all = 0;
 if (feof(Pinjaman))
 {
  printf("File Kosong,proses konsolidasi dibatalkan...!!!\n");
 }
 else
 {
  fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
  strcpy(current, pinjam.kode_buku);
  do{
    sum = 0;
    while (!feof(Pinjaman) && !strcmp(current,pinjam.kode_buku))
    { 
     sum += pinjam.qty;
     sum_all += pinjam.qty;
     fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
    }
    printf("jumlah peminjaman %s : %d\n", current,sum);
    while (!feof(Pinjaman) && strcmp(current,pinjam.kode_buku)){
      strcpy(current,pinjam.kode_buku);
    }
    
  }while(!feof(Pinjaman));
  
  printf("===========================================\n");
  printf("Jumlah Seluruh Pinjaman : %d", sum_all);
 }
fclose(Pinjaman);
return 0;
}
