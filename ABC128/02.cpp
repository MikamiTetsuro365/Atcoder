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
    //ll P , Q , R;
    //cin >> P >> Q  >> R;
    ll N;
    cin >> N;
    vector<pair <pair <string, ll >, ll> > dic(N);

    for(ll i = 0; i < N; i++){
        string name;
        ll point;
        cin >> name >> point;
        dic[i] = make_pair(make_pair(name, point * -1), i);
    }

    sort(dic.begin(), dic.end());

    for(ll i = 0; i < N; i++){
        //string s = to_string(dic[i].second);
        cout << dic[i].second+1 << endl;
    }


} 