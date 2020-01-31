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

    ll N;
    cin >> N;

    vector<string > s;

    for(ll i = 0; i < N; i++){
        string t; cin >> t;
        s.push_back(t);
    }

    for(ll i = 0; i < N; i++){
        for(ll j = N-1; j >= 0; j--){
            cout << s[j][i];
        }
        cout << endl;
    }

}