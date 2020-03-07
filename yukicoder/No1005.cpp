#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    string S, T;
    cin >> S >> T;
    
    ll ans = 0;
    
    string tS;

    //こんなんもあるんか
    if(S.length() < T.length()){
        cout << "0" << endl;
        return 0;
    }

    //一文字で当てはまるのがあれば無理よね
    if(T.length() == 1){
        for(ll i = 0; i < S.length(); i++){
            if(S[i] == T[0]){
                cout << "-1" << endl;
                return 0;
            }
        }
        cout << "0" << endl;
        return 0;
    }

    for(ll i = 0; i <= S.length()-T.length();){
        bool f = true;
        for(ll j = 0; j < T.length(); j++){
            if(S[i+j] != T[j]){
                f = false;
                break;
            }
            tS += S[i+j];
        }
        if(f == true){
            //-を挿入したとする
            ans++;
            i += T.length() - 1;
        }else{
            i++;
        }
    }

    cout << ans << endl;
}