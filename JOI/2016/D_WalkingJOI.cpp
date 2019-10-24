#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll N, M, L;
ll mx, mn;

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
        if(l == 2){
            l = -1;
        }
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

        //↑でループの限界を超えたらjはプラス1されているのを忘れずに!
        if(h[j-1].second == -1 && i != 0){
            memo.push_back(h[i].first);
        }else if(h[j-1].second == 1 && j - 1 != h.size()-1){
            memo.push_back(h[j-1].first);
        }

        i = j;
    }

    //東からきた人と西から来た人が合う場所の計算
    for(ll i = 0; i < memo.size(); i+=2){
        meeting.insert((memo[i] + memo[i + 1]) / 2);
        //cout << (memo[i] + memo[i + 1]) / 2 << " ";
    }

    //上限と下限
    mx = *(meeting.rbegin());
    mn = *(meeting.begin());

    //検索
    vector<ll > ans;
    for(ll i = 0; i < L; i++){
        ll search; cin >> search; search--;
        
        //現在地と次の考えうる移動先
        ll now = h[search].first;
        ll muki = h[search].second;
        ll to = now + M * muki;

        //上限と下限外なら誰とも出会うことはないので移動し続けられる
        if(muki == 1 && mx >= now){            
            ll num = ijo(meeting, now);
            to = min(num, to);
            //ans.push_back(min(num, to));

        }else if(muki == -1 && mn <= now){
            ll num = ika(meeting, now);
            to = max(num, to);
            //ans.push_back(max(num, to));
        }
        ans.push_back(to);
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}