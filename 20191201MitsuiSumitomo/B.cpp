#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N = 0;
    cin >> N;

    ll tmp = N;

    for(ll i = N; i > 0; i--){
        ll tmp = i * 1.08;
        if(tmp == N){
            cout << i << endl;
            return 0;
        }
    }

    cout << ":(" << endl;

}