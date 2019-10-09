#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){

    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = min(A * N, B);

    cout << ans << endl;

}