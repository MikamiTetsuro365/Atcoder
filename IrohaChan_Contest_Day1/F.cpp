#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll MOD = 1000000007;

map<ll, ll> PF;
ll primeFactor(ll num){

    //素因数と指数部の並び
    ll cn = 0;
    ll i = 2;

    while(num >= i * i){
        if(num % i == 0){
            PF[i]++;
            num /= i;
            cn++;
        }else{
            i++;
        }
    }
    //1は素因数分解できない
    if(num != 1){
        PF[num]++;
        cn++;
    }
    
    return cn;
}

int main(){

    ll N, K;
    cin >> N >> K;

    ll num = primeFactor(N);

    if(num < K){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 1;

    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        for(ll i = 0; i < iter->second; i++){
            if(K == 1){
                ans *= iter->first;
            }else{
                K--;
                cout << iter->first << " ";
            }
        }        
    }

    cout << ans << endl;
}