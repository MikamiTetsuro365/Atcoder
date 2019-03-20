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


using namespace std;
typedef long long ll;


int main(){

    ll N, M;
    cin >> N >> M;

    vector<pair <ll, ll> > PY(M);
    vector<ll > num(N, 0);
    vector<vector<ll > > memo;
    memo = vector<vector<ll >>(N, vector<ll >(0, 0));

    vector<vector<pair<int,int>>> t_memo(N);

    ll P, Y;

    for(ll i = 0; i < M; i++){
        cin >> P >> Y;
        memo[P-1].push_back(Y);
        t_memo[P-1].push_back(make_pair(Y,i));      
    }

    for(ll i = 0; i < N; i++){
        sort(t_memo[i].begin(), t_memo[i].end());
    }

    vector<string > result(M, "");
    
    for(ll i = 0; i < N; i++){
        if(t_memo[i].size() == 0){
            continue;
        }
        for(ll j = 0; j < t_memo[i].size(); j++){
            //ll t = t_memo[i][j].first;
            //t_memo[i][j].first = t_memo[i][j].second;
            //t_memo[i][j].second = t;
            ostringstream ss;
            ss << setw(6) << setfill('0') << to_string(i+1) << setw(6) << setfill('0') << to_string(j+1);
    
            result[t_memo[i][j].second] = ss.str();
            //cout << "(" << t_memo[i][j].first << ":" << t_memo[i][j].second << ")" ;
        }
    }
    
    //表示
    for(ll i = 0; i < M; i++){
        cout << result[i] << endl;
    }

    

}