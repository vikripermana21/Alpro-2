#include <stdio.h>
#include <string.h>

typedef struct {
   char kode_kendaraan[10];
   char jenis[10];
   int harga;
   int stok;
} kendaraan;
kendaraan dataKendaraan;
FILE *Mhs;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void isiData(){
   Mhs = fopen("dataKendaraan.dat","ab");
   // printf("Stok :");
   // scanf("%s", &dataKendaraan.stok);
   // while(dataKendaraan.stok != 9999){
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
while(!feof(Mhs)){
fread(&dataKendaraan, sizeof(dataKendaraan),1, Mhs);
printf("| %s | %s | %d | %d |", dataKendaraan.kode_kendaraan,dataKendaraan.jenis,dataKendaraan.harga,dataKendaraan.stok);
printf("\n");
}
fclose(Mhs);
}

void onlyTypeA(){
int totalStok=0;

Mhs=fopen("dataKendaraan.dat", "rb");
while(!feof(Mhs) ){
fread(&dataKendaraan, sizeof(dataKendaraan),1, Mhs);
if(!strcmp(dataKendaraan.jenis,"A")){
totalStok++;
}
}
printf("\nTotal Stok Kendaraan Jenis A adalah %d unit\n",totalStok);
fclose(Mhs);
}

void lowestStok(){
   int n=0;
   struct kendaraan stok[10];
   Mhs=fopen("dataKendaraan.dat", "rb");
while(!feof(Mhs) ){
fread(&dataKendaraan, sizeof(dataKendaraan),1, Mhs);
stok[n].kode_kendaraan = dataKendaraan.kode_kendaraan;
stok[n].jenis = dataKendaraan.jenis;
stok[n].harga = dataKendaraan.harga;
stok[n].stok = dataKendaraan.stok;
n++;
}
// bubbleSort(stok,n);s
for (int i = 0; i < n; i++) {
        printf("%s ", stok[i].kode_kendaraan);
    }
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