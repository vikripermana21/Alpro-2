// Dengan Separator

#include <stdio.h>
#include <string.h>
int main ()
{
 struct {char maskapai[10]; int jumlah_penerbangan; char tujuan [50];}flight;
 FILE *PointerFile;
 PointerFile = fopen("flight data.txt","rt");
 fscanf (PointerFile, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
 int sum, sum_all;
 char current [10];

  if (feof(PointerFile))
   {
    printf("File Kosong,proses konsolidasi dibatalkan...!!!\n");
   }
  else
   {
    //fscanf (PointerFile, "%s %d %s\n", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
    sum_all = 0;
    do
     {
      sum = 0;
      strcpy(current, flight.maskapai);

      do
       {
        sum = sum + flight.jumlah_penerbangan;
        fscanf (PointerFile, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
       }while (strcmp(flight.maskapai,current)==0 || !feof(PointerFile) );

       printf("Jumlah Penerbangan Maskapai %s: %d\n", current, sum);
       sum_all = sum_all + sum;

     }while (!feof(PointerFile));
     printf("Jumlah Seluruh Penerbangan : %d", sum_all);
   }

 fclose (PointerFile);
return 0;
}