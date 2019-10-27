#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    ll N; cin >> N;
    // 1＝プラス -1=マイナス
    vector<ll > kigou;
    vector<ll > num;

    for(ll i = 0; i < N; i++){
        char t; cin >> t;
        if(t == '+'){
            num.push_back(19);
        }else if(t == '-'){
            num.push_back(-19);
        }else{
            num.push_back(t-48);
        }
    }

    ll mx_ans = -INF;
    ll mn_ans = INF;
    do{
        ll t_ans = 0;
        if(num[0] == 19 || num[0] == -19 || num[N-1] == 19 || num[N-1] == -19) continue;
        
        
        for(ll i = 0; i < num.size(); i++){
            
            cout << num[i];
        }
        cout << endl;
    }while(next_permutation(num.begin(), num.end()));


 
}