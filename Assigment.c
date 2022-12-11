#include "stdio.h"
char wantedArr[7]={'w','i','n','h','t','u','t'};
char wantedArr2[17] = {'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};
char tempArr[20];
int wantedArrIndex = 7;
int wantedArrIndex2 = 17;
void findData(int w, char arr[20]);

int main() {
    findData(wantedArrIndex,wantedArr);
    findData(wantedArrIndex2, wantedArr2);
    return 0;
}

void findData(int w, char arr[20]){
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    char c = getc(fptr);
    int i = 0;
    int check = 0;
    while (!feof(fptr)){
        if(c == ' ' || c == '.'){

            for(int x=0; x<w; x++){
                if(arr[x] == tempArr[x] && tempArr[w+1]==0){
                    check +=1;
                    if(check == w){
                        printf("%s\n", arr);
                        check = 0;
                        i=0;
                        for(int a=0; a<20; a++){
                            if(tempArr[a] > 0){
                                tempArr[a] = 0;
                            }else{
                                break;
                            }
                        }
                        break;
                    }

                }else {
                    check = 0;
                    i=0;
                    for(int a=0; a<20; a++){
                        if(tempArr[a] > 0){
                            tempArr[a] = 0;
                        }else{
                            break;
                        }
                    }
                    break;
                }
            }
        }else {
            tempArr[i] = c;
            i++;
        }
        c = getc(fptr);
    }
}