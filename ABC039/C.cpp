#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    string S;
    cin >> S;

    vector<pair<char, string> > tmp;
    //糞
    tmp.push_back(make_pair('W', "Do"));
    tmp.push_back(make_pair('B', "Do"));
    tmp.push_back(make_pair('W', "Re"));
    tmp.push_back(make_pair('B', "Re"));
    tmp.push_back(make_pair('W', "Mi"));
    tmp.push_back(make_pair('W', "Fa"));
    tmp.push_back(make_pair('B', "Fa"));
    tmp.push_back(make_pair('W', "So"));
    tmp.push_back(make_pair('B', "So"));
    tmp.push_back(make_pair('W', "La"));
    tmp.push_back(make_pair('B', "La"));
    tmp.push_back(make_pair('W', "Si"));
    tmp.push_back(make_pair('W', "Do"));
    tmp.push_back(make_pair('B', "Do"));
    tmp.push_back(make_pair('W', "Re"));
    tmp.push_back(make_pair('B', "Re"));
    tmp.push_back(make_pair('W', "Mi"));
    tmp.push_back(make_pair('W', "Fa"));
    tmp.push_back(make_pair('B', "Fa"));
    tmp.push_back(make_pair('W', "So"));
    tmp.push_back(make_pair('B', "So"));
    tmp.push_back(make_pair('W', "La"));
    tmp.push_back(make_pair('B', "La"));
    tmp.push_back(make_pair('W', "Si"));
    tmp.push_back(make_pair('W', "Do"));
    tmp.push_back(make_pair('B', "Do"));
    tmp.push_back(make_pair('W', "Re"));
    tmp.push_back(make_pair('B', "Re"));
    tmp.push_back(make_pair('W', "Mi"));
    tmp.push_back(make_pair('W', "Fa"));
    tmp.push_back(make_pair('B', "Fa"));
    tmp.push_back(make_pair('W', "So"));
    tmp.push_back(make_pair('B', "So"));
    tmp.push_back(make_pair('W', "La"));
    tmp.push_back(make_pair('B', "La"));
    tmp.push_back(make_pair('W', "Si"));
    tmp.push_back(make_pair('W', "Do"));

    
    for(ll i = 1; i <= 16; i++){
        bool f = true;
        //cout << i << endl;
        for(ll j = 0; j < 20; j++){
            //cout << tmp[i + j].first << " " << S[j] << endl;
            if(tmp[i + j].first != S[j]){
                f = false;
            }
        }
        if(f == true){
            cout << tmp[i].second << endl;
            return 0;
        }
    }

}