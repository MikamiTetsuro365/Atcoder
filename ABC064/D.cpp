#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;


int main(){

    ll N;
    string S;
    cin >> N >> S;
    //終わりだょ
    //S.push_back('*');

    stack<char > st;
    for(ll i = 0; i < N; i++){
        if(st.empty()){
            st.push(S[i]);
            continue;
        }
        if(S[i] == '('){
            st.push(S[i]);
        }

        if(S[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }else{
                st.push(S[i]);
            }
        }   
        
    }

    map<char, ll> mp;
    
    while(!st.empty()){
        mp[st.top()]++;
        st.pop();
    }

    string ans = "";
    for(ll i = 0; i < mp[')']; i++){
        ans += '(';
    }

    ans += S;

    for(ll i = 0; i < mp['(']; i++){
        ans += ')';
    }  

    cout << ans << endl;

}