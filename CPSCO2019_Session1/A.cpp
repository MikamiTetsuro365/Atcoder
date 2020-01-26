#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N, A;
    cin >> N >> A;

    ll mn = A / 3;
    if(A % 3 > 0){
        mn++;
    }

    ll mx = N / 3;
    if(N % 3 > 0){
        mx++;
    }

    cout << mn << " " << min(mx, A) << endl; 

}