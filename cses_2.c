#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);
  long long tot_sum;
  tot_sum = (long long)n*(n+1)/2;
  
  for(int i =0 ; i<n-1; i++){
    long long x;
    scanf("%d", &x);
    tot_sum -= x;
  }
  printf("%d\n", tot_sum);
  return 0;
}