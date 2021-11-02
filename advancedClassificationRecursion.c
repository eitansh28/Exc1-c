#include<stdio.h>
#include<stdbool.h>
#include "NumClass.h"
#include<math.h>

int powe(int a,int b){
	int power=1;
	while(b!=0){
		power*=a;
		b--;
	}return power;
}

int f1(int num,int dignum,int ans){
    //we will keep running with recursion with f1 each time adding digit^numberofdigits tp our ans
      if(num>0)
    ans+=(powe(num%10,dignum) +f1(num/10,dignum,ans));
    return ans;
}

  int isArmstrong (int num){
    int x=num;
    int numofdigits =0;
    while(x!=0){
		numofdigits++;
			x=x/10;
}
//we gonna send our num with the number of digits of our num to ceck every digit^numofdigits
//if it will be equal or our original num its an armstrong number
    if (num==f1(num,numofdigits,0)){
    return 1;
  }else{
    return 0;
  }
}



  int f2(int x,int sum){
	//	static int sum=0;
    //the function will save sum and run in recursion to find reversed x
      if(x!=0){
          sum = f2(x/10,sum*10 + (x%10));
      }
      return sum;
  }


  int isPalindrome(int x){
    //we will check our x against afunction that check our x in reverse if they equal its aplindrome
    if (x==f2(x,0))
      return 1;
    else
      return 0;
  }
