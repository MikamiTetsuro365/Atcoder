#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//愚直シミュレーションより良い方法
int main() {

    ll K, T;
    cin >> K >> T;

    priority_queue<ll > que;

    for(ll i = 0; i < T; i++){
        ll t; cin >> t;
        que.push(t);
    }

    ll top = que.top();

    //一番多い数を持つ種類のケーキを１直線に並べて間を区切っていく
    //一直線で並べた時点で隣り合う数はa-1
    //そこに別の種類のケーキを奥ごとに隣り合う数は１へる
    //0になったらそれ以上減らないし，種類が３種類以上あってa-1以上の隙間を消せたら
    //全て同じ種類同士が隣合わないようにおける！

    cout << max(top - 1 - (K - top), 0LL) << endl;

}