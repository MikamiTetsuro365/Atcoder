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

    ll A, B, K;
    cin >> A >> B >> K;
    for(ll i = A; i < A + K; i++){
        if(i > B) break;
        cout << i << endl;
    }

    for(ll i = max(A + K, B - K + 1); i <= B; i++){
        cout << i << endl;
    }

}