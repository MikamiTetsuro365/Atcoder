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
typedef long long int ll;

int main(){
    ll N;
    cin >> N;
    vector<ll > A(N);
    //入力
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }  
    //累積和
    ll sum = 0;
    vector<ll > ruiseki;
    ruiseki.push_back(0);
    for(ll i = 0; i < N; i++){
        sum += A[i];
        ruiseki.push_back(sum);
    }   

    ll r = 1;
    ll l = 0;
    sum = ruiseki[1];
    ll ans = 0;
    //しゃくとり法
    while(r <= N && l <= N ){
        //cout << l << ":" << r << ":" << sum << endl;
        if(sum == N){
            ans++;
            l++;
        }
        if(sum > N){
            l++;
        }
        if(sum < N){
            r++;
        }
        sum = ruiseki[r] - ruiseki[l];
    }

    cout << ans << endl;


} 