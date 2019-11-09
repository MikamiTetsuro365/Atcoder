#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){
    ll N, M;
    cin >> N >> M;

    vector<ll > line(N+10, 0);

    vector<ll > left(N, 0);
    vector<ll > right(N, 0);

    for(ll i = 0; i < M; i++){
        ll l, r, c = 0; cin >> l >> r >> c;
        l--;
        r--;
        
        if(left[l] == 0){
            left[l] = c;
        }else{
            left[l] = min(left[l], c);
        }

        if(right[r] == 0){
            right[r] = -1 * c;
        }else{
            right[r] = max(right[r], -1 * c);
        }


    }

    for(ll i = 0; i < N; i++){
        cout << left[i] << " ";
    }
    cout << endl;
    for(ll i = 0; i < N; i++){
        cout << right[i] << " ";
    }
    cout << endl;

    /*
    if(line[0] > 0 && line[N-1] < 0){
        cout << "-1" << endl;
    }else{
        //ans
    }
    */

}