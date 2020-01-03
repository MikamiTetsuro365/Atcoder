#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


//べき定数 a^n nは2以上
//1のときはどんなnを書けても1しかない
//b^2 b^3 b^4...をXの範囲を超えないだけ求めてやる
//それだけ
//なんか難しかった（は？
int main() {
    ll X; cin >> X;
    ll ans = 1;
    for(ll i = 2; i <= X; i++){
        ll tmp = i * i;
        while(tmp <= X){
            ans = max(ans, tmp);
            tmp *= i;
        }
    }

    cout << ans << endl;

}