#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//寝かしたい
int main() {
    //ifstream in("23.txt");
    //cin.rdbuf(in.rdbuf());

    ll N;
    cin >> N;

    vector<ll > minus;
    vector<ll > plus;


    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(t < 0) minus.push_back(t);
        else plus.push_back(t);
    }

    sort(minus.rbegin(), minus.rend());

    vector<pi > ans;
    ll mx = 0;

    for(ll i = 1; i < minus.size(); i++){
        ans.push_back(make_pair(minus[i-1], minus[i]));
        minus[i] = minus[i-1] - minus[i];
        cout << minus[i] << endl;
    }

    if(!minus.empty()) plus.insert(plus.begin(), minus[minus.size()-1]);
    sort(plus.begin(), plus.end());
   

    /*
    for(ll i = 0; i < plus.size(); i++){
        cout << plus[i] << endl;
    }
    */

    for(ll i = 0; i < plus.size()-1; i++){
        if(i == plus.size()-2){
            ans.push_back(make_pair(plus[i+1], plus[i]));
            plus[i+1] = plus[i+1] - plus[i];
            continue;
        }

        /*
        if(plus[i+1] < plus[i]){
            ans.push_back(make_pair(plus[i+1], plus[i]));
            plus[i+1] = plus[i+1] - plus[i];
            continue;            
        }
        */

        ans.push_back(make_pair(plus[i], plus[i+1]));
        plus[i+1] = plus[i] - plus[i+1];
    }

    //答え
    cout << plus[plus.size()-1] << endl;
    /*for(ll i = 0; i < N-1; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }*/


}