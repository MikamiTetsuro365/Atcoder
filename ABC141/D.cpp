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
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;
    vector<double > A(N);
    priority_queue<ll > que;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        que.push(A[i]);
        
    }

    
    sort(A.rbegin(), A.rend());

    while(M > 0){
        double price = floor( que.top() / 2);
        que.pop();
        M--;
        que.push(price);
    }

    //合計
    ll sum = 0;
    while(!que.empty()){
        sum += que.top();
        que.pop();
    }

    cout << sum << endl;

} 