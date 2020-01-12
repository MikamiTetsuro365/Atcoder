#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, M; cin >> N >> M;

    vector<vector<string > > vec(N + 1919);

    for(ll i = 0; i < M; i++){
        ll p; string s; cin >> p >> s;
        vec[p-1].push_back(s);
    }

    ll wa = 0;
    ll ac = 0;
    for(ll i = 0; i < N; i++){
        bool f = false;
        ll tmp = 0;
        for(ll j = 0; j < vec[i].size(); j++){
            //cout << vec[i][j] << " ";

            if(vec[i][j] == "AC"){
                ac++;  
                f = true;
                break;
            }
            if(vec[i][j] == "WA"){
                tmp++;
            }
            
        }   
        if(f == true){
            wa += tmp;
        }     
    }


    cout << ac << " " << wa << endl;


}