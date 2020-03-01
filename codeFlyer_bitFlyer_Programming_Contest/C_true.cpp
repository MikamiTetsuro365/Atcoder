#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//余事象を考える
int main() {

    ll N, D;
    cin >> N >> D;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //N個から3つの選び方
    ll sum = N * (N - 1) * (N - 2) / 6;

    //i j kのうちjを基準として左右分けて考える
    //X[j]で左にいくつD以下の要素があるか
    vector<ll > L(N, 0);
    //X[j]で左にいくつD以下の要素があるか
    vector<ll > R(N, 0);

    //しゃくとりっぽく
    ll l = 0;
    for(ll r = 0; r < N; r++){
        //vec[r]を基準としてD以下のvec[l]（基点）を探す
        //以下になったらそれ以降は以下
        while(l < r && vec[r]-vec[l] > D){
            l++;
        }
        L[r] = r - l;
    }
    ll r = N - 1;
    for(ll l = N - 1; l >= 0; l--){
        //vec[l]を基準としてD以下のvec[r]（基点）を探す
        //以下になったらそれ以降は以下
        while(l < r && vec[r]-vec[l] > D){
            r--;
        }
        R[l] = r - l;
    }

    //余事象を考える：NGを引いていく
    for(ll i = 0; i < N; i++){
        //X[i]-X[k]がD以
        //x[j]と差がD以下の中から2つ選ぶ j=kとした時 i-k間は必ずD以下になるので条件を満たさない
        sum -= L[i] * (L[i]-1) / 2;
        //左がD以上 右がD以下
        sum -= (i - L[i]) * R[i];
        //左がD以下 右がD以上
        sum -= L[i] * (N - i - 1 - R[i]);
        //左も右もD以上
        sum -= (i - L[i]) * (N - i - 1 - R[i]);
    }

    cout << sum << endl;

}