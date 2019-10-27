#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  

int main(){
    ll N, M; cin >> N >> M;

    ll ans = 0;
    while(N <= M){
        N *= 2;
        ans++;
    }

    cout << ans << endl;
}