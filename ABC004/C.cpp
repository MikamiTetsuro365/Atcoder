#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//6番目まであるので30周期ですよ．．．
int main() {

    ll N;
    cin >> N;

    ll ans = N % 30;

    vector<ll > A;
    for(ll i = 0; i < 6; i++){
        A.push_back(i+1);
    }

    for(ll i = 0; i < ans; i++){
        swap(A[i%5], A[(i%5)+1]);
    }

    for(ll i = 0; i < 6; i++){
        cout << A[i];
    }
    cout << endl;
}