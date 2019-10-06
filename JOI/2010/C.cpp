#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;


int main(){
    ll N, M;
    cin >> N >> M;
    
    vector<vector<ll > > vec(M , vector<ll >(2, 0));
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll a, b; cin >> a >> b;
        vec[i][0] = a;
        vec[i][1] = b;
    }

    vector<vector<ll > > ans(2 , vector<ll >(N + 1, 0));

    //友達
    for(ll i = 0; i < M; i++){
        if(vec[i][0] == 1){
            ans[0][vec[i][1]] = 1;
        }else if(vec[i][1] == 1){
            ans[0][vec[i][0]] = 1;
        }
    } 
    //友達の友達
    for(ll i = 0; i < N + 1; i++){
        if(ans[0][i] == 1){
            for(ll j = 0; j < M; j++){
                if(vec[j][0] == i){
                    if(ans[0][vec[j][1]] == 1) continue;
                    ans[1][vec[j][1]] = 1;
                }else if(vec[j][1] == i){
                    if(ans[0][vec[j][0]] == 1) continue;
                    ans[1][vec[j][0]] = 1;
                }
            }
        }
    }     

    ll friend_num = 0;
    for(ll i = 0; i < 2; i++){
        for(ll j = 2; j < N + 1; j++){
            if(ans[i][j] == 1){
                friend_num++;
            }
        }   
    }     
    cout << friend_num << endl;

}