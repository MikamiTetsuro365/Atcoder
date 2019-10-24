#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M, L;

ll ijo(set<ll > s, ll t){
    return *s.lower_bound(t);
}
ll ika(set<ll > s, ll t){
    auto it = s.lower_bound(t);
    if(it == s.end()){
        it--;
    }else if(*it > t){
        it--;
    }
    return *it;
}

int main(){

    cin >> N >> M >> L;
    vector<pi > h;

    //前処理
    for(ll i = 0; i < N; i++){
        ll p, l; cin >> p >> l;
        h.push_back(make_pair(p, l));
    }
    //1のとき東向き（右） 2のとき西向き(左)
    set<ll > meeting;
    vector<ll > memo;
    //前処理
    for(ll i = 0; i < h.size();){
        ll j = i;

        while(j < h.size() && h[i].second == h[j].second){
            j++;
        }

        if(h[j-1].second == 2){
            if(i == 0) meeting.insert(-INF); //西へ突き進んでしまい誰とも出会わない
            else memo.push_back(h[i].first);
        }
        if(h[j-1].second == 1){
            if(i == h.size()-1) meeting.insert(INF);//東へ突き進んでしまい誰とも出会わない
            else memo.push_back(h[j-1].first);
        }
        i = j;
    }
    //東からきた人と西から来た人が合う場所
    for(ll i = 0; i < memo.size(); i+=2){
        meeting.insert((memo[i] + memo[i + 1]) / 2);
        //cout << (memo[i] + memo[i + 1]) / 2 << endl;
    }

    //検索
    vector<ll > ans;
    for(ll i = 0; i < L; i++){
        ll search; cin >> search; search--;
        ll t = 0;
        if(h[search].second == 1){
            //t = h[search].first + M;
            t = h[search].first;
            ll num = ijo(meeting, t);
            
            if(num <= t + M){
                ans.push_back(num);
            }else{
                ans.push_back(t + M);
            }

        }else{
            t = h[search].first;
            ll num = ika(meeting, t);

            if(num >= t - M){
                ans.push_back(num);
            }else{
                ans.push_back(t - M);
            }
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}