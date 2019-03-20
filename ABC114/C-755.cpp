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


using namespace std;
typedef unsigned long long ll;

ll N;
ll ans = 0;
void enumeration(ll e, ll s){

    if(s == 9){
        return;
    }

    for(ll i = 3; i <= 7; i = i + 2){
        //cout << e * 10 + i << endl;
        ll t = e * 10 + i;
        bool f3 = 0, f5 = 0, f7 = 0;
        for(ll j = 0; j < s + 1; j++){

           // cout << t % 10 ;

            if(t % 10 == 3){
                f3 = 1;
            }
            if(t % 10 == 5){
                f5 = 1;
            }
            if(t % 10 == 7){
                f7 = 1;
            }

            t /= 10;

        }
        //cout << endl;
        
        if((f3 & f5 & f7) == 1 && e * 10 + i <= N){
            ans++;
            //cout << e * 10 + i << endl;
        }
        enumeration(e * 10 + i , s + 1 );
    }
}

int main(){

    cin >> N;
    enumeration(0, 0);

    cout << ans << endl;
}