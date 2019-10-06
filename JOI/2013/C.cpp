#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll solv(string store_name, string s){

    for(ll j = 0; j < s.length(); j++){
        //文字の位置
        ll k = 0;
        if(s[j] == store_name[k]){
            if(s.length() - (j + store_name.length()) < 0){
                return false;
            }
            
            //間隔
            ll c = 1;
            while(c < s.length()){
                ll t_k = 1;
                ll h = 0;
                //今見ている場所
                ll posi = j + c;
                while(posi < s.length()){
                    if(s[posi] == store_name[t_k]){
                        t_k++;
                    }else{
                        break;
                    }
                    if(t_k == store_name.length()){
                        //cout << "atari" << endl; 
                        return true;
                    }
                    posi += c;
                    h++;
                }
                //cout << endl;
                c++;
            }
            
        }
    }

    return false;
}

int main(){
    ll N;
    cin >> N;
    string store_name;
    cin >> store_name;
    //vector<string > S;
    
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        if(solv(store_name, s)){
            //cout << i << endl;
            ans++;
        } 

    }

    cout << ans << endl;

}