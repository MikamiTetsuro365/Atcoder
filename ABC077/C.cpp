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
typedef long long ll;
ll N;

//全通り試すとO(N^3)で無駄すぎる
//真ん中を固定して，それより上，それより下の値がどれだけあるかを調べてかけると組み合わせがわかる

int main(){

    cin >> N;
    vector<ll > a(N, 0);
    vector<ll > b(N, 0);
    vector<ll > c(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }

    for(ll i = 0; i < N; i++){
        cin >> b[i];
    }

    for(ll i = 0; i < N; i++){
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        //b[i]より小さい（＞）値の数をaからみつける
        auto it1 = lower_bound(a.begin(), a.end(), b[i]);
        ll lessThan = it1 - a.begin();
         //b[i]より大きい（＞）値の数をaからみつける
        auto it2 = upper_bound(c.begin(), c.end(), b[i]);
        ll GreaterThan = c.end() - it2;
        //総数は？
        ans += lessThan * GreaterThan;
    }   

    cout << ans << endl;
    

} 