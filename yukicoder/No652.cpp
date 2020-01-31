#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//謎の誤差が発生したのでstod使うのやめた
int main() {

    ll a, b;
    cin >> a >> b;
    ll minute = a * 60 + b;
    //cout << minute << endl;

    string s;
    cin >> s;

    //double t = stod(s.substr(3,s.length()-3));
    //double sabun = (t - 9) * 60;

    string st = s.substr(3,s.length()-3);

    ll len = st.length();
    ll tt = 0;
    if(len == 2){
        tt =  (st[1]-'0') * 60;
    }else if(len == 3){
        tt = ((st[1]-'0') * 10 + (st[2]-'0')) * 60;
    }else if(len == 4){
        tt = (st[1]-'0') * 60 + (st[3]-'0') * 6;
    }else{
        tt = ((st[1]-'0')* 10 + (st[2]-'0')) * 60 + (st[4]-'0') * 6;
    }
     
    if(st[0] == '-') tt *= -1;

    minute += tt - 9 * 60;

    if(minute < 0){
        minute += 24 * 60;
    }
    if(minute >= 24 * 60){
        minute -= 24 * 60;
    }   

    cout << setw(2) << setfill('0') << minute / 60 << ":" ;
    cout << setw(2) << setfill('0') << minute % 60 << endl;


}