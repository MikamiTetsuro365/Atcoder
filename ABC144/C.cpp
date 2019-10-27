#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

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

int main(){

    ll N; cin >> N;

    vector<ll > div = divisor(N);

    ll ans = INF;

    for(ll i = 0; i < div.size() / 2 + 1; i++){
        //cout << div[i] << " " << div[div.size() - i - 1] << endl;
        ans = min(div[i] - 1 + div[div.size() - i - 1] - 1, ans);
    }

    cout << ans << endl;
    

}