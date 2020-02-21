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

    bool f = false;
    for(ll i = 1; i < S.length(); i++){
        if(S[i-1] == 'a' && S[i] == 'o'){
            S[i-1] = 'k';
            S[i] = 'i';
        }
    }
    
    cout << S << endl;
}