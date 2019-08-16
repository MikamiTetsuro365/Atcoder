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
#include <tuple>

using namespace std;
typedef long long ll;
ll N;

int main(){

    ll N;
    cin >> N;
    ll n = N;
    //ごりっごり
    map<tuple<ll, ll, ll >, ll> conf;
    vector<tuple<ll, ll, ll > > ans;

    //入力
    vector<tuple<ll, ll, ll > > input;
    for(ll i = 0; i < N; i++){
        ll x, y, h;
        cin >> x >> y >> h;

        if(h == 0){
            n--;
        }

        input.push_back(make_tuple(x, y, h));
        
    }

    for(ll i = 0; i < N; i++){
        ll x, y, h;
        x = get<0>(input[i]);
        y = get<1>(input[i]);
        h = get<2>(input[i]);

        if(h == 0){
            continue;
        }

        for(ll X = 0; X <= 100; X++){
            for(ll Y = 0; Y <= 100; Y++){
                //cout << abs(x - X) + abs(y - Y) + h << endl;
                
                conf[make_tuple(abs(x - X) + abs(y - Y) + h, X, Y)]++;
                
                //cout << ans[make_tuple(abs(x - X) + abs(y - Y) + h, X, Y)] << endl;
                if(conf[make_tuple(abs(x - X) + abs(y - Y) + h, X, Y)] == n){
                    //cout << X << " " << Y << " " << abs(x - X) + abs(y - Y) + h << endl;
                    ans.push_back(make_tuple(X, Y, abs(x - X) + abs(y - Y) + h));
                    //cout << "good" << endl;
                }
            }
        }
    }


    //整合性を確認>あってるやつを出力

    for(ll i = 0; i < ans.size(); i++){
        ll cn = 0;
        ll cx, cy, ch;
        cx = get<0>(ans[i]);
        cy = get<1>(ans[i]);
        ch = get<2>(ans[i]);

        for(ll j = 0; j < N; j++){
            ll x, y, h;
            x = get<0>(input[j]);
            y = get<1>(input[j]);
            h = get<2>(input[j]);

            ll t_h =  max(ch - abs(x - cx) - abs(y - cy), ll(0) );

            if(h == t_h){
                cn++;
            }
        }

        if(cn == N){
            cout << cx << " " << cy << " " << ch << endl;
            break;
        }

    }

    //cout << ans.size() << endl;


} 