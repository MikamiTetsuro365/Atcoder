#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    
    string s;
    cin >> s;
    map<char, ll> mp;

    char alph = 'A';
    for(ll i = 0; i < 26; i++){
        mp[alph+i];
    } 
    
    for(ll i = 0; i < s.length(); i++){
        if(mp[s[i]] == 0){
            mp[s[i]]++;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}