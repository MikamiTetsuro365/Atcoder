#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//打ち消すイメージ
//愚直シミュレーション
int main() {

    ll K, T;
    cin >> K >> T;

    priority_queue<ll > que;

    for(ll i = 0; i < T; i++){
        ll t; cin >> t;
        que.push(t);
    }

    ll top = que.top();
    for(ll i = 0; i < T; i++){
        if(i == 0){
            que.pop();
        }else{
            ll tmp = top - que.top();
            //cout << tmp << endl;
            que.pop();
            top = abs(tmp);
        }
    }

    cout << max(0LL, top - 1) << endl;

}