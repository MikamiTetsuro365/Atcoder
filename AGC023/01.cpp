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
    //累積和をとって同じ数字が現れたところでの組み合わせを考えるだけ
    
    ll N;
    cin >> N;
    vector<ll > A(N);
    
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    //累積和
    vector<ll > ruiseki;
    ruiseki.push_back(0);
    for(ll i = 0; i < N; i++){
        sum += A[i];
        ruiseki.push_back(sum);
    }   
    //累積わにMOD
    ll ans = 0;
    //連想配列用意
    map<ll, ll> result;
    
    for(ll i = 0; i < ruiseki.size(); i++){
        result[ruiseki[i]]++;
    }     
    
    for(auto i = result.begin(); i != result.end() ; ++i){
        ll value = i->second;
        if(value == 1) continue;
        ans += value * (value - 1) / 2;
    }

    cout << ans << endl;


} 