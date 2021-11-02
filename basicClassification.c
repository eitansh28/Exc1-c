#include<stdio.h>
#include<stdbool.h>
#include "NumClass.h"

int isPrime(int x){
  for (size_t i = 2; i <= (x/2); i++) {
    if(x%i == 0)
    return 0;
  }return 1;
}

int fact(int x){
  int dub=1;
  for (size_t i = 1; i <=x; i++) {
    dub*=i;
  }return dub;
}

int isStrong(int x){
int sum=0;
int n=x;
  while(x!=0){
  	int f=(x%10);
    sum+=fact(f);
  	x=x/10;
  }if(sum==n)
  return 1;
  return 0;
  }
  
