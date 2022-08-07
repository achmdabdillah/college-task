#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * makeLower (char * s) {
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

typedef struct transaction {
    char index[10];
    char nama[20];
    char size[20];
    char penyajian[20];
    char harga[100];
} Transaction; 

typedef struct line {
    char line[300];
} Line;

typedef struct column {
    char column[100];
} Column;

bool isIndexValid (int index, Transaction transaction[10]) {
    bool result = false;
    for(int i = 0; i < 11; i++){
        if(strlen(transaction[index].nama) > 0 ){
            result = true;
            break;
        }
    }
    return result;
} 

Transaction assignTransaction (char line[300], Transaction transaction){
    Column column[5];
    int index = 0;
    for(int i = 0; i < strlen(line); i++){
        if(line[i] == ','){
            index++;
            continue;
        }   
        strncat(column[index].column, &line[i], 1); 
    } 
    strcpy(transaction.index    , column[0].column);
    printf("index %s\n", column[0].column);
    strcpy(transaction.nama     , column[1].column);
    strcpy(transaction.size     , column[2].column);
    strcpy(transaction.penyajian, column[3].column);
    strcpy(transaction.harga    , column[4].column);

    for(int j = 0; j < 5; j++) {
        strcpy(column[j].column, "");
    }

    return transaction;
}

void getData(Line line[10], Transaction transaction[10]){
    for(int i = 0; i < 11; i++){
        if(strlen(line[i].line) > 10) transaction[i] = assignTransaction(line[i].line, transaction[i]);
    }
}

void deleteArray(int index, int pilihan, Transaction transaction[10]){
    Transaction deleteTransaction = {"", "", "", ""};

    transaction[pilihan] = transaction[pilihan + 1];
    transaction[pilihan + 1] = deleteTransaction;
    index--;
    if(pilihan <= index){
        deleteArray(index, pilihan + 1, transaction);
    }
}

bool isInputValid(char * input, char * type){
    makeLower(input);
    bool result = false;
    if(strcmp(type,"minuman") == 0){
        if(strcmp(input, "kopi" ) == 0|| strcmp(input, "teh") == 0 || strcmp(input, "coklat") == 0 || strcmp(input, "soda") == 0) result = true;
    }
    else if(strcmp(type, "size") == 0){
        if(strcmp(input, "small") == 0 || strcmp(input, "medium") == 0 || strcmp(input, "largest") == 0) result = true;
    }
    else if(strcmp(type, "penyajian") == 0){
        if(strcmp(input, "dingin") == 0 || strcmp(input, "panas") == 0 || strcmp(input, "hangat") == 0) result = true;
    }

    return result;
}

