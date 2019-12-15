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

    ll N, M; cin >> N >> M;
    map<ll, ll> mp;
    for(ll i = 1; i <= N; i++){
        mp[i] = i-1;
    }

    //戦闘の番号
    ll mn = 0;

    for(ll i = 0; i < M; i++){
        ll a; cin >> a;
        if(mp[a] == mn){
            continue;
        }
        mp[a] = mn - 1;
        mn -= 1;
    }

    priority_queue<pi, vector<pi>, greater<pi > > que;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        que.push(make_pair(iter->second, iter->first));
    }    

    //表示
    for(ll i = 0; i < N; i++){
        cout << que.top().second << endl;
        que.pop();
    }

}