//Euler's tour
// Length of a subtree



const int mx=2*100000+5;
vector<ll>in_time(mx),out_time(mx);
ll timee;
vector<ll>tour;
vector<ll>adj[mx];

void dfs(ll u)
{
    vis[u]=true;
    in_time[u] = ++timee;
    tour.push_back(u);
    for(auto x : adj[u])
    {
        if(vis[x])continue;
        dfs(x);
    }
    out_time[u] = timee;
}