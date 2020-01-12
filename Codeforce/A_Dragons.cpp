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

    ll S, N; cin >> S >> N;

    vector<pi > D;

    for(ll i = 0; i < N; i++){
        ll x, y; cin >> x >> y;
        D.push_back(make_pair(x, y));
    }

    sort(D.begin(), D.end());

    for(ll i = 0; i < N; i++){
        if(S <= D[i].first){
            cout << "NO" << endl;
            return 0;
        }
        S += D[i].second;
    }

    cout << "YES" << endl;

}