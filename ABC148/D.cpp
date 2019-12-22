#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll mx = 0;
map<ll, vector<ll > > mp;
void solve(ll num, ll len = 0, ll posi = -1){
    for(ll i = 0; i < mp[num].size(); i++){
        //cout << num << " " << mp[num][i] << endl;
        if(posi >= mp[num][i]){
            continue;
        }

        solve(num + 1, len + 1, mp[num][i] );

    }
    mx = max(mx, len);
    return;
}

int main() {

    ll N = 0;
    cin >> N;
    //map<ll, vector<ll > > mp;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        mp[t].push_back(i);
    }

    if(mp[1].empty()){
        cout << -1 << endl;
        return 0;
    }

    solve(1);

    cout << N - mx << endl;
}