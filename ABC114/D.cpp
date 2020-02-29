#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

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

int main() {

    //準備
    prime.assign(101, true);
    isPrime(100);

    ll N;
    cin >> N;

    //N!の素因数
    map<ll, ll > PF;
    for(ll i = 1; i <= 100; i++){
        ll cn = 0;
        if(prime[i] == true){
            ll j = i;
            while(N / j > 0){
                PF[i] += N / j;
                cn += N / j;
                j *= i;

            }
        }
        //cout << cn << endl;
    }

    ll num75 = 0;
    ll num25 = 0;
    ll num15 = 0;
    ll num5 = 0;
    ll num3 = 0;


    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        ll cn = iter->second;
        if(cn >= 2) num3++;
        if(cn >= 4) num5++;
        if(cn >= 14) num15++;
        if(cn >= 24) num25++;
        if(cn >= 74) num75++;
    }

    ll ans = num75;
    //重複して数えているのでマイナス１する
    ans += (num5 - 1) * num15;
    ans += (num3 - 1) * num25;
    ans += (num3 - 2) * num5 * (num5 - 1) / 2;

    cout << ans << endl;

}
