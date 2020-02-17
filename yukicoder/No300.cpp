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

    if(floor(sqrt(N))*floor(sqrt(N)) == N){
        cout << 1 << endl;
        return 0;
    }

    vector<ll > div = divisor(N);

    ll mn = INF;
    for(ll i = 0; i < div.size() / 2; i++){
        if(div[div.size()-1-i] == div[i] * (div[div.size()-1-i]/div[i])){
            mn = min(mn, div[div.size()-1-i]/div[i]);
        } 
    }

    cout << mn << endl;

}