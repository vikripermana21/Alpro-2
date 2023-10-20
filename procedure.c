#include <stdio.h>

typedef struct {
   long nim;
   char nama[25];
   float ip;
} datamhs;
datamhs Msiswa;
FILE *Mhs;

void isiData(){
   Mhs = fopen("data.dat","wb");
   printf("NIM :");
   scanf("%ld", &Msiswa.nim);
   while(Msiswa.nim != 9999){
   printf("Nama :");
   scanf("%s", &Msiswa.nama);
   printf("IP :");
   scanf("%f", &Msiswa.ip);
   fwrite(&Msiswa, sizeof(Msiswa),1, Mhs);
   printf("NIM :");
   scanf("%ld", &Msiswa.nim);
}
fclose(Mhs);
}

void printData(){
   Mhs=fopen("data.dat", "rb");
while(!feof(Mhs)){
fread(&Msiswa, sizeof(Msiswa),
1, Mhs);
printf("NIM :%ld", Msiswa.nim);
printf(" Nama :%s",
Msiswa.nama);
printf(" IP :%f", Msiswa.ip);
printf("\n");
}
fclose(Mhs);
}

int main(){
   isiData();
   printData();
}