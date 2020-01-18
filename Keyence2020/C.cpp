#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N, K, S;
    cin >> N >> K >> S;

    ll iku = 1919;
    if(S == 1000000000){
        iku *= -1;
    }

    for(ll i = 0; i < N; i++){
        if(i >= K){
            cout << ( i ? " " : "" ) << S + iku;
        }else{
            cout << ( i ? " " : "" ) << S;
        }
    }

}