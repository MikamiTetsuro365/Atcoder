#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//2日酔のときに出場しなくてよかった
int main(){

    string S;
    cin >> S;

    if(S.length() % 2 != 0){
        cout << "No" << endl;
        return 0;
    }else{
        for(ll i = 0; i < S.length(); i+=2){
            if(S[i] == 'h' && S[i+1] == 'i'){
                //大丈夫
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    // if(true){
    //     cout << "Yes" << endl;
    // }else{
    //     cout << "No" << endl;
    // }


}