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
ll Q;
vector<string > T;
vector<string > D;
ll isOK(ll posi, string s){
    //ll ab_posi = posi;
    for(ll i = 0; i < Q; i++){
        if(s.substr(posi,1) == T[i]){
            if(D[i] == "L"){
                posi--;
            }else{
                posi++;
            }
        }

        //左よりすぎるとだめよ
        if(posi < 0){
            return 0;
        }else if(posi > N - 1){
        //右よりすぎるとだめよ
            return 1;
        }
    }
    return 2;
}

int main(){
    //multimap<string, ll> mp;
    //multimap<string, ll> mp2;
    cin >> N >> Q;
    string s;
    cin >> s;

    string t, d;
    for(ll i = 0; i < Q; i++){
        cin >> t >> d;
        T.push_back(t);
        D.push_back(d);
    } 

    //操作
    ll left = -1;
    ll right = N;

    //二部探査
    //左
    while(abs(right-left) > 1){
        ll mid = left + (right - left) / 2;
        if(isOK(mid, s) == 0) left = mid;
        else right = mid;
    }

    ll mxLeft = left;

    left = -1;
    right = N;
    //右
    while(abs(right-left) > 1){
        ll mid = left + (right - left) / 2;
        if(isOK(mid, s) == 1) right = mid;
        else left = mid;
    }  
    ll mxRight = right;
    

    ll ans = mxRight - mxLeft - 1;

    cout << ans << endl;
} 