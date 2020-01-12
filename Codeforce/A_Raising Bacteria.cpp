#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N; cin >> N;

    ll cn = 0;
    //例 N=10
    //10になるには5が2倍された時
    //5になるには2が2倍された後に1足されたとき
    //2になるには1が2倍された時
    //よって，最初のバクテリア1が4になったとき1を足すと10に最小で分裂できる
    while(N / 2 != 0){
        if(N % 2 == 1){
            cn++;
        }
        N /= 2;
    }

    cout << cn + 1 << endl;

}