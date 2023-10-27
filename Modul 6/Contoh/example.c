    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct {
    char kode_buku[10];
    int qty;
    int harga;
    } buku;
    buku dataPinjam;
    FILE *bukuPtr;

    void isiData(){
    bukuPtr = fopen("dataPinjam2.dat","ab");
    printf("Kode buku :");
    scanf("%s", &dataPinjam.kode_buku);
    printf("Qty :");
    scanf("%d", &dataPinjam.qty);
    printf("Harga :");
    scanf("%d", &dataPinjam.harga);
    fwrite(&dataPinjam, sizeof(dataPinjam),1, bukuPtr);
    // }
    fclose(bukuPtr);
    }

    void printData(){
    bukuPtr=fopen("dataPinjam2.dat", "rb");
    printf("| Kode Buku | Qty | Harga |\n");
    while(fread(&dataPinjam, sizeof(dataPinjam),1, bukuPtr)){

    printf("| %s | %d | %d |", dataPinjam.kode_buku,dataPinjam.qty,dataPinjam.harga);
    printf("\n");
    }
    fclose(bukuPtr);
    }

    int main(){
    int pilihMenu = 0;
    while (pilihMenu != 9)
    {
    printf("\nSelamat Datang di Perpustakaan 'Cinta Buku' \n");
    printf("1. Isi data buku \n");
    printf("2. Tampilkan data buku tersedia \n");
    printf("9. Exit \n");
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
    case 9:
        printf("Selamat Tinggal :D");
        break;
    default:
    printf("Pilihan menu tidak ada");
        break;
    }

    }
    
    
    }