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

    //距離Nに誰が居るか
    map<ll, map<ll, ll > > dist;
    //誰が距離Nにいるか
    map<ll, ll> who;

    //最初の追加ではlが座標0に居ることにする
    for(ll i = 0; i < M; i++){
        ll l, r; cin >> l >> r;
        if(who[r] == 0){
            //まだどこに居るか確定していない
            
        }
    }

}