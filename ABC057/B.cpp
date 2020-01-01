#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

ll a[55], b[55], c[55], d[55];

int main(){

    ll N, M; cin >> N >> M;

    for(ll i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }

    for(ll i = 0; i < M; i++){
        cin >> c[i] >> d[i];
    }


    for(ll i = 0; i < N; i++){
        ll p = 1;
        ll dis = INF;
        for(ll j = 0; j < M; j++){

            ll tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);

            if(tmp < dis){
                dis = tmp;
                p = j;
            }
        }
        cout << p + 1 << endl;
    }

}