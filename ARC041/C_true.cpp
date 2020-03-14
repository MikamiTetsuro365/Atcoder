#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//惜しい
int main() {

    ll N, D;
    cin >> N >> D;

    set<ll > R; set<ll > RR; set<ll > rR; set<ll > rRR;
    R.insert(0); RR.insert(0); rR.insert(0); rRR.insert(0);
    R.insert(D+1); RR.insert(D+1); rR.insert(D+1); rRR.insert(D+1);
    set<ll > L; set<ll > LL; set<ll > rL; set<ll > rLL;
    L.insert(0); LL.insert(0); rL.insert(0); rLL.insert(0);
    L.insert(D+1); LL.insert(D+1); rL.insert(D+1); rLL.insert(D+1);

    bool startL_flag = false;
    for(ll i = 0; i < N; i++){
        ll x; char d;
        cin >> x >> d;
        if(d == 'R'){
            R.insert(x);
            RR.insert(x);
            rR.insert(x);
            rRR.insert(x);
        }else{
            if(i == 0) startL_flag = true;
            L.insert(x);
            LL.insert(x);
            rL.insert(x);
            rLL.insert(x);
        } 
    }

    ll sum = 0;
    
    //右が目一杯左へ
    map<ll, ll> sumR;
    for(auto i = R.rbegin(); i != R.rend(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = LL.lower_bound(*i);
        //cout << *i << " " << *d << endl;
        ll cost = (*d - 1) - *i;
        ll tmp = *d - 1;
        d--; 
        //答えの紐付け
        sumR[*d] += cost;
        LL.insert(tmp); 
        rRR.erase(*i);
        rRR.insert(tmp);    
    }

    //左が目一杯左へ
    map<ll, ll> sumL;
    for(auto i = L.begin(); i != L.end(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = RR.lower_bound(*i);
        d--;
        //cout << "::" <<  *i << " " << *d + 1 << endl;
        ll cost = *i - (*d + 1);
        ll tmp = *d + 1;
        d++; 
        //答えの紐付け
        sumL[*d] += cost;     
        RR.insert(tmp);
        rLL.erase(*i);
        rLL.insert(tmp);
    }
    //右が最右に目一杯右へ（左が目一杯左へを使って）
    map<ll, ll> sumMostR;
    for(auto i = rR.rbegin(); i != rR.rend(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = rLL.lower_bound(*i);
        //cout << *i << " " << *d << endl;
        ll cost = (*d - 1) - *i;
        ll tmp = *d - 1;
        d--; 
        //答えの紐付け
        sumMostR[*d] += cost;
        rLL.insert(tmp);     
    }

    //左が最左に目一杯左へ（右が目一杯右へを使って）
    map<ll, ll> sumMostL;
    for(auto i = rL.begin(); i != rL.end(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = rRR.lower_bound(*i);
        d--;
        //cout << "::" <<  *i << " " << *d + 1 << endl;
        ll cost = *i - (*d + 1);
        ll tmp = *d + 1;
        d++; 
        //答えの紐付け
        sumMostL[*d] += cost;     
        rRR.insert(tmp);
    }

    //確認
    //cout << "t_sumR" << endl;
    vector<ll > t_sumR;
    if(startL_flag == true) t_sumR.push_back(0);
    auto begin = sumR.begin(), end = sumR.end();
    for (auto iter = begin; iter != end; iter++){
        t_sumR.push_back(iter -> second);
        //cout << iter -> second << endl;
    } 
    t_sumR.push_back(0);

    //cout << "t_sumL" << endl;
    vector<ll > t_sumL;
    begin = sumL.begin(), end = sumL.end();
    for (auto iter = begin; iter != end; iter++){
        t_sumL.push_back(iter -> second);
        //cout << iter -> second << endl;
    }
    t_sumL.push_back(0);       

    //cout << "t_sumMostR" << endl;
    vector<ll > t_sumMostR;
    if(startL_flag == true) t_sumMostR.push_back(0);
    begin = sumMostR.begin(), end = sumMostR.end();
    for (auto iter = begin; iter != end; iter++){
        t_sumMostR.push_back(iter -> second);
        //cout << iter -> second << endl;
    } 
    t_sumMostR.push_back(0);

    //cout << "t_sumMostL" << endl;
    vector<ll > t_sumMostL;
    begin = sumMostL.begin(), end = sumMostL.end();
    for (auto iter = begin; iter != end; iter++){
        t_sumMostL.push_back(iter -> second);
        //cout << iter -> second << endl;
    }
    t_sumMostL.push_back(0);       

    ll ans = 0;
    for(ll i = 0; i < min(t_sumL.size(), t_sumR.size()); i++){
        //cout << t_sumL[i] << " " << t_sumMostR[i] << ":" <<  t_sumR[i] << " " << t_sumMostL[i] << endl;
        ans += max(t_sumL[i]+t_sumMostR[i], t_sumR[i]+t_sumMostL[i]);
    }

    cout << ans << endl;

}