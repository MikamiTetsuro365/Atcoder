#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//条件ワケして破滅した
int main(){

    ll T;
    cin >> T;

    vector<ll > ans;
    for(ll i = 0; i < T; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        ll ans = INF;
        //とりあえず仮でa<=b<=cと並べて辻褄が合う並べ替えができるかチェック
        //bを最大，最小に揃える
        if(a < c) swap(a, c);
        
        if(b >= 3){
            //aがbより大きいときは下げる
            ll a_ans = max(0LL, a - b + 1);
            //cがaより大きいときは
            ll c_ans = max(0LL, c - (a - a_ans) + 1);
            if(a_ans < a && c_ans < c){
                ans = min(ans, a_ans + c_ans);
            }
        }

        if(a >= 3){
            ll c_ans = max(0LL, c - a + 1);
            ll b_ans = max(0LL, b - (c - c_ans) + 1);
            if(c_ans < c && b_ans < b){
                ans = min(ans, c_ans + b_ans);
            }            
        }

        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;

    }

}