/**
 * 
 * Just a sample of how it is going to work. 
 * May not work now
 * 
**/

#include<string.h>
#include<stdlib.h>
#include "secrets.h"

char* encrypt(char* str){ 
    int i, x;
   

  
  
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; //the key for encryption is 3 that is added to ASCII value
    
  printf("%s\n",str);
    return str;
}

char* decrypt(char* str){
   int i;
   

  
   for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value
  printf("%s\n",str);
      
    return str;
}
