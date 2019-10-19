#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){
    ll A, B, C, D, E, F, G, H; cin >> A >> B >>C >>D >>E >> F >> G >>H;

    ll ans = A + B + C + D;
    ll ans2 = E + F + G + H;

    if(ans < ans2){
        cout << ans2 << endl;
    }else{
        cout << ans << endl;
    }
}