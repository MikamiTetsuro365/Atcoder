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
ll N;

int main(){

    ll N, K;
    cin >> N >> K;
    ll ans1 = 0;
    ll ans2 = 0;
    ll ans3 = 0;
    
    for(ll i = 1; i <= N ; i++){
        if((3 * i) * 2 % K == 0){
            ans3++;
        }
        for(ll j = i + 1; j <= N; j++){
            if((2 * i + j) * 2 % K == 0){
                ans2++;
            }
            for(ll k = j + 1; k <= N; k++){
                //cout << i << " " << j << " " << k << endl;
                if((i + j + K) * 2 % K == 0){
                    ans1++;
                }
            }            
        }
    }

    cout << ans3 + ans2 * 3 + ans1 * 6 << endl;

} 