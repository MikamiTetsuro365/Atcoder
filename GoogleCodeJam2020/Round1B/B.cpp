#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll T;
    cin >> T;
    for(ll t = 0; t < T; t++){
        bool f = false;
        for(ll i = -7; i <= 7; i++){
            for(ll j = -7; j <= 7; j++){
                cout << i << " " << j << endl << flush;
                string s;
                cin >> s;             
                if(s == "CENTER"){
                    f = true;
                    break;
                }
            }             
            if(f == true) break;
        }        
    }

    return 0;
}