#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000000;
ll INF = 11451419194545;

string s[5] = {
    ".###..#..###.###.#.#.###.###.###.###.###",
    ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#",
    ".#.#..#..###.###.###.###.###...#.###.###",
    ".#.#..#..#.....#...#...#.#.#...#.#.#...#",
    ".###.###.###.###...#.###.###...#.###.###" 
};

int main(){

    ll N;
    cin >> N;

    vector<string > S;

    for(ll i = 0; i < 5; i++){
        string s;
        cin >> s;
        S.push_back(s);
    }

    string ans;
    ll idx = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= 9; j++){
            bool f = true;
            for(ll k = 0; k < 5; k++){
                for(ll kk = 0; kk < 4; kk++){
                    if(s[k][kk + 4 * j] != S[k][kk + 4 * i]){
                        f = false;
                        break;
                    }
                }
                if(f == false) break;                
            }
            if(f == true){
                ans += to_string(j);
                break;
            }
        }
    }

    cout << ans << endl;

}