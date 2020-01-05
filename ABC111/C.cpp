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

    ll n = 0;
    cin >> n;
    //奇数番
    vector<pi > odd(101000);
    for(ll i = 0; i < odd.size(); i++){
        odd[i].first = 0;
        odd[i].second = i+1;
    }
    //偶数番
    vector<pi > even(101000);
    for(ll i = 0; i < even.size(); i++){
        even[i].first = 0;
        even[i].second = i+1;
    }

    ll max_odd = -1;
    ll max_even = -1;
    
    for(ll i = 1; i <= n; i++){
        ll t; cin >> t;

        if(i % 2 == 1){
            even[t].first++;
            //max_even = max(max_even, even[t].first);
        }else{
            odd[t].first++;
            //max_odd = max(max_odd, odd[t].first);
        }
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    if(odd[0].second == even[0].second){
        ll t1_ans = n / 2 - odd[1].first + n / 2 - even[0].first;
        ll t2_ans = n / 2 - odd[0].first + n / 2 - even[1].first;
        
        cout << min(t1_ans, t2_ans) << endl;

    }else{
        cout << n / 2 - odd[0].first + n / 2 - even[0].first << endl;
    } 

}