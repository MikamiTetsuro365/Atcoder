#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    string s1, s2; cin >> s1 >> s2;

    ll ans = 1;

    bool yokoF = false;
    bool tateF = false;
    for(ll i = 0; i < s1.length();){

        if(s1[i] == s2[i]){
            //最初縦並び1つ
            if(i != 0){
                if(yokoF == false){
                    ans *= 2;
                }else{
                    yokoF = false;
                }
            }else{
                ans *= 3;
            }
            i+=1;
            ans %= MOD;
            tateF = true;
        }else if(s1[i] == s1[i+1]){
            if(i != 0){
                if(tateF == false){
                    ans *= 3;
                }else{
                    ans *= 2;
                    tateF = false;
                }
            }else{
                ans *= 6;
                ans %= MOD;
            }
            ans %= MOD;
            i+=2;
            yokoF = true;
        }
    }  

    cout << ans << endl;
}