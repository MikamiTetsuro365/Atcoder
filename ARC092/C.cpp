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

    ll N; 
    cin >> N;

    vector<pi > ab;
    vector<pi > cd;

    for(ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }

    for(ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        cd.push_back(make_pair(a, b));
    }

    //sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    ll ans = 0;
    pi t_pair = make_pair(-1, -1);

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(cd[i].first > ab[j].first && ab[j].first >= 0){
                if(cd[i].second > ab[j].second){
                    if(t_pair.first < ab[j].second){
                        t_pair = make_pair(ab[j].second, j);
                    }
                }
            }
        }

        //ペア決定
        if(!(t_pair.first == -1)){
            ans++;
            //ペアにしたやつはもうペアにしない
            ab[t_pair.second].first = -1;
            ab[t_pair.second].second = -1;
            t_pair = make_pair(-1, -1);
        }

    }



    cout << ans<< endl;

}