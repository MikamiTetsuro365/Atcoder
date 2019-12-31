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
        //cout << i << endl;
        if(!prime[i]) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j <= N; j += i){
            prime[j] = false;
        }    
    }
}

int main(){

    cin >> N;
    prime.assign(110000 + 1, true);
    isPrime(110000);

    for(ll i = N; i < prime.size(); i++){
        if(prime[i] == true){
            cout << i << endl;
            return 0;
        }
    }
} 