#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//愚直な場合分け
//どこまで進んだら戻れなくなるか
int main(){

    ll N, K;
    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //rigth
    ll right = 0;
    for(ll i = K; i < N; i++){
        right += vec[i];
        if(vec[i] <= 1){
            break;
        }
    }

    //left
    ll left = 0;
    for(ll i = K-2; i >= 0; i--){
        left += vec[i];
        if(vec[i] <= 1){
            break;
        }
    }

    if(vec[K-1] == 0){
        cout << 0 << endl;
    }else if(vec[K-1] == 1){
        cout << max(right, left) + 1 << endl;
    }else{
        cout << right + left + vec[K-1] << endl;
    }

}