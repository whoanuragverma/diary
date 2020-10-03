/**
 * 
 * Project structure is going to look something like this.
 * Make sure you have your code defragmented into smaller bits for easier integration and testing. 
 * 
 * 
 **/

#include<stdio.h>
#include "encryption/encryption.h"

int main(){
    char input[100];
    printf("Enter Something:");
    scanf("%s",input);
    char *crypt = encrypt(input);
    char *dcypt = decrypt(crypt);
    printf("Encrypted: %s\n",crypt);
    printf("Decrypted: %s\n",dcypt);
}