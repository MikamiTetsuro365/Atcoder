#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
//10進数からN進数への変換
int main(){

    ll N, M;
    //N=変換する10進数の数字 M進数へ
    cin >> N >> M;

    vector<ll > S;
    
    //例外
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    while(N != 0){
        //剰余
        //マイナスの剰余はC++ではマイナスになってしまいおかしいので割る数で足す
        ll t = N % M;
        if(t < 0) t += M;

        S.push_back(t);
        //Nから余りtを引くのはN/Mの商であるということ
        N = N - t;
        N /= M;
        
    }

    reverse(S.begin(), S.end());

    //結果表示
    for(ll i = 0; i < S.size(); i++){
        cout << S[i];
    }
    cout << endl;

}