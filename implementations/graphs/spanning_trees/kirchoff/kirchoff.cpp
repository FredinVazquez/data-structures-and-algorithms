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

const double EPS = 1E-9;
int n, m;
vector<vector<int>> adj, deg_mat; // adjacency matrix A and degree matrix D
vector<vector<int>> L; // Laplacian matrix: L = D - A

int Gauss(vector<vector<int>> a) {
    double det = 1;
    n = a.size();
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}

void solve() {
    cin >> n >> m;
    adj.resize(n, vector<int>(n));
    deg_mat.resize(n, vector<int>(n));
    L.resize(n, vector<int>(n));
    for (int i =0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        deg_mat[a][a]++; deg_mat[b][b]++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            L[i][j] = deg_mat[i][j] - adj[i][j];

    vector<vector<int>> cofactor(n-1, vector<int>(n-1));

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            cofactor[i-1][j-1] = L[i][j];

    auto det = Gauss(cofactor);
    printf("Number of spanning trees in G: %d\n", det);

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