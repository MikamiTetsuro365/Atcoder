#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//気持ち偶数奇数で分けるとわかる気がしたが証明がわらず...
int main() {

    ll N, M;
    cin >> N >> M;

    map<ll, ll> mp;
    for(ll i = 0; i < M; i++){
        ll a, b; cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter -> second % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;

}