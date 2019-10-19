#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll A, B, C, D; cin >> A >> B >> C >> D;

    ll sec = A+B+C+D;

    cout << sec / 60 << endl;
    cout << sec - (60 * (sec / 60)) << endl;

}