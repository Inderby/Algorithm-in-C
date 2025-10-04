#include <stdio.h>

void failure(int size, char * pattern, char * fail){
    int i = 1;
    int len = 0;
    fail[0] = 0;

    while(i < size){
        if(pattern[i] == pattern[len]){
            len++;
            fail[i] = len;
            i++;
        }else{
            if(len != 0){
                len = fail[len - 1];
            }else{
                fail[i] = 0;
                i++;
            }
        }
    }
}

int main(){

    char text[1000];
    char pattern[100];

    int text_size = 0;
    int pattern_size = 0;
    int find = 0;
    while(text[text_size] != '\0') text_size++;
    while(pattern[pattern_size] != '\0') pattern_size++;

    int fail[pattern_size];
    failure(pattern_size, pattern, fail);

    int i = 0;
    int j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            find = 1;
            j = fail[j - 1];
        }else if(i < text_size && text[i] != pattern[j]){
            if(j != 0){
                j = fail[j - 1];
            }else{
                i++;
            }
        }
    }

    if(find){
        printf("find");
    }
    return 0;
}