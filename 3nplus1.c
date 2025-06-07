#include<stdio.h>
#include<stdlib.h>

int main(){
  long int n;
  scanf("%ld", &n);
  while(n != 1){
    printf("%ld ", n);
    if(n%2 == 0){
      n= n/2;
    }else{
      n = 3*n+1;
    }
  }
  printf("%ld", n); // Print the final value of n, which should be 1
  return 0;
}