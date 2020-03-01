#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//メモ化して計算量落とせると思ったが・・・3TLE出るのでダメそう？
int main() {

    ll N, D;
    cin >> N >> D;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    ll ans = 0;

    //メモ化(二分探査の回数を減らせる)->二分探査自体が高速なので減らしてもあんま意味ない
    vector<ll > memo(N, -1);
    for(ll i = 0; i < N; i++){
        ll idx = 0;
        if(memo[i] == -1){
            idx = upper_bound(vec.begin(), vec.end(), vec[i] + D) - vec.begin();
            memo[i] = idx;
        }else{
            idx = memo[i];
        }
        
        for(ll j = i + 1; j < idx; j++){
            ll idx2 = 0;
            if(memo[j] == -1){
                idx2 = upper_bound(vec.begin(), vec.end(), vec[j] + D) - vec.begin();
                memo[j] = idx2;
            }else{
                idx2 = memo[j];
            }
            
            // ll idx3 = 0;
            // if(memo[idx2] == -1){
            //     idx3 = upper_bound(vec.begin(), vec.end(), vec[idx2-1] + D) - vec.begin();
            //     memo[idx3];
            // }
            ans += idx2 - idx;
        }
        // cout << vec[idx-1] << endl;
        //ll idx2 = upper_bound(vec.begin(), vec.end(), vec[idx-1] + D) - vec.begin();
        // cout << ":" << vec[idx-1] << " " << vec[idx2-1] << endl;
        //cout << ":" << idx - 1 - i << " " << idx2 - idx << endl;
        //ll num = idx2 - idx;
        //ans += num * (num+1) / 2;
    }

    cout << ans << endl;
}