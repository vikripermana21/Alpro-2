// Dengan Separator

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
     sum = sum + pinjam.harga;
     fread(&pinjam, sizeof(pinjam), 1, Pinjaman);
    }
    if(strcmp(current,"9999")){
      printf("jumlah nilai peminjaman %s: %d\n", current, sum);
    }
   sum_all = sum_all + sum;
   if (feof(Pinjaman) && strcmp(pinjam.kode_buku,Separator)==0)
   {
     break;
   }
  }while(!feof(Pinjaman));

  printf("===========================================\n");
  printf("Jumlah Nilai Seluruh Pinjaman : %d", sum_all);
 }
fclose(Pinjaman);
return 0;
}
