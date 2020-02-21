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
    
    vector<ll > A;
    vector<ll > B;
    vector<ll > C;
    for(ll i = 0; i < N; i++){
        vector<ll > tmp(3, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        sort(tmp.begin(), tmp.end());
        A.push_back(tmp[0]);
        B.push_back(tmp[1]);
        C.push_back(tmp[2]);
    }   

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    cout << A.back() * B.back() * C.back() << endl;

}