#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    //階乗を前計算
    string S;
    cin >> S;

    vector<ll > w;

    //後ろから選んだほうが早い..?
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'c'){
            w.push_back(0);
        }else if(w.size() > 0 && S[i] == 'w'){
            for(ll j = 0; j < w.size(); j++){
                w[j]++;
            }
        }
    }

    ll ans = 0;
    for(ll j = 0; j < w.size(); j++){
        //cout << w[j] << endl;
        //w[j]個のwから2個を選ぶ
        ans += w[j] * (w[j] - 1) / 2;
    }

    cout << ans << endl;


}