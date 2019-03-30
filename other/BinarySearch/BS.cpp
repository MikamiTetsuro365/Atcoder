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
#include <map>

using namespace std;
typedef long long ll;
ll N;
vector<ll > DATA;
ll check(ll posi){
    //ここに条件を書く
    if(posi == 0){
        return 0;
    }
    return 1;
}

int main(){

    cin >> N;
    for(ll i = 0; i < N; i++){
        DATA.push_back(0);
    }
    //操作
    ll left = -1;
    ll right = N;

    //二部探査
    //中央から左側を
    while(abs(right-left) > 1){
        ll mid = left + (right - left) / 2;
        if(check(mid) == 0) left = mid;
        else right = mid;
    }
    //とある条件を満たす最小値
    ll mxLeft = left;

    left = -1;
    right = N;
    //中央から右側を
    while(abs(right-left) > 1){
        ll mid = left + (right - left) / 2;
        if(check(mid) == 1) right = mid;
        else left = mid;
    }  
    //とある条件を満たす最小値
    ll mxRight = right;

} 