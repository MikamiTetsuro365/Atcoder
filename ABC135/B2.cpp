#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
ll N;

int main(){

    ll N;
    cin >> N;

    vector<ll > v(N, 0);

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        cin >> v[i];
        if(i + 1 != v[i]){
            ans++;
        }

        if(ans > 2){
            cout << "NO" << endl;
            return 0;
        }

    }

    if(ans == 0 || ans == 2){
        cout << "YES" << endl;
    }

}