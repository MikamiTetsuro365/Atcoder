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
    ll N;
    cin >> S >> N;

    for(ll i = 0; i < S.length(); i++){
        if('a' == S[i]) continue;
        //cout << 'z' - S[i] + 1 << " " << N << endl;
        if('z' - S[i] + 1 <= N){
            N -= 'z' - S[i] + 1;
            S[i] = 'a';
        }
    }

    if(N > 0){
        S[S.length()-1] += N % 26;
    }

    cout << S << endl;

}