#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<ll > A;

    //同じ数が連続して続くところは圧縮
    for(ll i = 0; i < N; i++){
        ll in;
        cin >> in;
        if(i == 0){
            A.push_back(in);
            continue;
        }
        if(A[i] != A[i-1]){
            A.push_back(in);
        }
    }

    vector<ll > yama;
    //yama.push_back(0);
    map<ll, ll> mp;

    //priority_queue<ll > que;
    //出っ張ってるところを網羅
    bool yama_flg = true;
    bool flg = true;
    for(ll i = 0; i < A.size(); i++){
        if(i == 0){
            if(A[i] > A[i + 1]){
                yama.push_back(0);
                yama.push_back(A[i]);
                //que.push(A[i]);
                mp[A[i]] = 1;
            }else{
                yama.push_back(A[i]);
                yama_flg = false;
            }
        }else if(i == A.size() - 1){
            if(A[i] > A[i - 1]){
                yama.push_back(A[i]);
                yama.push_back(0);
                mp[A[i]] = 1;
            }else{
                yama.push_back(A[i]);
            }       
        }else if(A[i] > A[i + 1] && A[i] > A[i - 1]){
            yama.push_back(A[i]);
            mp[A[i]] = 1;
        }else if(A[i] < A[i + 1] && A[i] < A[i - 1]){
            yama.push_back(A[i]);
        }
    }

    mp[0] = 1;

    //yama.push_back(0);
    ll ans = 0;
    bool r_flag = false;
    bool l_flag = false;
    auto begin = mp.begin(), end = mp.end();

    for (auto iter = begin; iter != end; iter++) {
        ll suimen = iter->first;
        cout << "suimen : " << suimen << endl;
        ll t_ans = 0;
        //cout << que.top() << endl;
        for(ll i = 1; i < yama.size(); i+=2){
            cout << "yama "<< yama[i] << endl;
            if(yama[i] > suimen){
                if(yama[i + 1] <= suimen){
                    //cout << "we "<< endl;
                    r_flag = true;
                }
                if(yama[i - 1] <= suimen){
                    //cout << "ga "<< endl;
                    l_flag = true;
                }
            }
            if(r_flag == true && l_flag == true){
                cout << yama[i] << endl;
                ans++;
                r_flag = false;
                l_flag = false;
            }
        }
        cout << "t_ans : " << t_ans << endl; 
        ans = max(ans, t_ans);
        //que.pop();
    }


    //確認
    /*
    for(ll i = 0; i < yama.size(); i++){
        cout << yama[i] << endl;
    }
    */

    cout << ans << endl;
}