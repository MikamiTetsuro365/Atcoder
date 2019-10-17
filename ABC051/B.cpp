#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
//Z分のループは不要　一意に決まる
int main(){

    ll K, S; cin >> K >> S;

    ll ans = 0;
    for(ll i = 0; i <= min(K, S); i++){
        if(i > K){
            break;
        }
        for(ll j = 0; j <= min(K, S); j++){
            if(i + j > S){
                break;
            }
            if(S - (i + j) <= K){
                ans++;
            }  
        }       
    }

    cout << ans << endl;

}