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

    ll N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    reverse(S.begin()+A-1, S.begin()+B);

    cout << S << endl;

}