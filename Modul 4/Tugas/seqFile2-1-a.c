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
    bukuPtr=fopen("tipe1.dat", "rb");
        }else if(tipe == 2){
    bukuPtr=fopen("tipe2.dat", "rb");

        }else{
    bukuPtr=fopen("tipe3.dat", "rb");
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
        bukuPtr1 = fopen("tipe1.dat","ab");
        bukuPtr2 = fopen("tipe2.dat","ab");
        bukuPtr3 = fopen("tipe3.dat","ab");

        if(feof(bukuPtr)){
            printf("File Kosong");
        }else{
            do{
                fread(&dataBuku,sizeof(dataBuku),1, bukuPtr);
                if(!strcmp(dataBuku.jenis,"1")){
                    fwrite(&dataBuku,sizeof(dataBuku),1, bukuPtr1);
                }else if(!strcmp(dataBuku.jenis,"2")){
                    fwrite(&dataBuku,sizeof(dataBuku),1, bukuPtr2);
                }else{
                    fwrite(&dataBuku,sizeof(dataBuku),1, bukuPtr3);
                }
            }while(!feof(bukuPtr));
        }
        fclose(bukuPtr);
        fclose(bukuPtr1);
        fclose(bukuPtr2);
        fclose(bukuPtr3);
    }

    void splitFileHarga(){
        bukuPtr = fopen("dataBuku.dat","rb");
        bukuPtr1 = fopen("harga>=1000.dat","ab");
        bukuPtr2 = fopen("harga<1000.dat","ab");

        if(feof(bukuPtr)){
            printf("File Kosong");
        }else{
            do{
                fread(&dataBuku,sizeof(dataBuku),1, bukuPtr);
                if(dataBuku.harga >= 1000){
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
    printf("3. Split File menjadi 3 Bagian berdasarkan Jenis \n");
    printf("4. Tampilkan data buku bertipe 1 (lakukan step 3 terlebih dahulu)\n");
    printf("5. Tampilkan data buku bertipe 2 (lakukan step 3 terlebih dahulu)\n");
    printf("6. Tampilkan data buku bertipe 3 (lakukan step 3 terlebih dahulu)\n");
    printf("7. Split File menjadi 2 bagian Harga Sewa ≥ Rp. 1.000 dan harga sewa < Rp. 1.000\n");
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
    case 6:
        printData(3);
        break;
    case 7:
        splitFileHarga();
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