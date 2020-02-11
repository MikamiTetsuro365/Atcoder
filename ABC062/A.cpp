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

    ll x, y;
    cin >> x >> y;

    ll group[13] {1919, 0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};

    if(group[x] == group[y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}