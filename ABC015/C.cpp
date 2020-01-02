#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

vector<vector<ll > > vec;

bool ans = true;

ll N, K;

void dfs(ll d = 0, ll x = 0){

    if(d == N){
        //cout << d << " " <<  x << endl;
        if(x == 0){
            //cout << "false" << endl;
            ans = false;
        }
        return;
    }

    for(ll i = 0; i < K; i++){

        if(d == 0){
            dfs(d + 1, vec[d][i]);
        }else{
            dfs(d + 1, x^vec[d][i]);
        }

        
    }
}

int main(){

    cin >> N >> K;

    vec.assign(N, vector<ll>());

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < K; j++){
            ll t; cin >> t;
            vec[i].push_back(t);
        }
    }

    dfs();

    if(ans == true){
        cout << "Nothing" << endl;
    }else{
        cout << "Found" << endl;
    }
    

}
