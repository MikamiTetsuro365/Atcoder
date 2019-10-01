#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<ll > A;
    //vector<pair<ll, ll > > order;
    map<ll, vector<ll > > mp;

    //同じ数が連続して続くところは圧縮
    A.push_back(0);
    ll t_in = -1;
    ll num = 1;
    for(ll i = 0; i < N; i++){
        ll in = 0;
        cin >> in;
        if(in != t_in){
            mp[in].push_back(num);
            A.push_back(in);
            t_in = in;
            num++;
        }
    }
    A.push_back(0);

    //確認
    /* 
    for(ll i = 0; i < A.size(); i++){
        cout << A[i];
    }
    cout << endl;
    */

    //例外
    if(mp.size() == 1){
        auto begin = mp.begin(), end = mp.end();
        for (auto iter = begin; iter != end; iter++) {
            if(iter -> first > 0){
                cout << "1" << endl;
                return 0;
            }else{
                cout << "0" << endl;
                return 0;               
            }
        }
    }


    ll ans = 1;
    priority_queue<ll > ansQue; 
    ansQue.push(ans);

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        //cout << iter -> first << " " <<  iter->second.size() << endl;
        for(ll i = 0; i < iter->second.size(); i++){
            A[mp[iter -> first][i]] = 0;
            //cout << mp[iter -> first][i] - 1 << " " << mp[iter -> first][i] + 1 << endl;
            ll left  = A[mp[iter -> first][i] - 1];
            ll right = A[mp[iter -> first][i] + 1];
            
            if(left == 0 && right  == 0 ){
                ans--;
            }else if(left > 0 && right  > 0){
                ans++;
            }

        }
        ansQue.push(ans);
        //cout << ans << endl;
    }
 
    cout << ansQue.top() << endl;
}