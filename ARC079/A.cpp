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

    ll N, T; cin >> N >> T;

    vector<map<ll, ll > > G;
    G.assign(N, map<ll, ll>());

    for(ll i = 0; i < T; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a][b]++;
        G[b][a]++;
    }

    auto b1 = G[0].begin(), e1 = G[0].end();
    for (auto iter = b1; iter != e1; iter++) {
        ll next = iter -> first;
        if(G[next][N-1] == 1){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

}

