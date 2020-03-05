#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N; string S;
    cin >> N >> S;
    
    vector<ll > v(4, 0);

    for(ll i = 0; i < N; i++){
        v[S[i]-'0'-1]++;
    }
    sort(v.begin(), v.end());

    cout << v.back() << " " << v.front() << endl;

}