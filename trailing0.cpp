#include<iostream>
#include<cmath>
using namespace std;
int main(){
  long int n;
  cin>> n;
  long int ans = 0;
  int i = floor(log2(n)/log2(5));
  for(int j = 1; j <= i; j++){
   ans = ans + (n/pow(5, j));
  }
  cout << ans << endl;
  return 0;
}