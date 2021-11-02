#include<stdio.h>
#include<stdbool.h>
#include <math.h>
#include "NumClass.h"

int powe(int a,int b){
	int power=1;
	while(b!=0){
		power*=a;
		b--;
	}return power;
}

int isArmstrong(int x){
int count=0;
int n=x;
int v=x;
int sum=0;
	while(x!=0){
		count++;
			x=x/10;
}
	while(n!=0){
		sum+=(powe((n%10),count));
			n=n/10;
}
	if(sum==v){
  		return 1;
		}else{
			return 0;
}
}

int isPalindrome(int x){
	//we will save our original number,rev going to be our original but reversed
	//and sheherit is a variable that going to hold our "sheherit" each time we divide by 10
    int orig =x;
    int sheherit =0;
    int rev =0;
	//we will keep dividing our original by 10 and add sheherit until there wont anything left to add
    while (x!=0){
      sheherit = x % 10;
      rev= rev*10+sheherit;
      x/=10;
    }
	// if rev equal our original number it is a palindrome
    if (orig==rev)
    return 1;
    else
    return 0;
  }
