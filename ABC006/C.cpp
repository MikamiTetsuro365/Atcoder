#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//愚直な式変形と調べる変数の固定化
int main() {

    ll N, M;
    cin >> N >> M;

    for(ll z = 0; z <= 100000; z++){
        ll y = M - 2 * N - 2 * z;
        if(y < 0) continue;
        ll x = N - y - z;
        if(x < 0) continue;
        else{
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;

}