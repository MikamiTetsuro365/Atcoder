#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//外積！！
//三角形じゃなくて長方形考えると外積での面積は(1/2すると三角形の面積)
//x1y2 - x2y1 = S
//x1とx2を10^9と1で固定して考える

int main() {

    ll N;
    cin >> N;
    
    ll x1 = 1000000000;
    ll x2 = 1;

    if(N <= x1){
        cout << 0 << " " << 0 << " ";
        cout << N << " " << 0 << " ";
        cout << 0 << " " << 1 << endl;
    }else{
        //10^9 * y2 - 1 * y1 = S
        //S/10^9してy2を求める．そのあと-y1してSになるようにするにはどうすればよいか？
        //y2をちょびっと大きめ(切り上げ)にとって，余分をy1で引く！
        //y1=10^9に固定しているので制約を超えない
        ll y2 = N / x1;
        if(N % x1 > 0) y2++;
        ll y1 = x1 * y2 - N;

        cout << 0   << " " << 0 << " ";
        cout << x1 << " " << y1 << " ";
        cout << x2 << " " << y2 << endl;
    }

}