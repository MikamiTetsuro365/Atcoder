#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){
    string N; cin >> N;
    for(ll i = 0; i < N.length(); i++){
        if(N[i] == '1') N[i] = '9';
        else if(N[i] == '9') N[i] = '1';
    }
    cout << N << endl;
}