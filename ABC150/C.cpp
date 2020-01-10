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
    cin >> N;

    vector<ll > P;
    vector<ll > Q;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        P.push_back(t);
    }

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        Q.push_back(t);
    }

    vector<ll > A(N, 0);
    for(ll i = 0; i < N; i++){
        A[i] = i + 1;
    }

    map<vector<ll >, ll > mp;

    ll cn = 1;
    do{
        vector<ll > tmp;
        for(ll i = 0; i < A.size(); i++){
            tmp.push_back(A[i]);
        }
        
        mp[tmp] = cn;

        cn++;

    }while(next_permutation(A.begin(), A.end()));


    cout << abs(mp[P] - mp[Q]) << endl;


}