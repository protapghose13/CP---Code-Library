const int mx = 200011;
vector<int>vec[mx];
vector<vector<int>> bridges;
int n, d[mx], low[mx], visitingTime = 0;
bool vis[mx];

void dfs(int u, int pr){
    assert(u != -1);
    d[u] = ++visitingTime;
    low[u] = visitingTime;
    vis[u] = true;
    for(auto v: vec[u]){
        if(v != pr){
            if(vis[v]){
                low[u] = min(low[u], d[v]);
            }
            else{
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                vector<int> temp(2);
                temp[0] = u, temp[1] = v;
                if(d[u] < low[v]){
                    bridges.push_back(temp);
                }
            }
        }
    }
}

void solve(){
    visitingTime = 0;
    cin>>n;
    for(int i=0;i<=n;i++){
        vec[i].clear();
        vis[i] = false;
        low[i] = 4 * mx;
    }
    dfs(1, -1);
}