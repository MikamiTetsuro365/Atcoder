#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll A, B;
    cin >> A >> B;

    ll ans = B / A;
    if(B % A > 0){
        ans++;
    }

    cout << ans << endl;

}