#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

vector<bool > prime;

//primeListには素数は入ってません
void isPrime(ll N){
    prime[0] = false;
    prime[1] = false;

    //ルートN以下まで繰り返す
    for(ll i = 2; i < ceil(sqrt(N)) ; i++){
        //素数になりえないとき
        if(prime[i] == false) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j < N; j += i){
            prime[j] = false;
        }
        
    }
}

int main(){

    ll Q;
    cin >> Q;
    
    //cin >> N;
    prime.assign(100001, true);
    isPrime(100001);

    vector<ll > kukan(100001, 0);

    for(ll i = 2; i < prime.size(); i++){
        //cout << prime[i] << endl;
        if(prime[i] == true && i % 2 == 1){
            if(prime[(i + 1) / 2] == true){
                kukan[i] = kukan[i - 1] + 1;
            }else{
                kukan[i] = kukan[i - 1];
            }
        }else{
            kukan[i] = kukan[i - 1];
        }
    }

    vector<ll > ans(Q, 0);
    for(ll i = 0; i < Q; i++){
        ll l = 0; 
        ll r = 0;
        cin >> l >> r;
        //ans += kukan[r] - kukan[l - 1];
        ans[i] = kukan[r] - kukan[l - 1];
    }

    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
} 