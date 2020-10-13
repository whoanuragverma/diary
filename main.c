/**
 * 
 * Project structure is going to look something like this.
 * Make sure you have your code defragmented into smaller bits for easier integration and testing. 
 * 
 * 
 **/

#include<stdio.h>
#include<stdlib.h>
#include "auth/auth.h"


int main(){
    if(isUserAvailable() == 0) signup();
    else flogin();
    //diary
}