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

using namespace std;
typedef long long ll;


int main(){

    string S;
    cin >> S;

    bool b_flg = false;
    bool c_flg = false;

    S += "xxxx";

    ll ans = 0;
    ll a_count = 0;

    ll flg = 0;

    for(ll i = 0; i < S.length(); i++){
        //cout << S[i];
        if(S[i] == 'A'){
            a_count++;
            continue;
        }

        if(a_count > 0 && S[i] == 'B'){
            if(S[i + 1] == 'C'){
                ans += a_count;
                i += 1;
            }else
            {
                a_count = 0;
            }
            
        }else if(a_count > 0 && S[i] == 'C'){
            a_count = 0;
        }


        
    }

    cout << ans << endl;

}