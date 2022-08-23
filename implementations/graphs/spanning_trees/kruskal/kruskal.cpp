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
vector<int> parent, rank_vec;

void MakeSet(int v) {
    parent[v] = v;
    rank_vec[v] = 0;
}

int FindSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = FindSet(parent[v]);
}

void UnionSets(int a, int b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (rank_vec[a] < rank_vec[b]) swap(a, b);
        parent[b] = a;
        if (rank_vec[a] == rank_vec[b]) rank_vec[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n, m, cost;
vector<Edge> mst, edges; // Minimum Spanning Tree

void Init() {
    cost = 0;
    mst.clear();
    parent.clear(); parent.resize(n);
    rank_vec.clear(); rank_vec.resize(n);
}

void Kruskal() {
    Init();
    // 1. Build individual trees
    for (int u=0; u<n; u++) MakeSet(u);

    // 2. Sort edges in non-decreasing order
    sort(edges.begin(), edges.end());

    // 3. Build MST
    for (auto e : edges) {
        if (FindSet(e.u) != FindSet(e.v)) {
            cost += e.weight;
            mst.push_back(e);
            UnionSets(e.u, e.v);
        }
    }
}

void solve() {
    cin >> n >> m;
    edges.clear();
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge e = {u,v,w};
        edges.push_back(e);
    }
    Kruskal();
    //cout << cost;

    for (auto e : mst) {
        cout << e.u << " " << e.v << " " << e.v;
    } 
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