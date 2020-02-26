#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N;
    cin >> N;

    vector<bool > f(N, false);

    map<ll, ll > mp;
    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        mp[i] = A-1;
    }

    ll idx = 0;
    ll cn = 0;
    while(cn <= 100019){
        idx = mp[idx];
        cn++;
        if(idx == 1){
            cout << cn << endl;
            return 0;
        }
    }

    cout << -1 << endl;

}