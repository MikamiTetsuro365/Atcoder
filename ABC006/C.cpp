#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, M;
    cin >> N >> M;

    for(ll i = 0; i < N; i++){
        if(i > N) break;
        for(ll j = 0; j < N; j++){
            ll k = N - i - j;
            if(k < 0) break;
            ll n = i + j + k;
            ll m = 2 * i + 4 * j + 3 * k;
            if(n == N && m == M){
                cout << i << " " << k << " " << j << endl;
                return 0;
            }
        }        
    }

    cout << -1 << " " << -1 << " " << -1 << endl;

}