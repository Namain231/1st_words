#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
/*
const long long MOD = 1e9 + 7;
long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long modinv(long long q) {
    return modpow(q, MOD - 2);
}*/
long double prob(long double i){
}
int main(){
  //B87678
  int t;
  cin>>t;
  for(int i=0; i<t; i++){
    double n;
    cin>>n;
    if(n==1){
      return 1;
    }
    long double rec = 1/n;
    long double exv = 1*rec;

    for(double i =2; i<= n; i++){
      exv += rec*[(1/(i-1))*i + prob())];
    }
    exv = floor(exv);
    cout<<exv<<endl;
  }
  return 0;
}