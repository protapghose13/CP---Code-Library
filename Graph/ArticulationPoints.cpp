
const int mx = 200011;
vector<int>vec[mx];
int n, d[mx], low[mx], visitingTime = 0, root;
bool vis[mx], points[mx];

void dfs(int u, int pr){
    assert(u != -1);
    d[u] = ++visitingTime;
    low[u] = visitingTime;
    vis[u] = true;
    int children = 0;
    for(auto v: vec[u]){
        if(v != pr){
            if(vis[v]){
                low[u] = min(low[u], d[v]);
            }
            else{
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(u != root && d[u] <= low[v]){
                    points[u] = true;
                }
            }
        }
    }
    if(u == root && children > 1){
        points[u] = true;
    }
}

void solve(){
    visitingTime = 0;
    cin>>n;
    for(int i=0;i<=n;i++){
        vec[i].clear();
        vis[i] = points[i] = false;
        low[i] = 4 * mx;
    }
    root = 1;
    dfs(root, -1);
}
