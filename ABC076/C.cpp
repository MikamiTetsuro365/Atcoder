#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 
//辞書順最小
//なるべく後ろにあるハテナに文字列を入れる
int main(){
    
    string S, T;
    cin >> S >> T;
    
    //例外
    if(S.length() < T.length()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    ll posi = -1;
    for(ll i = 0; i <= S.length() - T.length(); i++){
        bool fin = true;
        //cout << i << " " << S[i] << endl;
        for(ll j = i; j < i + T.length(); j++){
            //cout << j - i << endl;
            if(S[j] == '?' || S[j] == T[j - i]){
                continue;
            }else{
                fin = false;
                break;
            }
        }
        
        //復元
        if(fin == true){
            posi = i;
        }
    }

    if(posi != -1){
        string ans;
        //前半穴埋め
        for(ll j = 0; j < posi; j++){
            if(S[j] == '?'){
                ans += 'a';
            }else{
                ans += S[j];
            }
        }
        ans += T;
        //後半穴埋め
        for(ll j = posi + T.length(); j < S.length(); j++){
            if(S[j] == '?'){
                ans += 'a';
            }else{
                ans += S[j];
            }
        }
        cout << ans << endl;
    }else{
        //埋める候補がなければ
        cout << "UNRESTORABLE" << endl;
    }

}