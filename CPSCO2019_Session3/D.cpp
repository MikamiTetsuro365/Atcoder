#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//細かい条件を考える系
int main() {

    ll N;
    cin >> N;
    
    string S;
    cin >> S;
    
    //NGパターン列挙
    //先頭NG
    if(S[0] == 'G' || S[0] == 'B'){
        cout << "No" << endl;
        return 0;
    }
    //末尾NG
    if(S[S.length()-1] == 'R' || S[S.length()-1] == 'G'){
        cout << "No" << endl;
        return 0;
    }
    //末尾-1 NG
    if(S[S.length()-2] == 'R'){
        cout << "No" << endl;
        return 0;
    }
    
    //グリーンは出現したかフラグ
    bool f = false;
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'G'){
            //グリーンは連続して出現しない
            if(S[i+1] == 'G'){
                cout << "No" << endl;
                return 0;                
            }
            f = true;
        }
        //RとBも連続して出現しない
        if(S[i] == 'R' && S[i+1] == 'B'){
            cout << "No" << endl;
            return 0;              
        }
    }
    if(f == false) cout << "No" << endl;
    else cout << "Yes" << endl;
    
}