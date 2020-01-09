#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

string s;
bool f = false;
map<string, bool> mp;

void solv(string tmp = "", string b = "er"){
    if(mp[tmp] == true){
        return;
    }
    mp[tmp] == true;
    if(s.length() <= tmp.length()){
        //cout << tmp << endl;
        if(s == tmp){
            f = true;
        }
        return;
    }

    if(b != "er"){
        solv(tmp + "er", "er");
    }
    
    solv(tmp + "dream", "dream");
    solv(tmp + "eras", "eras");
}

int main() {

    cin >> s;

    solv();

    if(f){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}