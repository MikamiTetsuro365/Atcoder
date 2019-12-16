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

    ll N; cin >> N;
    vector<ll > A(N, 0);
    //初期化
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    ll ans = INF;
    for(ll i = 0; i <= (1<<N); i++){
        ll t1 = 0;
        ll t2 = 0;
        for(ll j = 0; j < N; j++){
            //右シフトして最下位で立っているかどうか判定
            if((i >> j) & 1 == 1){
                t1 += A[j];
            }else{
                t2 += A[j];
            }
        }
        ans = min(ans, max(t1, t2));
    }

    cout << ans << endl;
}