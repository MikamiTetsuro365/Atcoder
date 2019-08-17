#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <map>


using namespace std;
typedef long long ll;

//?????????????

int main(){

    string S, T;
    cin >> S >> T;
    map<char, vector<char > > s;
    map<char, vector<char > > t;

    //sort(S.begin(), S.end());
    //sort(T.begin(), T.end());
    //cout << S << endl;
    //cout << T << endl;

    for(ll i = 0; i < S.length(); i++){
        //S????????
        /* 
        if(S[i] == T[i]){
            continue;
        }
        */

        if(s[S[i]].size() == 0){
            s[S[i]].push_back(T[i]);
        }else{
            bool f = 0;
            for(ll j = 0; j < s[S[i]].size(); j++){
                if(s[S[i]][j] == T[i]){
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                s[S[i]].push_back(T[i]);
            }
        }
        //T????????
        if(t[T[i]].size() == 0){
            t[T[i]].push_back(S[i]);
        }else{
            bool f = 0;
            for(ll j = 0; j < t[T[i]].size(); j++){
                if(t[T[i]][j] == S[i]){
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                t[T[i]].push_back(S[i]);
            }
        }
    }

    //1?1??????????????????
    //???????????
    for( auto i = s.begin(); i != s.end() ; ++i ) {
        if(s[i->first].size() > 1){
            cout << "No" << endl;
            return 0;
        }else{
            if(i->first != t[s[i->first][0]][0]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for( auto i = t.begin(); i != t.end() ; ++i ) {
        if(t[i->first].size() > 1){
            cout << "No" << endl;
            return 0;
        }else{
            if(i->first != s[t[i->first][0]][0]){
                cout << "No" << endl;
                return 0;
            }           
        }
    }

    cout << "Yes" << endl;
    
}