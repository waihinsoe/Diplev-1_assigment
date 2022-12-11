#include "stdio.h"
#include "stdlib.h"
void generateChar();
void counting();
void dataPrinting();
int biggestElement();
//void dataPrintingASCII();
void dataAddingToFile();
int charArray[26];
int main() {

    generateChar();
    counting();
    dataPrinting();
    int index = biggestElement();
    printf("index : %d\n", index);
//    dataPrintingASCII();
    dataAddingToFile();

    return 0;
}

void generateChar() {

    FILE *fptr;
    fptr = fopen("test.txt", "w");
    fclose(fptr);

    FILE *fptr1;
    fptr1 = fopen("test.txt", "a");
    if(fptr1==NULL){
        printf("File cannot open!!");
    }else {
        srand(time(NULL));
        int i = 0;
        while (i < 500){
            int data = rand()%123;
            if(data > 96){
                fprintf(fptr1,"%c",data);
                i++;
            }
        }
        fclose(fptr1);
    }


}

void counting(){
    FILE *fptr;
    fptr = fopen("test.txt", "r");

    if(fptr == NULL){
        printf("File cannot open");
    }else {
        char c = getc(fptr);
        while (!feof(fptr)){

            printf("data  : %d\n", c);
            int index = c - 97;
            charArray[index] = charArray[index]+ 1;
            printf("index : %d\n", index);
            c = getc(fptr);
        }
        fclose(fptr);
    }

}

void dataPrinting(){
    FILE *fptr;
    fptr = fopen("test.txt","r");
    if(fptr ==NULL){
        printf("File cannot open !");
    }else{
        int i = 0;
        int index = 0;
        for(i = 97; i < 123; i++,index++){
            printf("data from array %c  : %d\n", i,charArray[index]);
        }
    }
}

int biggestElement() {

    int temp = 0;
    for(int i=0; i < 26; i++) {
        if(charArray[i] > temp){
            temp = charArray[i];
        }

    }
    return temp;
}

void dataPrintingASCII() {
    int index = biggestElement();
    for(int x = 0; x< index; x++){
        for(int y = 0; y < 26; y++){
            if(charArray[y]>=0){
                printf("%c  ", y+97);
                charArray[y]--;
            }else{
                printf("%c%c%c", ' ', ' ', ' ');
            }
        }
        printf("\n");
    }

}

void dataAddingToFile(){

    FILE *fptr;
    fptr = fopen("charArray.txt", "w");
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("charArray.txt", "a");

    int index = biggestElement();
    for(int x = 0; x< index; x++){
        for(int y = 0; y < 26; y++){
            if(charArray[y]>=0){
                fprintf(fptr2,"%c  ", y+97);
                charArray[y]--;
            }else{
                fprintf(fptr2,"%c%c%c", ' ', ' ', ' ');
            }
        }
        fprintf(fptr2,"%c", '\n');
    }
    fclose(fptr2);

}