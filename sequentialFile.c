#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   char kode_kendaraan[10];
   char jenis[10];
   int harga;
   int stok;
} kendaraan;
kendaraan dataKendaraan;
FILE *Mhs;

void bubble_sort(kendaraan *data, int n) {
  int i, j;
  kendaraan temp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (data[j].stok > data[j + 1].stok) {
        temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

void lowestStok() {
  int n;
  kendaraan *dataKendaraanPtr;
  bubble_sort(&dataKendaraan, n);
dataKendaraanPtr = &dataKendaraan;

  printf("Data stok terendah adalah : \n");
  printf("| Kode Kendaraan | Jenis | Harga | Stok |\n");
 printf("| %s | %s | %d | %d | \n", dataKendaraanPtr->kode_kendaraan,
              dataKendaraanPtr->jenis, dataKendaraanPtr->harga,
              dataKendaraanPtr->stok);
}

void isiData(){
   Mhs = fopen("dataKendaraan.dat","ab");
   printf("Kode Kendaraan :");
   scanf("%s", &dataKendaraan.kode_kendaraan);
   printf("Jenis :");
   scanf("%s", &dataKendaraan.jenis);
   printf("Harga :");
   scanf("%d", &dataKendaraan.harga);
   printf("Stok :");
   scanf("%d", &dataKendaraan.stok);
   fwrite(&dataKendaraan, sizeof(dataKendaraan),1, Mhs);
// }
fclose(Mhs);
}

void printData(){
   Mhs=fopen("dataKendaraan.dat", "rb");
printf("| Kode Kendaraan | Jenis | Harga | Stok |\n");
while(fread(&dataKendaraan, sizeof(dataKendaraan),1, Mhs)){

printf("| %s | %s | %d | %d |", dataKendaraan.kode_kendaraan,dataKendaraan.jenis,dataKendaraan.harga,dataKendaraan.stok);
printf("\n");
}
fclose(Mhs);
}

void onlyTypeA(){
int totalStok=0;

Mhs=fopen("dataKendaraan.dat", "rb");
while(fread(&dataKendaraan, sizeof(dataKendaraan),1, Mhs)){
if(!strcmp(dataKendaraan.jenis,"A")){
totalStok += dataKendaraan.stok;
}
}
printf("\nTotal Stok Kendaraan Jenis A adalah %d unit\n",totalStok);
fclose(Mhs);
}

int main(){
   int pilihMenu = 0;
   while (pilihMenu != 5)
   {
   printf("\nSelamat Datang di Rental Mobil 'Pantang Mundur' \n");
   printf("1. Isi data mobil \n");
   printf("2. Tampilkan data mobil tersedia \n");
   printf("3. Tampilkan stok data mobil yang berjenis A \n");
   printf("4. Tampilkan stok data mobil terendah \n");
   printf("5. Exit \n");
   printf("Silahkan pilih menu :");
   scanf("%d",&pilihMenu);
   switch (pilihMenu)
   {
   case 1:
      isiData();
      break;
   case 2:
      printData();
      break;
   case 3:
      onlyTypeA();
      break;
   case 4:
      printData();
      lowestStok();
      break;
   case 5:
      printf("Selamat Tinggal :D");
      break;
   default:
   printf("Pilihan menu tidak ada");
      break;
   }

   }
   
   
}