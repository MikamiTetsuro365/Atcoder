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
#include <functional>

using namespace std;
typedef long long int ll;

int main(){

    ll N = 0;
    cin >> N;
    vector<ll > v(N, 0);
    vector<ll > c(N, 0);
    ll ans = 0;
    ll flg = 0;

    for(ll i = 0; i < N; i++){
        cin >> v[i];
    }

    for(ll i = 0; i < N; i++){
        //同じ数字が続くとき
        while(i+1 < N && v[i] == v[i+1]) i++;

        if(v[i] < v[i+1]){
            //単調増加
            while(i+1 < N && v[i] <= v[i+1]) i++;

        }else if(v[i] > v[i+1]){
            //単調減少
            while(i+1 < N && v[i] >= v[i+1]) i++;
        }
        ans++; 
    }


    cout << ans << endl;

} 