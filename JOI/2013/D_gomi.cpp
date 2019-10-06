#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

priority_queue<ll > ans;
ll D, N;
ll max_ans = 0;

bool solv(vector<vector<ll > > use, ll d, ll pp = 0, ll p = 0, ll sum = 0){

    if(d > 1){ 
        sum += abs(pp-p);
    }
    pp = p;

    if(d == D){
        max_ans = max(sum, max_ans);
        return true;
    }

    for(ll i = 0; i < use[d].size(); i++){
        //cout << use[d].size() << endl;
        solv(use, d + 1, pp , use[d][i], sum);
    }
 
    return true;
 
}

int main(){
    
    cin >> D >> N;

    vector<ll > temperature(D, 0);

    for(ll i = 0; i < D; i++){
        cin >> temperature[i];
    }

    vector<pair<ll, ll > > clo_temp;
    vector<pair<ll, ll > > clothes;

    for(ll i = 0; i < N; i++){
        ll a, b, c; cin >> a >> b >> c;
        clo_temp.push_back(make_pair(a, b));
        clothes.push_back(make_pair(c, i));
    }

    //前処理
    vector<vector<ll > > use;
    vector<ll > mn;
    vector<ll > mx;
    for(ll i = 0; i < D ; i++){
        vector<ll > tmp;
        ll t_mn = 114514;
        ll t_mx = -1;
        for(ll j = 0; j < N; j++){
            if(temperature[i] >= clo_temp[j].first && temperature[i] <= clo_temp[j].second){
                //tmp.push_back(clothes[j].first);
                //cout << clothes[j].first << " ";
                t_mn = min(t_mn, clothes[j].first);
                t_mx = max(t_mx, clothes[j].first);
            }
        }
        //cout << "min" << t_mn << "max" << t_mx <<endl;
        //mn.push_back(t_mn);
        //mx.push_back(t_mx);
        vector<ll > t_use;
        t_use.push_back(t_mn);
        t_use.push_back(t_mx);
        use.push_back(t_use);
    }
    
    solv(use, 0);
 
    cout << max_ans << endl;

}