#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll B;
void solve(){
    string s = "";
    for(ll i = 0; i < 10; i++){
        cout << i + 1 << endl << flush;
        char c;
        cin >> c;
        s += c;
    }
    cout << s << endl << flush;
    cin >> s;
}
int main(){
    
    ll T;
    cin >> T >> B;
    for(ll t = 0; t < T; t++){
        if(B == 10){
            solve();
        }else{
            vector<ll > G(19, -1);
            //最初の5個と最後の5個をとりあえず確認
            for(ll i = 1; i <= 10; i++){
                cout << i << endl << flush;
                char c1;
                cin >> c1;
                cout << 20-i+1 << endl << flush;
                char c2;
                cin >> c2;
                if(c1 == c2) G[i] = 1;
            }
            //最後の10回で確定させる
            vector<ll > ans(29, 0);
            for(ll i = 1; i <= 10; i++){
                cout << i << endl << flush;
                char c;
                cin >> c;
                ans[i] = c - '0';
                if(G[i] == -1){
                    if(ans[i] == 0){
                        ans[20-i+1] = 1;
                    }else{
                        ans[20-i+1] = 0;
                    }
                    
                }else{
                    ans[20-i+1] = ans[i];
                }
            }
            
            string s_ans;
            for(ll i = 1; i <= B; i++){
                s_ans += ans[i] + '0';
            }       
            cout << s_ans << endl << flush;
            char res;
            cin >> res;
        }

        
    }

    return 0;
}