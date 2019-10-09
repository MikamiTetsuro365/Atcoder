#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){
    
    ll N;
    cin >> N;

    vector<ll > V(N+10, 0);
    vector<ll > C(N+10, 0);

    for(ll i = 0; i < N; i++){
        cin >> V[i];
    }
    for(ll i = 0; i < N; i++){
        cin >> C[i];
    }

    ll ans = 0;
    //bit全列挙
    for(ll i = 0; i <= (1<<N); i++){
        //ビットの位置を数える
        ll x = 0;
        ll y = 0;
        //cout << i << endl;
        for(ll j = 0; j < N; j++){
            //右シフトして最下位で立っているかどうか判定
            if((i >> j) & 1 == 1){
                //cout << V[j] << " " << C[j] << endl;
                x += V[j];
                y += C[j];
            }
        }
        ans = max(x - y, ans);
    }

    cout << ans << endl;

}