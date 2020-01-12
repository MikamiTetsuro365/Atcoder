#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//お気持ち：縦横軸の数の最小だけ勝負に関係する

int main() {

    ll N, M; cin >> N >> M;

    if(min(N, M) % 2 == 0){
        cout << "Malvika" << endl;
    }else{
        cout << "Akshat" << endl;
    }

}