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
typedef long long ll;
ll N;
ll M;
string s;

int main(){
    string S;
    cin >> S;
    
    ll ans = 0;
    ll i = 1;
    //1 対 2で分ける
    for(ll j = 0; j < S.length() / 3; j++){
        //cout << S[i] << S[i+1] << endl;
        if(S[i] != S[i+1]){
            if(S[i] != S[i-1] && S[i+1] != S[i+2]){
                ans += 1;
            }
        }
        ans += 2;
        i += 2;
    }

    if(S.length() % 3 == 1){
        ans += 1;
    }else if(S.length()  % 3 == 2){

        if(S[S.length() - 1] == S[S.length() - 2] ){
            if(S[S.length() - 1] == S[S.length() - 3] && S[S.length() - 2] == S[S.length() - 4] ){
                ans += 2;
            }else{
                ans += 1;
            }
            
        }else{
            
            ans += 2;
        }
    }

    cout << ans << endl;
} 