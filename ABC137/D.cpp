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
#include <queue>

using namespace std;
typedef long long ll;
ll N, M;

int main(){

    ll ans = 0;

    cin >> N >> M;

    map<ll, vector<ll > > v;

    for(ll i = 0; i < N; i++){
        ll tempA, tempB;
        cin >> tempA >> tempB;
        v[tempA].push_back(tempB);
    }

    priority_queue<ll > q;

    //M日分しかループは回さない
    //M日後から1日, 2日・・・i日前を考えていく
    for(ll i = 1; i <= M; i++){
        //i日前で候補があるか調べる
        for(ll j = 0; j < v[i].size(); j++){
            //atでキーに対応する値を返す
            q.push(v[i].at(j));
        }

        if(q.size() == 0){
            continue;
        }

        ans += q.top();
        q.pop();

    }

    cout << ans << endl;


}