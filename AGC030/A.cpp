#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll A, B, C; cin >> A >> B >> C;

    ll ans = 0;

    if(A + B < C){
        ans = A + 2 * B + 1;
    }else if(A + B >= C){
        ans = C + B;
    }


    cout << ans << endl;

}