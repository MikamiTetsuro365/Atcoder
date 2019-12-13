#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N; 
    cin >> N;

    vector<ll > M(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> M[i];
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = 1; j < N; j++){
            if(M[j-1] > M[j]){
                swap(M[j-1], M[j]);
                ans++;
            }
        }
    }

    cout << ans << endl;

}