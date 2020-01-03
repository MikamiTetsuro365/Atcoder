#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//二分探査なのは分かる
int main() {

    ll A, B, Q;
    cin >> A >> B >> Q;

    vector<pi > s;
    vector<pi > t;

    vector<pi > matome;
    //0＝寺 1=社
    for(ll i = 0; i < A; i++){
        ll x = 0; cin >> x;
        s.push_back(make_pair(x, 0));
        matome.push_back(make_pair(x, 0));
    }
    for(ll i = 0; i < B; i++){
        ll x = 0; cin >> x;
        t.push_back(make_pair(x, 1));
        matome.push_back(make_pair(x, 1));
    }

    //クエリQ
    for(ll i = 0; i < Q; i++){
        ll x = 0; cin >> x;
        matome.push_back(make_pair(x, 2));
    }

    //番兵
    //matome.push_back(make_pair(-1,-1));
    //matome.push_back(make_pair(-1,INF));
    sort(matome.begin(), matome.end());

    vector<ll > ans;
    ll len = A + B + Q;
    for(ll i = 0; i < len; i++){
        if(matome[i].second == 2){
            ll f1 = 0;
            ll f2 = 0;
            ll f3 = 0;
            ll f4 = 0;

            //左右を確かめる
            if(i > 1){
                if(matome[i-1].second == 0){
                    f1 = 0;
                    if(i - 2 >= 0){
                        if(matome[i-1].second == 0) f2 = 0;
                        //else if()
                    }else{
                        f2 = 3;
                    }
                }
            }else{
                f1 = 3;
                f2 = 3;
            }

            if(i != len - 1){
                if(matome[i+1].second == 0) f1 = true;
            }else{
                f3 = 3;
                f4 = 3;
            }



        }
    }


}