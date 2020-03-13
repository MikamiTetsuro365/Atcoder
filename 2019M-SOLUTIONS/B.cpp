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

    string S;
    cin >> S;

    ll sum = 0;
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'o') sum++;
    }

    if(15 - S.length() >= (8 - sum)) cout << "YES" << endl;
    else cout << "NO" << endl;

}