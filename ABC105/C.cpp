#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;

    vector<ll > S;
    
    //例外
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    while(N != 0){
        //剰余
        //マイナスの剰余はC++ではマイナスになってしまいおかしいので割る数で足す
        ll t = N % 2;
        if(t < 0) t += 2;

        S.push_back(t);
        
        N = N - t;
        N /= -2;
        
    }

    reverse(S.begin(), S.end());

    //結果表示
    for(ll i = 0; i < S.size(); i++){
        cout << S[i];
    }
    cout << endl;

}