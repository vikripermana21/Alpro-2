    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct {
    char kode_buku[10];
    char jenis[10];
    int harga;
    int stok;
    } buku;
    buku dataBuku,dataBuku1,dataBuku2,dataBuku3;
    FILE *bukuPtr, *bukuPtr1, *bukuPtr2, *bukuPtr3;

    void isiData(){
    bukuPtr = fopen("dataBuku2.dat","ab");
    printf("Kode buku :");
    scanf("%s", &dataBuku.kode_buku);
    printf("Jenis :");
    scanf("%s", &dataBuku.jenis);
    printf("Harga :");
    scanf("%d", &dataBuku.harga);
    printf("Stok :");
    scanf("%d", &dataBuku.stok);
    fwrite(&dataBuku, sizeof(dataBuku),1, bukuPtr);
    // }
    fclose(bukuPtr);
    }

    void printData(tipe){
        if(tipe == 0){
    bukuPtr=fopen("dataBuku.dat", "rb");
        }else if(tipe == 1){
    bukuPtr=fopen("dataBuku3.dat", "rb");
        }
    printf("| Kode Buku | Jenis | Harga | Stok |\n");
    while(fread(&dataBuku, sizeof(dataBuku),1, bukuPtr)){

    printf("| %s | %s | %d | %d |", dataBuku.kode_buku,dataBuku.jenis,dataBuku.harga,dataBuku.stok);
    printf("\n");
    }
    fclose(bukuPtr);
    }

    void mergeFile(){
        bukuPtr1 = fopen("dataBuku.dat","rb");
        bukuPtr2 = fopen("dataBuku2.dat","rb");
        bukuPtr3 = fopen("dataBuku3.dat","ab");
        
        fread(&dataBuku1,sizeof(dataBuku1),1, bukuPtr1);
        fread(&dataBuku2,sizeof(dataBuku2),1, bukuPtr2);

        while (!feof(bukuPtr1) || !feof(bukuPtr2))
        {
            if(feof(bukuPtr1)){
                fwrite(&dataBuku2,sizeof(dataBuku2),1, bukuPtr3);
                fread(&dataBuku2,sizeof(dataBuku2),1, bukuPtr2);
            }else if(feof(bukuPtr2)){
                fwrite(&dataBuku1,sizeof(dataBuku1),1, bukuPtr3);
                fread(&dataBuku1,sizeof(dataBuku1),1, bukuPtr1);
            }else if(atoi(dataBuku1.kode_buku)<= atoi(dataBuku2.kode_buku)){
                fwrite(&dataBuku1,sizeof(dataBuku1),1, bukuPtr3);
                fread(&dataBuku1,sizeof(dataBuku1),1, bukuPtr1);
            }else{
                fwrite(&dataBuku2,sizeof(dataBuku2),1, bukuPtr3);
                fread(&dataBuku2,sizeof(dataBuku2),1, bukuPtr2);
            }
        }
        
        fclose(bukuPtr1);
        fclose(bukuPtr2);
        fclose(bukuPtr3);
    }

    int main(){
    int pilihMenu = 0;
    while (pilihMenu != 9)
    {
    printf("\nSelamat Datang di Perpustakaan 'Cinta Buku' \n");
    printf("1. Isi data buku \n");
    printf("2. Tampilkan data buku tersedia \n");
    printf("3. Merge kedua file buku menjadi 1\n");
    printf("4. Tampilkan data buku yang sudah digabung (Lakukan step 3 terlebih dahulu)\n");
    printf("9. Exit \n");
    printf("Silahkan pilih menu :");
    scanf("%d",&pilihMenu);
    switch (pilihMenu)
    {
    case 1:
        isiData();
        break;
    case 2:
        printData(0);
        break;
    case 3:
        mergeFile();
        break;
    case 4:
        printData(1);
        break;
    case 9:
        printf("Selamat Tinggal :D");
        break;
    default:
    printf("Pilihan menu tidak ada");
        break;
    }

    }
    
    
    }