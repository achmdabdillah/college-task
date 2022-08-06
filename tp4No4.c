#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct transaction {
    char nama[10];
    char size[10];
    char penyajian[10];
    char harga[20];
} Transaction; 

typedef struct line {
    char line[300];
} Line;

typedef struct column {
    char column[300];
} Column;

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
    for(int i = 1; i <= 10; i++){
        if(strlen(line[i].line) > 10) transaction[i] = assignTransaction(line[i].line, transaction[i]);
    }
}

int main()
{
    Transaction transaction[10];
    FILE * ptr;
    Line line[10];
    char test[3000];
    char ch;
    int menuNo, pilihan, index = 0;
    bool exit = false;
 
    ptr = fopen("test.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
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

    fclose(ptr);

    do{
        printf("============================\n");
        printf("SISTEM PENILAIAN MATA KULIAH\n");
        printf("\n");
        printf("Pilihan Menu: \n");
        printf("1. Input data\n");
        printf("2. View History\n");
        printf("3. Delete History\n");
        printf("4. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &menuNo);
        if(menuNo == 1) {
            index++;
            printf("== Menu Input Data==\n");
            printf("Masukan Nama Minuman: ");
            scanf("%s", transaction[index].nama);
            printf("Masukan Size: ");
            scanf("%s", transaction[index].size);
            printf("Masukan Penyajian: ");
            scanf("%s", transaction[index].penyajian);
            printf("%s", transaction[1].nama);
            printf("%s", transaction[2].nama);
            printf("%s", transaction[3].nama);
        }
    } while (exit != true);

    return 0;
}
