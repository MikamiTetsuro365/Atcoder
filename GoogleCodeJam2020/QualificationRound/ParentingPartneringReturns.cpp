#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
int main(){

    ll N;
    cin >> N;
    
    for(ll i = 0; i < N; i++){
        ll M; cin >> M;
        vector<pair<pair<ll, ll>,ll> > SE;
        vector<char > ans(M, 'P');
        bool f = true;
        for(ll j = 0; j < M; j++){
            ll s, e;
            cin >> s >> e;
            SE.push_back(make_pair(make_pair(e, s), j));
        }
        
        sort(SE.begin(), SE.end());
        
        //状態把握
        ll C = 0;
        ll J = 0;
        
        ll t = 0;
        for(ll j = 0; j < M; j++){
            if(C > SE[j].first.second && J > SE[j].first.second){
                f = false;
                break;
            }else{
                if(C > SE[j].first.second && J <= SE[j].first.second){
                        J = SE[j].first.first;
                        ans[SE[j].second] = 'J';                    
                }else if(C <= SE[j].first.second && J > SE[j].first.second){
                        C = SE[j].first.first;
                        ans[SE[j].second] = 'C';                    
                }else{
                    if(C >= J){
                        C = SE[j].first.first;
                        ans[SE[j].second] = 'C';
                    }else{
                        J = SE[j].first.first;
                        ans[SE[j].second] = 'J';
                    }                    
                }

            }
            //cout << C << " " << J << endl;
            // if(t <= SE[j].first.second && ans[SE[j].second] == 'P'){
            //     ans[SE[j].second] = 'C';
            //     t = SE[j].first.first;
            // }
        }
        
        //choice J
        // t = 0;
        // for(ll j = 0; j < M; j++){
        //     if(t <= SE[j].first.second && ans[SE[j].second] == 'P'){
        //         ans[SE[j].second] = 'J';
        //         t = SE[j].first.first;
        //     }
        // }
        
        //check
        string p_ans;
        for(ll j = 0; j < M; j++){
            if(ans[j] == 'P') f = false;
            p_ans += ans[j];
        }

        if(f == false){
            cout <<"Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        }else{
            cout <<"Case #" << i+1 << ": " << p_ans << endl;
        }
        
        
        //cout <<"Case #" << i+1 << ": " << sumk << " " << cn_r << " " << cn_c << endl;

    }
}