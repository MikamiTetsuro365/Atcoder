#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//+~+間が0じゃないとだめ
//つまり0が1つでもあればカウントしない
int main() {

    string S;
    cin >> S;
    S += '+';

    ll ans = 0;

    bool zero = false;
    for(ll i = 0; i < S.length(); i++){      
        if(S[i] == '+'){
            if(zero == true){
                zero = false;
            }else{
                ans++;
            }
        }
        if(S[i] == '0') zero = true; 
    }

    cout << ans << endl;

}