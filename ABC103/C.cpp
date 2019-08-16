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

    ll N;
    cin >> N;
    vector<ll > a(N,0);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll t = 0;
        cin >> t;
        //あまりは0~t-1までしか出ない
        a[i] = t - 1;
        ans += t - 1;
    }

    cout << ans << endl;

    /* 
    sort(a.begin(), a.end());

    ll center = (a[0] + a[a.size()-1]) / 2;

    ll divide = 11451419191919;

    for(ll i = 0; i < N; i++){
        if(abs(center - a[i]) < divide){
            divide = a[i];
        }
    }

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        ans += divide / a[i];
    }

    cout << ans << endl;
    */


} 