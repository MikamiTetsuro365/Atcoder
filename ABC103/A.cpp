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

    vector<ll > A(3, 0);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.rbegin(), A.rend());
    cout << abs(A[0]-A[1]) + abs(A[1]-A[2]) << endl;
}