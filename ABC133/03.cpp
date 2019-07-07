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

using namespace std;
typedef long long ll;
ll N;

int main(){
    
    ll L , R;
    cin >> L >> R;

    //cout << L % 2019 << " " << R % 2019 << endl;
    ll cnt = 0;
    vector<ll> md(2019, 1145141919191919);
    vector<pair<ll, ll > > mm;
    for(ll i = L; i <= R; i++){
        //cout << i << endl;
        mm.push_back(make_pair(i % 2019, i));
        //cout << i % 2019 << endl;
        if(mm.size() == 2019){
            break;
        }
    }
    ll ans = 1145141919191919;
    for(ll i = 0; i < mm.size(); i++){
        for(ll j = i + 1; j < mm.size(); j++){
            ans = min(ans, mm[i].second * mm[j].second % 2019);
            //cout <<  mm[i].second * mm[j].second % 2019 << endl;
        }
    }
    //sort(mm.begin(), mm.end());
    //cout << mm[0].second << " " << mm[1].second << endl;
    cout << ans << endl;
} 