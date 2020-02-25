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

    ll sum = 0;
    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        vector<ll > div = divisor(A);
        if(A == 1) continue;
        if(div.size() > 2) sum++;
    }

    if(sum % 2 == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}