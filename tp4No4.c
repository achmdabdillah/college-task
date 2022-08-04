#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct menu {
    char nama[10];
    char size[10];
    char penyajian[10];
    char harga[20];
} Menu; 

int main()
{
    FILE* ptr;
    char str[50];
    ptr = fopen("test.txt", "a+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    while (fgets(str, 50, ptr) != NULL) {
        printf("%s", str);
    }
 
    fclose(ptr);
    return 0;
}

// bool getIsNimExist (char nim[20], int index, Mahasiswa mhs[10]) {
//     bool result = false;
//     for(int i = 0; i < index; i++){
//         if(strcmp(mhs[i].nim, nim) == 0){
//             result = true;
//             break;
//         }
//     }
//     return result;
// };

// bool isScoreValid (float score) {
//     if(score > 100 || score < 0){
//         return false;
//     }
//     else{
//         return true;
//     }
// } 

// int main(void) { 
    
    // int menuNo, pilihan, index = 0;
    // bool exit = false;
    // bool isNimExist = false;
    // char checkNim[20];
    
    

    // Mahasiswa mhs[10];
    // do {
    //     printf("============================\n");
    //     printf("SISTEM PENILAIAN MATA KULIAH\n");
    //     printf("\n");
    //     printf("Pilihan Menu: \n");
    //     printf("1. Input Data Mahasiswa \n");
    //     printf("2. Input Nilai \n");
    //     printf("3. Lihat Nilai dan Status \n");
    //     printf("4. Exit \n");
    //     printf("Pilihan Anda: ");
    //     scanf("%d", &menuNo);

    //     if(menuNo == 1) {
    //         printf("== Menu Input Data==\n");
    //         if(index <= 0){
    //             printf("Masukan Nim Anda: ");
    //             scanf("%s", mhs[index].nim);

    //         } else {
    //             do {
    //                 printf("Masukan Nim Anda: ");
    //                 scanf("%s", checkNim);
    //                 isNimExist = getIsNimExist(checkNim, index, mhs);
    //                 printf(isNimExist ? "NIM sudah terdaftar!\n" : "");
    //             } while (isNimExist);
    //             strcpy(mhs[index].nim, checkNim);
    //         };
            
    //         printf("Masukan Nama Anda: ");
    //         scanf("%s", mhs[index].nama);
    //         printf("Masukan Mata Kuliah: ");
    //         scanf("%s", mhs[index].matkul);
    //         index++;
    //     }
    //     else if (menuNo == 2) { 
    //         bool scoreValid;
    //         char checkScore[3];
                
    //             do {
    //                 printf("== Menu Input Nilai==\n"); 
    //                 printf("masukan NIM :");
    //                 scanf("%s", checkNim);
    //                 isNimExist = getIsNimExist(checkNim, index, mhs);
    //                 printf(!isNimExist ? "Tidak Ada Data Mahasiswa Dengan NIM %s\n" : "", checkNim);
    //             } while (!isNimExist); 

    //             for(int i = 0; i < index; i++) {
                    
    //                 if(strcmp(mhs[i].nim, checkNim) == 0){
    //                     printf("Input nilai untuk %s\n", mhs[i].nama);
                        
    //                     bool scoreValid;
    //                     char buffer[256];

    //                     do{
    //                         printf("Masukan Nilai hadir : ");
    //                         scanf("%s", buffer);
    //                         mhs[i].nilai.hadir = atof(buffer);
    //                         if(mhs[i].nilai.hadir == 0.00) {
    //                             scoreValid = false;
    //                         } else {
    //                             scoreValid = isScoreValid(mhs[i].nilai.hadir);
    //                         }
    //                         printf(!scoreValid ? "Masukan nilai dari 1-100\n" : ""); 
    //                     } while (!scoreValid);

    //                     do{
    //                         printf("Masukan Nilai tugas : ");
    //                         scanf("%s", buffer);
    //                         mhs[i].nilai.tugas = atof(buffer);
    //                         if(mhs[i].nilai.tugas == 0.00) {
    //                             scoreValid = false;
    //                         } else {
    //                             scoreValid = isScoreValid(mhs[i].nilai.tugas);
    //                         }
    //                         printf(!scoreValid ? "Masukan nilai dari 1-100\n" : ""); 
    //                     } while (!scoreValid);

    //                     do{
    //                         printf("Masukan Nilai quiz : ");
    //                         scanf("%s", buffer);
    //                         mhs[i].nilai.quiz = atof(buffer);
    //                         if(mhs[i].nilai.quiz == 0.00) {
    //                             scoreValid = false;
    //                         } else {
    //                             scoreValid = isScoreValid(mhs[i].nilai.quiz);
    //                         }
    //                         printf(!scoreValid ? "Masukan nilai dari 1-100\n" : ""); 
    //                     } while (!scoreValid);

    //                     do{
    //                         printf("Masukan Nilai keaktifan : ");
    //                         scanf("%s", buffer);
    //                         mhs[i].nilai.keaktifan = atof(buffer);
    //                         if(mhs[i].nilai.keaktifan == 0.00) {
    //                             scoreValid = false;
    //                         } else {
    //                             scoreValid = isScoreValid(mhs[i].nilai.keaktifan);
    //                         }
    //                         printf(!scoreValid ? "Masukan nilai dari 1-100\n" : ""); 
    //                     } while (!scoreValid);

    //                     do{
    //                         printf("Masukan Nilai uas : ");
    //                         scanf("%s", buffer);
    //                         mhs[i].nilai.uas = atof(buffer);
    //                         if(mhs[i].nilai.uas == 0.00) {
    //                             scoreValid = false;
    //                         } else {
    //                             scoreValid = isScoreValid(mhs[i].nilai.uas);
    //                         }
    //                         printf(!scoreValid ? "Masukan nilai dari 1-100\n" : ""); 
    //                     } while (!scoreValid);
    //                 } 
                    
    //                 mhs[i].finalScore = mhs[i].nilai.hadir * 0.10 + mhs[i].nilai.tugas * 0.20 + mhs[i].nilai.quiz * 0.10 + mhs[i].nilai.keaktifan * 0.10 + mhs[i].nilai.uas * 0.50;

    //                 if (mhs[i].finalScore >= 90 && mhs[i].finalScore <= 100) {
    //                     strcpy(mhs[i].grade, "A");
    //                 }
    //                 else if (mhs[i].finalScore >= 80 && mhs[i].finalScore <= 89) {
    //                     strcpy(mhs[i].grade, "B");
    //                 }
    //                 else if (mhs[i].finalScore >= 70 && mhs[i].finalScore <= 79) {
    //                     strcpy(mhs[i].grade, "C");
    //                 }
    //                 else if (mhs[i].finalScore >= 60 && mhs[i].finalScore <= 69) {
    //                     strcpy(mhs[i].grade, "D");
    //                 }
    //                 else if (mhs[i].finalScore >= 50 && mhs[i].finalScore <= 59) {
    //                     strcpy(mhs[i].grade, "E");
    //                 } 
    //                 else {
    //                     strcpy(mhs[i].grade, "NO GRADE");
    //                 }
                    
    //                 if(strcmp(mhs[i].grade, "E") == 0 || strcmp(mhs[i].grade, "NO GRADE") == 0) {
    //                     strcpy(mhs[i].status,"TIDAK LULUS");
    //                 } else {
    //                     strcpy(mhs[i].status,"LULUS");
    //                 }
    //             } 
    //             printf("Nilai Sudah Diinputkan\n");
    //             printf(" \n");
    //             printf(" \n");
    //     }
    //     else if (menuNo == 3) {
    //         printf("\n\n== Lihat Nilai==\n");
    //         printf("Pilihan Menu: \n");
    //         printf("1. Masukan nim \n");
    //         printf("2. Lihat semua nilai \n");
    //         printf("Masukan Pilihan :");
    //         scanf("%d", &pilihan); 

    //         if(pilihan == 1){
    //             printf("masukan NIM :");
    //             scanf("%s", checkNim); 
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //             printf("|%10s|%10s|%20s%10s%24s|%11s|%10s|%11s|%10s|\n", "NIM", "NAMA", "", "NILAI", "", "FINAL SCORE", "GRADE", "STATUS", "MATKUL");
    //             printf("|%21s|%10s|%10s|%10s|%10s|%10s|%45s|\n", "", "Hadir", "Tugas", "Quiz", "Keaktifan", "UAS", "");
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //             for(int i = 0; i < sizeof(mhs) / sizeof(mhs[0]); i++){
    //                 if(strcmp(mhs[i].nim, checkNim) == 0){
    //                     printf("|%10s|%10s|%10.2f|%10.2f|%10.2f|%10.2f|%10.2f|%11.2f|%10s|%11s|%10s|\n", mhs[i].nim, mhs[i].nama ,mhs[i].nilai.hadir, mhs[i].nilai.tugas, mhs[i].nilai.quiz, mhs[i].nilai.keaktifan, mhs[i].nilai.uas, mhs[i].finalScore, mhs[i].grade, mhs[i].status, mhs[i].matkul);
    //                 }
                    
    //             }
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //         } else if(pilihan == 2){
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //             printf("|%10s|%10s|%20s%10s%24s|%11s|%10s|%11s|%10s|\n", "NIM", "NAMA", "", "NILAI", "", "FINAL SCORE", "GRADE", "STATUS", "MATKUL");
    //             printf("|%21s|%10s|%10s|%10s|%10s|%10s|%45s|\n", "", "Hadir", "Tugas", "Quiz", "Keaktifan", "UAS", "");
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //             for(int i = 0; i < sizeof(mhs) / sizeof(mhs[0]); i++){
    //                 if(i >= index){
    //                     break;
    //                 }
    //                 printf("|%10s|%10s|%10.2f|%10.2f|%10.2f|%10.2f|%10.2f|%11.2f|%10s|%11s|%10s|\n", mhs[i].nim, mhs[i].nama ,mhs[i].nilai.hadir, mhs[i].nilai.tugas, mhs[i].nilai.quiz, mhs[i].nilai.keaktifan, mhs[i].nilai.uas, mhs[i].finalScore, mhs[i].grade, mhs[i].status, mhs[i].matkul);
    //             }
    //             printf("---------------------------------------------------------------------------------------------------------------------------\n");
    //         }
            
            
    //     }
    //     else if (menuNo == 4) {
    //         exit = true;
    //     }
    //     else {
    //         printf("Key Yang Anda Masukan Salah, Silahkan Input Kembali\n");
    //     }
    // } while (exit != true);
    
//     return 0;
// }