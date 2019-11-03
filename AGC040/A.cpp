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

    if(s[0] == '<'){
        if(vec.size() % 2 != 0){
            vec.push_back(1);
        }
        for(ll i = 1; i < vec.size(); i+=2){
            //cout << vec[i] << " " << vec[i-1]  << endl;
            if(vec[i] >= vec[i-1]){
                ll e1 = vec[i];
                ans += sum(0, vec[i-1]-1);            
                ans += sum(0 , e1);
                //cout << sum(s1, e1) <<endl;
                //cout << sum(0, vec[i] - 1) << endl;
            }else{
                ans += sum(0, vec[i-1]);
                ll e2 = vec[i] - 1;
                ans += sum(0, e2);
                //cout << sum(0, vec[i-1]) + sum(0, e1) <<endl;
            }
            //cout << ans << endl;
        }
    }else{
        ans += sum(0, vec[0]);
        if((vec.size()-1) % 2 != 0){
            vec.push_back(1);
        }
        for(ll i = 2; i < vec.size(); i+=2){
            if(vec[i] >= vec[i-1]){
                ll e1 = vec[i];
                //cout << s1 << " " << e1 << endl;
                ans += sum(0, vec[i-1]-1);            
                ans += sum(0 , e1);
                //cout << sum(s1, e1) + sum(0, vec[i] - 1) <<endl;
            }else{
                ans += sum(0, vec[i-1]);
                ll e2 = vec[i] - 1;
                ans += sum(0, e2);
                //cout << sum(0, vec[i-1]) + sum(0, e1) <<endl;
            }
            //cout << ans << endl;
        }
    }

    cout << ans << endl;
}