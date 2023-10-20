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
    bukuPtr = fopen("dataBuku.dat","ab");
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
    bukuPtr=fopen("stok>=10.dat", "rb");
        }else{
    bukuPtr=fopen("stok<10.dat", "rb");
        }
    printf("| Kode Buku | Jenis | Harga | Stok |\n");
    while(fread(&dataBuku, sizeof(dataBuku),1, bukuPtr)){

    printf("| %s | %s | %d | %d |", dataBuku.kode_buku,dataBuku.jenis,dataBuku.harga,dataBuku.stok);
    printf("\n");
    }
    fclose(bukuPtr);
    }

    void splitFile(){
        bukuPtr = fopen("dataBuku.dat","rb");
        bukuPtr1 = fopen("stok>=10.dat","ab");
        bukuPtr2 = fopen("stok<10.dat","ab");

        if(feof(bukuPtr)){
            printf("File Kosong");
        }else{
            do{
                fread(&dataBuku,sizeof(dataBuku),1, bukuPtr);
                if(dataBuku.stok >= 10){
                    fwrite(&dataBuku,sizeof(dataBuku),1, bukuPtr1);
                }else{
                    fwrite(&dataBuku,sizeof(dataBuku),1, bukuPtr2);
                }
            }while(!feof(bukuPtr));
        }
        fclose(bukuPtr);
        fclose(bukuPtr1);
        fclose(bukuPtr2);
    }

    int main(){
    int pilihMenu = 0;
    while (pilihMenu != 9)
    {
    printf("\nSelamat Datang di Perpustakaan 'Cinta Buku' \n");
    printf("1. Isi data buku \n");
    printf("2. Tampilkan data buku tersedia \n");
    printf("3. Split File menjadi 2 bagian Stok >= 10 dan stok < 10\n");
    printf("4. Tampilkan data buku dengan Stok >= 10 (lakukan step 3 terlebih dahulu)\n");
    printf("5. Tampilkan data buku dengan Stok < 10(lakukan step 3 terlebih dahulu)\n");
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
        splitFile();
        break;
    case 4:
        printData(1);
        break;
    case 5:
        printData(2);
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