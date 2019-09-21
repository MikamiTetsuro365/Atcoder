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
#include <queue>

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<ll > H(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> H[i];  
    }

    ll ans = 0;    
    
    for(;;){
        ll i = 0;
        ll max = *std::max_element(H.begin(), H.end());
        if(max == 0) break;

        while(i < N){
            if(H[i] == 0){
                i++;
                continue;
            }else{
                ans++;
                while(i < N && H[i] > 0){
                    H[i]--;
                    i++;
                }
            }
        }

    }

    cout << ans << endl;


} 