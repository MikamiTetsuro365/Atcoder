#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>

using namespace std;
typedef long long int ll;

vector<ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      //重複許すマジ
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main(){

    ll N;
    cin >> N;

    ll ans = 0;
    for(ll i = 1; i <= N; i += 2){
        vector<ll > ret = divisor(i);
        if(ret.size() == 8){
            ans++;
        }
    }

    cout << ans << endl;

} 