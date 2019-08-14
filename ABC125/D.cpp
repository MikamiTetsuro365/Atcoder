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

    cin >> N;
    vector<ll > v;
    
    //マイナスの数
    vector<ll > minus;
    //合計
    ll sum = 0;
    ll m_sum = 0;

    for(ll i = 0; i < N; i++){

        ll temp = 0;
        cin >> temp;
        v.push_back(abs(temp));

        if(temp < 0){
            //マイナスの集合
            minus.push_back(temp);
            m_sum += temp;
        }
        sum += temp;
    }

    sort(v.begin(), v.end());

    if(minus.size() % 2 == 0){
        sum += 2 * abs(m_sum);
    }else{
        sum += 2 * abs(m_sum) - 2 * v[0];
    }

    cout << sum << endl;


}