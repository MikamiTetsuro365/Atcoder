#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

string upperCase(string name){
    for (int i=0;i< name.size();i++)
        name[i]=toupper(name[i]);
    return name;
}

int main(){

    string s, t;
    cin >> s >> t;

    if(s == t){
        cout << "same" << endl;
    }else if(upperCase(s) == upperCase(t)){
        cout << "case-insensitive" << endl;
    }else{
        cout << "different" << endl;
    }
}