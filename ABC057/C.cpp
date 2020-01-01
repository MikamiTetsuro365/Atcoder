#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

void divisor(ll n) {
  ll ans = 0;
  vector< ll > div;

  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);

      //重複許すマジ
      if(i * i != n){
          div.push_back(n / i);
      }
    }
  }
  sort(div.begin(), div.end());
  
  string s;
  s = to_string(div[div.size()/2]);

  cout << s.length() << endl;

}

int main(){

    ll N; cin >> N;

    divisor(N);
}