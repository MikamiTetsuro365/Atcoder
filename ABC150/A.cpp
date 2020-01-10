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

    ll A, X;
    cin >> A >> X;

    ll ans = 500 * A;

    if(ans >= X){
        cout << "Yes" << endl;
    }else{  
        cout << "No" << endl;
    }

}