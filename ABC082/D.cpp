#include "bits/stdc++.h"
#include <unordered_set>
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


    vector<unordered_set<ll > >x_dp(vec.size()+10);
    vector<unordered_set<ll > >y_dp(vec.size()+10);
    x_dp[0].insert(0);
    y_dp[0].insert(0);
    y_dp[1].insert(0);

    ll i = 0;
    
    while(i < vec.size()){
        
        if(i == 0){
            x_dp[1].insert(vec[i]);
            x_dp[2].insert(vec[i]);
        }else if(i != 0 && i % 2 == 1){
            //cout << i << " " <<  vec[i] << endl;
            for(auto y : y_dp[i]){
                y_dp[i + 1].insert(y + vec[i]); 
                y_dp[i + 1].insert(y - vec[i]); 
                //次の次は更新されないので
                y_dp[i + 2].insert(y + vec[i]); 
                y_dp[i + 2].insert(y - vec[i]); 
            }      
        }else if(i != 0 && i % 2 == 0){
            //cout << i << " " << vec[i] << endl;
            for(auto x : x_dp[i]){
                //cout << iter->first + vec[i] << " " << iter->first - vec[i] << endl;
                x_dp[i + 1].insert(x + vec[i]); 
                x_dp[i + 1].insert(x - vec[i]); 
                //次の次は更新されないので
                x_dp[i + 2].insert(x + vec[i]); 
                x_dp[i + 2].insert(x - vec[i]); 
            }    
        }

        i++;
    }

    ll posi = vec.size();
    if(x_dp[posi].find(x) != x_dp[posi].end() && y_dp[posi].find(y) != y_dp[posi].end() ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}