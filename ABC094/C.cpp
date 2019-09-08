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
typedef long long int ll;

int main(){

    ll N = 0;
    cin >> N;
    vector<pair<ll, ll > > a;
    //map<ll >

    for(ll i = 0; i < N; i++){
        ll in = 0;
        cin >> in;
        a.push_back(make_pair(in, i));
    }

    sort(a.begin(), a.end());

    vector<ll > ans(N);

    for(ll i = 0; i < N; i++){
        if(i < N / 2){
            //ans += a[N / 2 + 1];
            ans[a[i].second] = a[N / 2].first;
        }else{
            //ans += a[N / 2];
            ans[a[i].second] = a[N / 2 -1].first;
        }
    }

    //表示
    for(ll i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

    //cout << ans << endl;



} 