#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
//乗れるだけ載せて，乗れないなら次の時間に乗れるだけ載せるを繰り返す
int main(){

    ll N, C , K;
    cin >> N >> C >> K;
    vector<ll > T(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> T[i];  
    }
    sort(T.begin(), T.end());
    
    ll ans = 0;

    ll mn = T[0];
    ll mx = T[0] + K;
    ll cn = 0;
    bool flg = false;

    for(ll i = 0; i < N; i++){
        if(C == 1){
            ans++;
            continue;
        }
        if(flg == true){
            flg = false;
            cn = 0;
            ans++;
            mn = T[i];
            mx = T[i] + K;
        }

        if(T[i] >= mn && T[i] <= mx){
            cn++;
            if(cn == C) flg = true;
        }else{
            cn = 1;
            ans++;
            mn = T[i];
            mx = T[i] + K;
        }
    }

    if(C != 1 && cn < C){
        ans++;
    }

    cout << ans << endl;


} 