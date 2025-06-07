#include <stdio.h>
#include <stdlib.h>

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i<t; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    int min, max;
    if(a<b){
      min = a;
      max = b;
    }else{
      min = b;
      max = a;
    }
    int sum = a + b;
    if(sum%3 ==0 && min*2 >= max){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}