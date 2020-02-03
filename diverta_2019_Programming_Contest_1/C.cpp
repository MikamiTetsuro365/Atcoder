#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 9223372036854775807;
//場合分け(終)
int main(){

    ll N;
    cin >> N;

    ll ans = 0;
    ll AB = 0;
    ll A = 0;
    ll B = 0;

    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        if(s.front() == 'B' && s.back() == 'A') AB++;
        else if(s.front() == 'B') B++;
        else if(s.back() == 'A') A++;
        
        for(ll j = 1; j < s.length(); j++){
            if(s[j-1] == 'A' && s[j] == 'B') ans++;
        } 
    }

    if(AB >= 1){
        AB--;
        if(A >= 1) AB++, A--;
        if(B >= 1) AB++, B--;
        ans += AB;
        ans += min(A, B);
    }else{
        if(A >= 1 && B >= 1) ans += min(A, B);    
    }
    
    cout << ans << endl;

}