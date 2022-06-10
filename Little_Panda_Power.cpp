#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <limits.h>
using namespace std;
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define LL long long
#define modulo 1000000007

LL power(LL base, LL exponent, int mod = modulo)
{
    LL res = 1;
    while ( exponent > 0 ) {
        if ( exponent&1 ) res = (res*base)%mod;
        base = (base*base)%mod;
        exponent >>= 1;
    }
    return res;
}

vector<LL> egcd(int a, int b){
    if(a == 0){
        vector<LL> ans;
        ans.pb(b), ans.pb(0), ans.pb(1);
        return ans;
    }
    vector<LL> ret = egcd(b % a, a);
    vector<LL> ans;
    ans.pb(ret[0]), ans.pb(ret[2] - ((b - b%a)/a) * ret[1]), ans.pb(ret[1]);
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int A, B, X;
        cin >> A >> B >> X;
        if(B < 0){
            LL ret = (X + egcd(A, X)[1]) % X;
            cout << power(ret, -B, X) << endl;
        }else cout << power(A, B, X) << endl;
    }
}
