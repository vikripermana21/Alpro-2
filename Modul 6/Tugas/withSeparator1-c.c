// Dengan Separator

// Algoritma
/*
- DEFINE STRUCT
- DEFINE variable *filePtr with FILE type
- DEFINE sum, sum_all,separator,leastFav,leastFavCount,mostFav,mostFavCount and current variable

- OPEN FILE

  IF(EOF(FILE))
    PRINT : FILE KOSONG
  ELSE
    READ FILE
    DO
      WHILE(!EOF(FILE) && KEY === SEPARATOR)
        READ FILE
      ENDWHILE
      SUM = 0
      CURRENT = KEY
      WHILE(!EOF(FILE) && KEY !== SEPARATOR)
        SUM += KEY.QTY
        READ FILE
      ENDWHILE
      IF sum <= leastFavCount && CURRENT !== SEPARATOR
        leastFavCount = sum;
        strcpy(leastFav,current);
      ELSE IF sum >= mostFavCount && && CURRENT !== SEPARATOR
        mostFavCount = sum;
        strcpy(mostFav,current);
      ENDIF
      IF CURRENT !== SEPARATOR
        PRINT : JUMLAH PEMINJAMAN ${CURRENT} : ${SUM}
      ENDIF
      SUM_ALL += SUM
    WHILE(!EOF(FILE))
      PRINT : JUMLAH SELURUH PINJAMAN : ${SUM_ALL}
      PRINT : Buku Paling Sedikit Meminjam : ${leastFav}
      PRINT : Buku Paling Banyak Meminjam : ${mostFav}

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
 char Separator[10] = "9999";
 char current [10];
 char leastFav [10];
 char mostFav [10];
 int leastFavCount = 1;
 int mostFavCount = 0;
 Pinjaman = fopen("dataPinjam.dat","rb");

 sum_all = 0;
 if (feof(Pinjaman))
 {
  printf("File Kosong,proses konsolidasi dibatalkan...!!!\n");
 }
 else
 {
  fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
  do{
   while(!feof(Pinjaman) && strcmp(pinjam.kode_buku,Separator)==0)
    {
     fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
    }
   sum = 0;
   strcpy(current, pinjam.kode_buku);
   while(! feof(Pinjaman) && strcmp(pinjam.kode_buku,Separator)!=0)
    {
     sum = sum + pinjam.qty;
     fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
    }
    if(sum <= leastFavCount && strcmp(current,Separator)){
      leastFavCount = sum;
     strcpy(leastFav,current);
    }else if(sum >= mostFavCount && strcmp(current,Separator)){
      mostFavCount = sum;
     strcpy(mostFav,current);
    }
    if(strcmp(current,"9999")){
      printf("jumlah peminjaman %s: %d\n", current, sum);
    }
   sum_all = sum_all + sum;
   if (feof(Pinjaman) && strcmp(pinjam.kode_buku,Separator)==0)
   {
     break;
   }
  }while(!feof(Pinjaman));
  
  printf("===========================================\n");
  printf("Jumlah Seluruh Pinjaman : %d \n", sum_all);
  printf("Buku Paling Sedikit Meminjam : %s \n", leastFav);
  printf("Buku Paling Banyak Meminjam : %s", mostFav);
 }
fclose(Pinjaman);
return 0;
}
