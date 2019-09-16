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
#include <queue>
#include <functional> 

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){

    ll N, K;
    cin >> N >> K;


    vector<ll > V(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> V[i];
    }

    sort(V.rbegin(), V.rend());

    //入力の最大値が求めるK未満のとき成り立たない
    if(V[0] < K ){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    //初期化
    ll n_gcd = V[0];
    //1かKになれる倍数が出てくれば良い
    for(ll i = 1; i < N; i++){
        if(i == 1){
            n_gcd = gcd(V[i-1], V[i]);
        }else{
            n_gcd = gcd(n_gcd , V[i]);
        }
    }  

    if(K % n_gcd == 0){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

} 