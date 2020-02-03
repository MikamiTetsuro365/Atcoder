#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll MOD = 1000000007;
//ACしたが絶対糞コード
ll trans(string num){
    ll res = 0;
    ll cn = 1;
    for(ll i = num.length()-1; i >= 0; i--){
        res += (num[i] - '0') * cn;
        cn *= 10;
    }
    return res;
}

int main(){

    ll N;
    cin >> N;

    ll sum = 0;

    string S = to_string(N);
    for(ll i = 0; i < S.length(); i++){
        sum += S[i] - '0';
    }

    string t_ans;
    if(sum % 9 > 0) t_ans = to_string(sum % 9);

    for(ll i = 0; i < sum / 9; i++){
        t_ans += to_string(9);
    }

    //cout << trans(t_ans) << endl;
    if(trans(t_ans) < trans(S)){
        cout << t_ans << endl;
    }else{
        if(t_ans.size() >= 2){
            if(t_ans[0] != '9'){
                t_ans[0]++;
                t_ans[1]--;
                cout << t_ans << endl;
            }else{
                t_ans[0]--;
                cout << 1 << t_ans << endl;
            }
            
        }else{
            t_ans[0]--;
            cout << 1 << t_ans[0]<< endl;
        }

    }
}    