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

bool ripposu(ll N){
    ll sum = 0;
    for(ll i = 1; i < sqrt(N); i++){
        if(pow(i, 3) == N){
            return true;
        }
    }
    return false;
}

bool kanzensu(ll N){
    ll sum = 0;
    for(ll i = 1; i < N; i++){
        if(N % i == 0){
            sum += i;
        }
    }
    if(sum == N){
        return true;
    } 
    return false;
}

int main(){

    ll N;
    cin >> N;
    
    //cin >> N;
    prime.assign(64, true);
    isPrime(64);

    if(prime[N] == true){
        cout << "Sosu!" << endl;
        return 0;
    }

    if(N >= 2 && ceil(sqrt(N)) == floor(sqrt(N)) ){
        cout << "Heihosu!" << endl;
        return 0;
    }

    if(N >= 2 && ripposu(N) ){
        cout << "Ripposu!" << endl;
        return 0;
    }

    if(N != 0 && kanzensu(N)){
        cout << "Kanzensu!" << endl;
        return 0;
    }

    cout << N << endl;

} 