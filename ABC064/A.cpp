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

    ll r,g,b;
    cin >> r >> g >> b;

    if((r * 100 + g * 10 + b) % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}