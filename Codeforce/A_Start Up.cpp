#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;
//回文判定かと思いきや
//アルファベットも左右対称じゃないと駄目です（試される英語力
int main(){

    string S;
    cin >> S;

    for(ll i = 0; i < S.length() / 2; i++){
        if(S[i] != S[S.length()-1-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    char check[11] = {'A','H','I','M','O','T','U','V','W','X','Y'};
    
    for(ll i = 0; i < S.length(); i++){
        bool f = false;
        for(ll j = 0; j < 11; j++){
            if(S[i] == check[j]){
                f = true;
                break;
            }
        }
        if(f == false){
            cout << "NO" << endl;
            return 0;            
        }
    }

    cout << "YES" << endl;
    return 0;

}