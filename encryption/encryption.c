#include<string.h>
#include<stdlib.h>

char* encrypt(char* input){
    int len = strlen(input);
    char *output = (char*)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++)
        output[i] = input[i] + 3;
    output[i] = '\0';
    return output;
}

char* decrypt(char* input){
    int len = strlen(input);
    char *output = (char*)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++)
        output[i] = input[i] - 3;
    output[i] = '\0';
    return output;
}
