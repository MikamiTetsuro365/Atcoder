#include "bits/stdc++.h" 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
//ll MOD = 1000000007;
ll INF = 11451419194545;

ll G[10019][10019];

int main() {

    ll T;
    cin >> T;

    //準備
    ll idx = 0;
    for(ll i = 5000; i <= 10000; i++){
        for(ll j = 5000; j <= 10000; j++){
            G[i][j] = (j-5000) + idx;
        }
        idx++;
    }

    idx = 0;
    for(ll i = 5000; i >= 0; i--){
        for(ll j = 5000; j <= 10000 ; j++){
            G[i][j] = (j-5000) + idx;
        }
        idx++;
    }
    
    idx = 0;
    for(ll i = 5000; i <= 10000; i++){
        for(ll j = 5000; j >= 0 ; j--){
            G[i][j] = abs(j-5000) + idx;
        }
        idx++;
    }

    idx = 0;
    for(ll i = 5000; i >= 0; i--){
        for(ll j = 5000; j >= 0 ; j--){
            G[i][j] = abs(j-5000) + idx;
        }
        idx++;
    }

    // for(ll i = 4990; i <= 5010; i++){
    //     for(ll j = 4990; j <= 5010; j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << G[1500][1500] << endl;

    vector<string> ANS;
    for(ll i = 0; i < T; i++){
        ll x, y;
        cin >> x >> y;
        x += 5000;
        y += 5000;
        string S;
        cin >> S;
        ll ans = INF;
        for(ll j = 0; j < S.length(); j++){
            if(S[j] == 'S'){
                y--;
            }
            if(S[j] == 'N'){
                y++;
            }
            if(S[j] == 'E'){
                x++;
            }
            if(S[j] == 'W'){
                x--;
            }
            
            ll t_ans = G[y][x];
            //cout << x << " " << y << " " << G[y][x] << endl;

            //先回りできるか？
            if(t_ans <= j + 1){
                //先回りできたら，何分後にくる？
                if(t_ans == j+1){
                    ans = min(t_ans, ans);
                }else
                {
                    ans = min(t_ans + (j+1 - t_ans) , ans) ;
                }    
            }
        }
        //cout << ans << endl;
        if(ans == INF){
            ANS.push_back("IMPOSSIBLE");
        }else{
            ANS.push_back(to_string(ans));
        }
    }

    for(ll i = 0; i < T; i++){
        cout << "Case #" << i + 1 << ": " << ANS[i] << endl;
    }

    //確認
    // for(ll i = 0; i < 10; i++){
    //     for(ll j = 0; j < 10; j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }


}