#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    string s; cin >> s;
    ll x, y; cin >> x >> y;

    vector<ll > vec;
    if(s[0] == 'T'){
        vec.push_back(0);
    }
    for(ll i = 0; i < s.size();){
        ll j = i;
        //一緒の間ループを回し続けて，切れ目を探す
        if(s[j] == 'T'){
            if(s[j+1] == 'T'){
                vec.push_back(0);
            }
            j++;
            i = j;
            continue;
        }
        while(j < s.size() && s[j] == s[i]){
            j++;
        }
        vec.push_back(j - i);
        //次の始点へすっ飛ばす
        i = j;
    }

    //確認
    /*
    for(ll i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    */
    

    //xとy軸の移動しうる点を交互に求めていく(Tの数だけXまたはY軸に沿って移動するかが変化する)


    vector<map<ll , ll> >x_dp(vec.size()+10);
    vector<map<ll , ll> >y_dp(vec.size()+10);
    x_dp[0][0] = 1;
    y_dp[0][0] = 1;
    y_dp[1][0] = 1;

    ll i = 0;
    
    while(i < vec.size()){
        
        if(i == 0){
            x_dp[1][vec[i]] = 1;
            x_dp[2][vec[i]] = 1;
            //cout << x_dp[1][vec[i]] << endl;
        }else if(i != 0 && i % 2 == 1){
            //cout << i << " " <<  vec[i] << endl;
            auto begin = y_dp[i].begin(), end = y_dp[i].end();
            for (auto iter = begin; iter != end; iter++) { 
                y_dp[i + 1][iter->first + vec[i]] = 1; 
                y_dp[i + 1][iter->first - vec[i]] = 1; 
                y_dp[i + 2][iter->first + vec[i]] = 1; 
                y_dp[i + 2][iter->first - vec[i]] = 1; 
            }      
        }else if(i != 0 && i % 2 == 0){
            //cout << i << " " << vec[i] << endl;
            auto begin = x_dp[i].begin(), end = x_dp[i].end();
            for (auto iter = begin; iter != end; iter++) {
                //cout << iter->first + vec[i] << " " << iter->first - vec[i] << endl;
                x_dp[i + 1][iter->first + vec[i]] = 1; 
                x_dp[i + 1][iter->first - vec[i]] = 1; 
                x_dp[i + 2][iter->first + vec[i]] = 1; 
                x_dp[i + 2][iter->first - vec[i]] = 1; 
            }    
        }

        i++;
    }


    if(x_dp[vec.size()][x] == 1 && y_dp[vec.size()][y] == 1 ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}