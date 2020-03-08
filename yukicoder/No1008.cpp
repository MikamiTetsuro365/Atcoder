#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M;
vector<ll > A;
vector<ll > X;
vector<ll > W;

bool check(ll mid){
    for(ll i = 0; i < N; i++){
        
    }
}

int main(){

    cin >> N >> M;
    //入力
    for(ll i = 0; i < N; i++){
        ll a; cin >> a;
        A.push_back(a);
    }

    for(ll i = 0; i < M; i++){
        ll x, w; cin >> x >> w;
        X.push_back(x);
        W.push_back(w);
    }

    //二分探査
    ll ng = 0; ll ok = INF;
 
    //最小値を求める
    //rightを寄せていく
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //最小値
    cout << ok << endl;


}