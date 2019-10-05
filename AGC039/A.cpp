#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;


int main(){

    string s;
    cin >> s;
    vector<char > S;
    for(ll i = 0; i < s.length(); i++){
        S.push_back(s[i]);
    }
    ll K;
    cin >> K;

    vector<ll > vec;
    for(ll i = 0; i < S.size();){
        ll j = i;
        //一緒の間ループを回し続けて，切れ目を探す
        while(j < S.size() && S[j] == S[i]){
            ++j;
        }
        vec.push_back(j - i);
        //次の始点へすっ飛ばす
        i = j;
    }



    ll ans = 0;

    bool f = false;
    for(ll i = 1; i < S.size();){
        if(S[i - 1] == S[i]){
            ans++;
            S[i] = '1';
            i += 2;
        }else{
            i++;
        }
    }

    if(S[0] == S[S.size()-1]){
        //初めと終わりが一緒
        if(vec.size() == 1){
            if(K % 2 == 0){
                ans = (ans * (K / 2)) + ((ans + 1) * (K / 2));
            }else{
                ans = (ans * ((K / 2) + 1)) + ((ans + 1) * (K / 2));
            }
            cout  << ans << endl;
            return 0;
        }else{
            if(vec[0] == 1 && vec[vec.size()] == 1){
                ans++;
                ans *= K;
                cout  << ans << endl;
                return 0;
            }else if(vec[0] % 2 == 1){
                ans = ans + ((ans + 1) * (K - 1));
                cout  << ans << endl;
                return 0;          
            }else if(vec[0] % 2 == 0){
                ans *= K;
            }
        }
        if(s.size() % 2 );
    }else{
        //初めと終わりが異なっている
        ans *= K;
    }
    
    /*
    if(S[0] == S[S.size()-1]){
        ans++;
    }
    */
    
    cout  << ans << endl;

}