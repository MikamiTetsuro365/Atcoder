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

    ll x, a, b;
    cin >> x >> a >> b;

    if(abs(x-a) > abs(x-b)){
        cout << "B" << endl;
    }else{
        cout << "A" << endl;
    }

}