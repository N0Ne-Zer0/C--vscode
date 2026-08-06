#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    queue<pair<int, int>> q;

    dist[1][0] = 0;
    q.push({ 1, 0 });

    while (!q.empty())
    {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        for (int v : g[u])
        {
            int np = p ^ 1;

            if (dist[v][np] == INF)
            {
                dist[v][np] = dist[u][p] + 1;
                q.push({ v, np });
            }
        }
    }

    for (int u = 1; u <= n; u++)
    {
        ll ans = LINF;

        for (int p = 0; p < 2; p++)
        {
            if (dist[u][p] == INF)
            {
                continue;
            }

            if (k % 2 == 0 && p == 1)
            {
                continue;
            }

            ll d = dist[u][p];
            ll cnt = (d + k - 1) / k;

            if (k % 2 == 1)
            {
                if (cnt % 2 != p)
                {
                    cnt++;
                }
            }

            ans = min(ans, cnt * k);
        }

        if (ans == LINF)
        {
            cout << -1;
        }
        else
        {
            cout << ans;
        }

        cout << (u == n ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}