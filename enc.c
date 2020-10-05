#include <stdio.h> 
#include <string.h> 
  

void encrypt(char input[100]) 
{ 
  
   
    char evenPos = '@', oddPos = '!'; 
  
    int repeat, ascii; 
  
    for (int i = 0; i <= strlen(input); i++) { 
  
       
        ascii = input[i]; 
        repeat = ascii >= 97 ? ascii - 96 : ascii - 64; 
  
        for (int j = 0; j < repeat; j++) { 
           
            if (i % 2 == 0) 
                printf("%c", oddPos); 
            else
                printf("%c", evenPos); //check
        } //push check
    } 
} 
  

void main() 
{ 
    char input[100] ;
    scanf("%s",&input); 
  
  
    encrypt(input); 
} 