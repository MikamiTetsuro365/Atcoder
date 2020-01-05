#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//6->5->6とだすのが最適
//境界値は気をつけろ
int main() {

    ll N; cin >> N;

    //ここ境界値
    if(N <= 6){
        cout << 1 << endl;
        return 0;
    }

    if(N <= 11){
        cout << 2 << endl;
        return 0;
    }

    ll ans = N / 11 * 2;

    //ここ境界値
    if(N % 11 >= 7){
        ans += 2;
    }else if(N % 11 != 0){
        ans += 1;
    }

    cout << ans << endl;

}
