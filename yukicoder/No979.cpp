#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

vector<ll > divisor(ll n) {
  vector< ll > div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      //重複許すマジ
      if(i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return (div);
}

int main() {
    ll N;
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    //最長増加部分列的な
    ll mx = 0;
    vector<ll > dp(N+19, 1);
    //約数毎にどれだけ伸ばせるか？
    vector<ll > len(19191919, 0);
    for(ll i = 0; i < N; i++){
        vector<ll > div = divisor(vec[i]);
        for(ll j = 0; j < div.size()-1; j++){
            //自分の約数方向に伸ばせる
            dp[i] = max(len[div[j]]+1, dp[i]);
            //cout << vec[i] << "::" << len[div[j]]+1 << endl;
        }
        len[vec[i]] = max(dp[i], len[vec[i]]);
        //cout << dp[i] << endl;
        mx = max(dp[i], mx);
    }

    cout << mx << endl;

}