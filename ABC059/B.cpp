#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//文字列で単に比較したらだめ（丁寧に場合分けしよう）
int main() {

    string A, B;
    cin >> A >> B;

    if(A.length() > B.length()){
        cout << "GREATER" << endl;
    }else if(A.length() < B.length()){
        cout << "LESS" << endl;
    }else{
        if(A == B){
            cout << "EQUAL" << endl;
        }else{
            //先頭桁から辞書順でどっちが大きいか確認
            for(ll i = 0; i < A.length(); i++){
                if(A[i] > B[i]){
                    cout << "GREATER" << endl;
                    return 0;
                }
                if(A[i] < B[i]){
                    cout << "LESS" << endl;
                    return 0;
                }
            }
        }
    }
     
}