#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    //階乗を前計算
    string S;
    cin >> S;

     ll ans = 0;
    //後ろから選んだほうが早い!
    ll count = 0;
    for(ll i = S.length(); i >= 0; i--){
        if(S[i] == 'c'){
            ans += count * (count - 1) / 2;
        }else if(S[i] == 'w'){
            count++;
        }
    }

    cout << ans << endl;

}