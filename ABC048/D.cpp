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

    string s;
    cin >> s;
    //同じ文字同士が隣り合うような局面がでるような文字のとり方が絶対にできない
    //最終的には最適に取るとxaxaxみたいな交互状態になっているはず
    //xaxaxaみたいな状態になると隣り合わないように取るためには端から取っていく
    //後は両端を気にするだけ
    if(s[0] == s[s.length()-1]){
        if((s.length() - 2) % 2 == 1){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }else{
        if((s.length() - 2) % 2 == 1){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }        
    }

}