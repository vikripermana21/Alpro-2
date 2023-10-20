#include <stdio.h>

typedef struct{
long nim;
char nama[25];
float ip;
} datamhs;
datamhs RekMhs1, RekMhs2, RekMhs3;
FILE *Mhs1, *Mhs2, *Mhs3;

int main(){
Mhs1=fopen("mhs1.dat", "rb");
Mhs2=fopen("mhs2.dat", "rb");
Mhs3=fopen("mhs3.dat", "wb");
while(!feof(Mhs1)){
fread(&RekMhs1,
sizeof(RekMhs1), 1, Mhs1);
fwrite(&RekMhs1,
sizeof(RekMhs1), 1, Mhs3);
}
while(!feof(Mhs2)){
fread(&RekMhs2,
sizeof(RekMhs2), 1, Mhs2);
fwrite(&RekMhs2,
sizeof(RekMhs2), 1, Mhs3);
}
fclose(Mhs1);
fclose(Mhs2);
fclose(Mhs3);

return 0;
}