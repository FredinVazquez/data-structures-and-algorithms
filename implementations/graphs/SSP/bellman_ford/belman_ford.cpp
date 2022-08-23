#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define fastIO()        cin.tie(0); cout.tie(0);
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define debug(x)        cout << #x << " = "; _debug(x); cout << endl;
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define pi(x)           printf("%d\n", x);
#define pl(x)           printf("%lld\n", x);
#define pb              push_back
#define F               first
#define S               second
#define all(x)          x.begin(), x.end()
#define sz(x)           (int) x.size()
#define LB(arr,x)       lower_bound(all(arr),x) -(arr).begin()
#define UB(arr,x)       upper_bound(all(arr),x) -(arr).begin()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

const ll MOD= 1e9 + 7;
const ll INF= 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin() , file.end() - 3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str() , "r", stdin);
    freopen(out_file.c_str(), "w",stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1,T2>& pair){

    cout <<"{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";
}

template<typename T>
void _debug(vector<T> & vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i,n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n - 1]); cout << "j";
}

void _debug(vector<string>& vec){
    int n= sz(vec);
    cout << endl;
    FO(i,n){

        cout << vec[i] << endl;
    }
}

template<typename T>
void _debug(vector<vector<T> >& A){
    int n = sz(A);
    cout << endl;
    FO(i,n){
        _debug(A[i]); cout << endl;
    }
}

template<typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template<typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b - 1){
        cout << vec[i] << " ";
    }
    cout << vec[b - 1] << endl;
    return;
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

int n , m;

const double INF=1e18;

struct edge {
    int u, v, weight;
};

void BellmanFord(int s, int n, int m, vector<double> &d, vector<int> & p, 
    const vector<edge> &edges) {
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    for (int i = 0; i < n-1; i++) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            auto edge = edges[j];
            if (d[edge.u] < INF) {
                if (d[edge.u] + edge.weight < d[edge.v]) {
                    d[edge.v] = d[edge.u] + edge.weight;
                    p[edge.v] = edge.u;
                    any = false;
                }
            }
        }
        if (!any) break;
    }
}

vector<int> SSSP(int s, int t, const vector<double> &d, const vector<int> &p) {
    if (d[t] == INF) return {};
    vector<int> path;
    path.push_back(t);
    auto par = p[t];
    while (par != s) {
        path.push_back(par);
        par = p[par];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}


void solve() {
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v , w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    int source = 0;
    vector<double> d;
    vector<int> p;
    BellmanFord(source, n, m, d, p, edges);

    // for (auto di : d) cout << di << ' ';
    // cout << endl;

    int target = 2;
    auto path = SSSP(source, target, d, p);
}


int main() {
    ios_base::sync_with_stdio(false);
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T; si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}