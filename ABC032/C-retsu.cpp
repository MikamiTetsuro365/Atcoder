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
    ll N, K;
    cin >> N >> K;
    vector<ll > vec(N, 0);

    //途中で0が入ると答えはN
    int zero_f = 0;
    for(ll i = 0; i < N; i++){
        cin >> vec[i];
        if(vec[i] == 0){
            zero_f = 1;
        }
    }

    if(zero_f == 1){
        cout << N << endl;
        return 0;
    }

    ll nextLeft = 0;
    ll nextRight = 0;

    ll temp = 1;
    ll ans = 0;

    while(nextRight < N){
        if(temp * vec[nextRight] <= K){
            temp *=  vec[nextRight];
            nextRight++;
            ans = max(ans, nextRight - nextLeft);
        }else if(nextLeft == nextRight){
            nextRight++;
            nextLeft++;
        }else{
            temp /= vec[nextLeft];
            nextLeft++; 
        }
    }

    cout << ans << endl;
} 