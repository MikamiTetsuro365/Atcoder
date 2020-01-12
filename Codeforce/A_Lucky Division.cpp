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

    ll tmp[10] = {4, 7, 47, 74, 447, 474, 477, 744, 747, 777};

    ll N; cin >> N;

    for(ll i = 0; i < 10; i++){
        if(N % tmp[i] == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

}