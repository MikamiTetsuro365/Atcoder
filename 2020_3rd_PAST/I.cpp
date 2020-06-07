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
    
    vector<ll > tate(N, 0);
    vector<ll > yoko(N, 0);

    for(ll i = 1; i <= N; i++){
        tate[i-1] = i;
        yoko[i-1] = i;
        //cout << i << endl;
    }

    vector<ll > ans;
    ll t = 0;
    ll t1 = 0;
    ll t2 = 0;
    for(ll i = 0; i < Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll a, b;
            cin >> a >> b;
            if(a == b) continue;
            
            if(t == 0) swap(yoko[a-1], yoko[b-1]);
            else swap(tate[a-1], tate[b-1]); 

            t1 = (t1 + 1) % 2;

        }else if(q == 2){
            ll a, b;
            cin >> a >> b;
            if(a == b) continue;
            
            if(t == 0) swap(tate[a-1], tate[b-1]); 
            else swap(yoko[a-1], yoko[b-1]);

            t2 = (t2 + 1) % 2;

        }else if(q == 3){
            t = (t + 1) % 2;
        }else{
            ll a, b;
            cin >> a >> b;
            //cout << a << " " << b << endl;
            if(t == 0){
                //cout << N * (tate[a]-1) + yoko[b]-1 << endl;
                ans.push_back(N * (yoko[a-1]-1) + (tate[b-1]-1));
            }else{
                ans.push_back(N * (tate[N-b]-1) + (yoko[N-a]-1));
            }
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }


}