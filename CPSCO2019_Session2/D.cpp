#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll H, N;

int main() {

    ll a, b;
    cin >> a >> b;

    if(a < b) swap(a, b);

    //最適なとり方はどちら
    if((a - 1) % 2 == 1 || (b - 1) % 2 == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}