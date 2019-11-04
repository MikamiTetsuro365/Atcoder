#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    map<ll, ll > mp;

    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        mp[t]++;
    }

    priority_queue<pi> que;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter -> second >= 2){
            que.push(make_pair(iter->first, iter->second));
        }
    }

    if(que.size() < 2){
        cout << 0 << endl;
    }else{
        if(que.top().second >= 4){
            ll a = que.top().first; que.pop();
            cout << a * a << endl;
        }else{
            ll a = que.top().first; que.pop();
            ll b = que.top().first; que.pop();
            cout << a * b << endl;
        }
    }
}