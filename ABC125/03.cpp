#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
 
using namespace std;
typedef long long ll;
double N;
set<ll>S;
 
void enum_div(ll n)//nの約数を列挙
{

	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			S.insert(i);
			if(i!=1 && i*i!=n)
			{
				S.insert(n/i);
			}
		}
	}
}
 
int main()
{   
    cin >> N;
    vector< ll> in(N, 0);

    int f = 0;

    cin >> in[0];

    ll test = 1;

    for(ll i = 1; i < N; i++){
        cin >> in[i];
        if(in[i-1] != in[i] ){
            f = 1;
        }
        test *= in[i];
    }

    if(f == 0){
        cout << in[0] << endl;
        return 0;
    }
 
    sort(in.rbegin(), in.rend());
    
    enum_div(test);

    /*for(ll i = 0; i < N; i++){
        enum_div(in[i]);
        S.insert(in[i]);
    }
    */
 
    vector< pair<ll, ll > > count;

    set<ll>::iterator it;
    //ll aa = 0;
    for(it = S.begin(); it != S.end(); it++){
        ll c = 0;
       // cout << *it << endl;
        for(ll j = 0; j < in.size(); j++){
            //cout << in[j] % *it << endl;
            if(in[j] % *it  == 0){
                c += 1;
            }
        }
        //cout << c << endl;
        count.push_back(make_pair(*it, c));
        //cout << count[aa].first << " " << count[aa].second  << endl;
        //aa++;
        //cout << count[i] << endl; 
    }
    ll ans = 0;
 
    for(ll i = 0; i < count.size(); i++){
        if(count[i].second == N - 1){
            ans = count[i].first;
            //cout << yaku[i] << endl;
        }
    }
 
    if(ans == 0){
        cout << "1" << endl;
    }else{
        cout << ans << endl;
    }
}