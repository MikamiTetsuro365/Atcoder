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

    ll ans = 0;

    if(K % 2 == 0){
        ans = pow(N / K, 3);
        //K/2余る数
        ll t = 0;
        for(ll i = 1; i <= N; i++){
            if(i % K == K / 2){
                t++;
            }
        }
        ans += pow(t, 3);

        cout << ans << endl;

    }else{
        ans = pow(N / K, 3);
        cout << ans << endl;
    }

} 
