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

using namespace std;
typedef long long ll;

int main(){

    ll M, D;
    cin >> M >> D;

    ll ans = 0;
    for(ll i = 1; i <= M; i++){
        for(ll j = 1; j <= D; j++){
            //cout << j << endl;
            if(j % 10 < 2){
                continue;
            }
            if(j / 10 < 2){
                continue;
            }
            //cout << j << " " << j % 10  << " " << j / 10 << endl;
            if(i == (j / 10) * (j % 10) ){
                ans++;
            }
        }
    }

    cout << ans << endl;

}