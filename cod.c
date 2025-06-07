#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  printf("Limit: ");
  scanf("%d", &n);
  int a[n+1];
  for(int i = 0; i<n+1; i++){
    a[i] = 1;
  }
  a[0] = 0;
  a[1] = 0;
  for(int i = 2; i*i <= n; i++){
    if(a[i] == 1){
      for(int j = i*i; j <= n; j+=i){
        a[j] = 0;
      }
    }
  }
  printf("Primes: ");
  for(int i = 0; i <= n; i++){
    if(a[i] == 1){
      printf("%d ", i);
    }
  }
  printf("\n");
}