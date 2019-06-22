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
ll N;
ll M;
string s;
vector<ll > input1;  
vector<vector <ll > > input2;

int main(){
    
    ll N = 0;
    cin >> N;

    vector< pair<ll, ll > > work(N);

    ll maxWork = 0;
    for(ll i = 0; i < N; i++){
        ll A = 0;
        ll B = 0;
        cin >> A >> B;
        maxWork += A;
        work[i] = make_pair(B, A);
    }

    sort(work.begin(), work.end());
    //cout << work[N-1].first << endl;
    /*
    if(maxWork > work[N-1].first){
        cout << "No" << endl;
    }
    */
    
    /*else{
        cout << "Yes" << endl;
    }*/

    /*
    //vector<vector<ll> > dp(N+1, vector<ll >(work[N-1].first + 1, -1));
   */
   //vector<ll> dp(work[N-1].first + 1, -1);
    //初期化
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        sum += work[i].second;
        //cout << sum << endl;
        if(sum > work[i].first){
            cout << "No" << endl;
            return 0;
        }

        
    }

    cout << "Yes" << endl;
} 