#include<stdio.h>
#include "encryption/encryption.h"

int main(){
    char input[100];
    scanf("%s",input);
    char *crypt = encrypt(input);
    char *dcypt = decrypt(crypt);
    printf("%s\n",crypt);
    printf("%s\n",dcypt);
}