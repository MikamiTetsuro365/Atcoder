#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){
    
    ll A, B, T;
    cin >> A >> B >> T;
    ll ans = 0;
    ll cn = 1;
    while(cn * A <= T){
        ans += B;
        cn++;
    }

    cout << ans << endl;

}