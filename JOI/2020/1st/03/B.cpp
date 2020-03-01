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

    ll N;
    string S;
    cin >> N >> S;

    for(ll i = 0; i < N-2; i++){
        if(S[i] == 'j' && S[i+1] == 'o' && S[i+2] == 'i'){
            S[i] = 'J';
            S[i+1] = 'O';
            S[i+2] = 'I';
        }
    }

    cout << S << endl;

}