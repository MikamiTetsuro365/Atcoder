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

    ll N, L;
    cin >> N >> L;

    vector<string > v(N);
    for(ll i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for(ll i = 0; i < N; i++){
        cout << v[i];
    }
    cout << endl;
}