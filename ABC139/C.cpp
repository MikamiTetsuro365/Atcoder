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

    ll N;
    vector<ll > H(N + 1, 0);
    cin >> N;
    H[0] = -1;
    for(ll i = 1; i <= N; i++){
        cin >> H[i];
    } 


    ll mx = 0;
    ll ans = 0;
    for(ll i = N; i >= 0; i--){
        //cout << H[i] << endl;
        if(H[i] <= H[i - 1]){
            ans++;
        }
        if(H[i] > H[i - 1]){
            mx = max(ans, mx);
            ans = 0;
        }
    } 

    cout << mx << endl;

}