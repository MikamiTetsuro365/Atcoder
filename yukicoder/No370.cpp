#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;


int main(){

    ll N, M;
    cin >> N >> M;
    ll ans = 1145141919;
    vector<ll > d(M, 0);

    for(ll i = 0; i < M; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    ll i = 0;
    while(i < M && i + N - 1 < M){
        //cout << i << " " << i + N - 1 << endl;
        ll t_ans = 0;
        if(d[i] < 0 && d[i+N-1] < 0){
            t_ans = abs(d[i]);
        }else if(d[i] <= 0 && d[i+N-1] >= 0){
            t_ans = d[i+N-1] - d[i] + min(abs(d[i]), d[i+N-1]);
        }else{
            t_ans = d[i+N-1];
        }
        ans = min(ans, t_ans);
        i++;
    }

    cout << ans << endl;
} 