#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    ll A, B;
    cin >> A >> B;
    //ピザのカロリー
    ll pizza_k;
    cin >> pizza_k;
    //トッピングのカロリー
    vector<pair<ll, ll > > t;
    t.push_back(make_pair(0, 0));
    for(ll i = 0; i < N; i++){
        ll in; cin >> in;
        t.push_back(make_pair(in, 1));
    }
    sort(t.begin(), t.end());

    /*
    vector<ll > sum(N + 1, 0);
    for(ll i = 0; i < N; i++){
        sum[i + 1] = sum[i] + t[i];
    }
    */

    //確認
    /*
    for(ll i = 0; i < rui_sum.size(); i++){
        cout << rui_sum[i] << endl;
    }
    */
    ll ans = 0;
    ll t_ans = 0;
    ll left = 0;
    ll right = 0;
    ll cal = pizza_k;
    ll cost = A;
    while(left <= N){
        //cout << "a" << endl;
        while(right <= N){
            cal += t[right].first;
            cost += t[right].second * B;
            t_ans = cal / cost;
            ans = max(ans, t_ans); 
            //cout << t_ans << endl;
            right++;
        }

        cal -= t[left].first;
        cost -= t[left].second * B;
        t_ans = cal / cost;
        //cout << t_ans << endl;
        ans = max(ans, t_ans); 
        left++;  
    }

    cout << ans << endl;

}