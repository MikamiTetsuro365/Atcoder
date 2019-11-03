#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
vector<ll > vec;
vector<vector<ll > > vec2;

ll sum(ll a, ll b){
    ll ans = 0;
    for(ll i = a; i <= b; i++){
        ans+=i;
    }
    return ans;
}

int main(){

    string s;
    cin >> s;
    //圧縮
    for(ll i = 0; i < s.length();){
        ll j = i;
        //一緒の間ループを回し続けて，切れ目を探す
        while(j < s.length() && s[j] == s[i]){
            ++j;
        }
        vec.push_back(j - i);
        //次の始点へすっ飛ばす
        i = j;
    }

    ll ans = 0;
    ll idx = 0;
    //1つ飛ばす
    if(s[0] == '>'){
        ans += sum(0, vec[0]);
        idx = 1;
    }
    //番兵
    if((vec.size() + idx) % 2 != 0){
        vec.push_back(1);
    }
    for(ll i = 1 + idx; i < vec.size(); i+=2){
        if(vec[i] >= vec[i-1]){
            ans += sum(0, vec[i-1]-1);            
            ans += sum(0 , vec[i]);
        }else{
            ans += sum(0, vec[i-1]);
            ans += sum(0, vec[i] - 1);
        }
    }
    cout << ans << endl;
}