int main()
{
    Transaction transaction[10];
    FILE * ptr;
    Line line[10];
    char text[5000];
    char ch;
    int menuNo, pilihan, index = 0;
    bool exit = false;
 
    ptr = fopen("dataminuman.txt", "r");
 
    if (NULL == ptr) {
        printf("file didn't exist! \n");
    }
 
    while(ch != EOF){
        ch = fgetc(ptr);
        int valid = ch; 
        if(ch == '\n'){
            index++;
        }
        if(valid > 0) strncat(line[index].line, &ch, 1); 
    }

    getData(line, transaction);

    do{
        printf("============================\n");
        printf("PROGRAM PENCATATAN TRANSAKSI\n");
        printf("\n");
        printf("Pilihan Menu: \n");
        printf("1. Input data\n");
        printf("2. View History\n");
        printf("3. Delete History\n");
        printf("4. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &menuNo);
        if(menuNo == 1) {
            int harga;
            char nama[20], size[20], penyajian[10], pilihan[1]; 
            bool minumValid = false, sizeValid = false, penyajianValid = false , konfirmasi = false, kembaliKeMenu = false;

            if(index == 0){ 
                do{
                    strcpy(transaction[index].nama, "Minuman");
                    strcpy(transaction[index].size, "Size");
                    strcpy(transaction[index].penyajian, "Penyajian");
                    strcpy(transaction[index].harga, "Harga");
                    printf("== Menu Input Data==\n");

                    do{
                        printf("Masukan Nama Minuman: ");
                        scanf("%s", nama);
                        minumValid = isInputValid(nama, "minuman");
                        printf( !minumValid ? "Minuman yang tersedia : Kopi, Teh, Coklat, Soda\n" : "");
                    } while (!minumValid);

                    do{
                        printf("Masukan Size: ");
                        scanf("%s", size);
                        sizeValid = isInputValid(size, "size");
                        printf( !sizeValid ? "Size yang tersedia : Small, Medium, Largest\n" : "");
                    } while (!sizeValid);

                    do{
                        printf("Masukan Penyajian: ");
                        scanf("%s", penyajian);
                        penyajianValid = isInputValid(penyajian, "penyajian");
                        printf( !penyajianValid ? "Penyajian yang tersedia : Dingin, Hangat, Panas\n" : "");
                    } while (!penyajianValid);

                    harga = strlen(nama) * strlen(size) * strlen(penyajian) * 100;

                    printf("\n\nNama Minuman : %s", nama);
                    printf("\nSize : %s", size);
                    printf("\nPenyajian : %s", penyajian);
                    printf("\nKonfirmasi pesanan ? (y/n) ");
                    scanf("%s", pilihan);
                    if(strcmp(pilihan, "y") == 0) {
                        strcpy(transaction[index + 1].nama, nama);
                        strcpy(transaction[index + 1].size, size);
                        strcpy(transaction[index + 1].penyajian, penyajian);
                        sprintf(transaction[index + 1].harga, "%d", harga);
                        printf("data ditambahkan\n");
                        konfirmasi = true;
                        index++;
                    } else {
                        kembaliKeMenu = true;
                    }
                } while (konfirmasi != true && kembaliKeMenu != true);
            }
            else{
                do{
                    printf("== Menu Input Data==\n");
                    do{
                        printf("Masukan Nama Minuman: ");
                        scanf("%s", nama);
                        minumValid = isInputValid(nama, "minuman");
                        printf( !minumValid ? "Minuman yang tersedia : Kopi, Teh, Coklat, Soda\n" : "");
                    } while (!minumValid);

                    do{
                        printf("Masukan Size: ");
                        scanf("%s", size);
                        sizeValid = isInputValid(size, "size");
                        printf( !sizeValid ? "Size yang tersedia : Small, Medium, Largest\n" : "");
                    } while (!sizeValid);

                    do{
                        printf("Masukan Penyajian: ");
                        scanf("%s", penyajian);
                        penyajianValid = isInputValid(penyajian, "penyajian");
                        printf( !penyajianValid ? "Penyajian yang tersedia : Dingin, Hangat, Panas\n" : "");
                    } while (!penyajianValid);

                    harga = strlen(nama) * strlen(size) * strlen(penyajian) * 100; 

                    printf("\n\nNama Minuman : %s", nama);
                    printf("\nSize : %s", size);
                    printf("\nPenyajian : %s", penyajian);
                    printf("\nKonfirmasi pesanan ? (y/n) ");
                    scanf("%s", pilihan);

                    if(strcmp(pilihan, "y") == 0){ 
                        strlen(transaction[index].nama) > 0 ? index++ : index;
                        strcpy(transaction[index].nama, nama);
                        strcpy(transaction[index].size, size);
                        strcpy(transaction[index].penyajian, penyajian); 
                        sprintf(transaction[index].harga, "%d", harga);
                        printf("data ditambahkan\n");
                        konfirmasi = true;
                    } else {
                        kembaliKeMenu = true;
                    }
                } while (konfirmasi != true && kembaliKeMenu != true);
            } 
        }
        else if (menuNo == 2) {
            printf("\n\n== View History==\n");
            printf("--------------------------------------------------------\n");
            printf("|%5s|%10s|%10s|%10s|%10s|\n", "No", "Minuman", "Size", "Penyajian", "Harga");
            printf("--------------------------------------------------------\n");
            for(int i = 1; i < 10; i++){
                if(strlen(transaction[i].nama) > 0){
                    printf("|%5d|%10s|%10s|%10s|%10s|\n", i, transaction[i].nama, transaction[i].size, transaction[i].penyajian, transaction[i].harga);
                }
            }
            printf("--------------------------------------------------------\n");
        }
        else if(menuNo == 3){
            int pilihan;
            bool isValid = false;
            printf("\n\n== Delete History==\n");
            printf("Masukan index: ");
            scanf("%d", &pilihan);

            isValid = isIndexValid(pilihan, transaction);
            if(isValid){
                for(int i = 0; i < index; i++){
                    if(i == pilihan){
                        deleteArray(index, pilihan, transaction);
                    }
                };
                printf("Data Successfully delete..\n");
            } else {
                printf("Tidak ada data dengan index %d!\n", pilihan);
            }
        }
        else if(menuNo == 4){
            char num[10];
            ptr = fopen("dataminuman.txt", "w");
            for(int i = 0; i < 11; i++){

                if(strlen(transaction[i].nama) > 0) {
                    strcat(transaction[i].nama, ",");
                    strcat(transaction[i].size, ",");
                    strcat(transaction[i].penyajian, ",");
                    
                    sprintf(num, "%d,", i);
                    i == 0 ? strcat(text, "No,") : strcat(text, num);
                    
                    strcat(text, transaction[i].nama);
                    strcat(text, transaction[i].size);
                    strcat(text, transaction[i].penyajian);
                    strcat(text, transaction[i].harga);
                    strcat(text, "\n");
                }
            }
            fprintf(ptr,"%s",text);
            exit = true;
            fclose(ptr);
        }
    } while (exit != true);

    return 0;
}
