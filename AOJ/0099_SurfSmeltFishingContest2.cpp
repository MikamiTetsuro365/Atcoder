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

    ll N, Q;
    cin >> N >> Q;

    vector<pi > sum;
    map<ll, ll> mp;
    vector<pi > result;
    priority_queue<pi > que;

    ll idx = 1;
    ll top = -1;
    for(ll i = 0; i < Q; i++){
        ll a, v; cin >> a >> v;
        //今までに追加された要素か？
        if(mp[a] == 0){
            mp[a] = idx;
            idx++;
            sum.push_back(make_pair(v, a));
        }else{
            sum[mp[a]-1].first += v;
        }
        
        //はじめての入力か？
        ll a_idx = mp[a]-1;
        ll top_idx = mp[top]-1;
        if(top == -1){
            top = a;
        }else{
            if(top == a){
                if(v < 0){
                    pi tmp = make_pair(sum[a_idx].first, sum[a_idx].second);
                    for(ll j = 0; j < sum.size(); j++){
                        if(tmp.first < sum[j].first){
                            tmp.first = sum[j].first;
                            tmp.second = sum[j].second;
                        }else if(tmp.first == sum[j].first && tmp.second > sum[j].second){
                            tmp.second = sum[j].second;
                        }
                    }
                    top = tmp.second;
                }
            }else{
                if(sum[top_idx].first < sum[a_idx].first){
                    top = a;
                }
                if(sum[top_idx].first == sum[a_idx].first && top > sum[a_idx].second){
                    top = a;
                }
            }
        }
        
        result.push_back(make_pair(top, sum[mp[top]-1].first));

    }

    for(ll i = 0; i < Q; i++){
        cout << result[i].first << " " << result[i].second << endl;
    }

}