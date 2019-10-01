#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

vector<bool > prime;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

//primeListには素数は入ってません
void isPrime(ll N){
    prime[0] = false;
    prime[1] = false;

    //ルートN以下まで繰り返す
    for(ll i = 2; i < ceil(sqrt(N)) ; i++){
        //素数になりえないとき
        //cout << i << endl;
        if(prime[i] == false) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j < N; j += i){
            prime[j] = false;
        }    
    }
}

//約数
vector<ll > divisor(ll n) {
  vector<ll > div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      //重複許すマジ
      if(i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return (div);
}



int main(){

    ll A, B;
    cin >> A >> B;

    if(A < B){
        swap(A, B);
    }

    ll GCD = gcd(A, B);

    prime.assign(GCD + 1, true);
    isPrime(GCD);

    //GCDの約数つまりAとBの公約数
    vector<ll > div = divisor(GCD);

    //素数数え上げ
    ll ans = 0;
    for(ll i = 0; i < div.size(); i++){
        cout << div[i] << endl;
        if(div[i] == 1 || prime[div[i]] == true){
            ans++;
        }
    }

    cout << ans << endl;
    


}