#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isPrime(maxn, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < maxn; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < maxn; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (!isPrime[n - 1])
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << (i == n ? '\n' : ' ');
            }
        }
        else if (n == 3 || n == 4 || n == 6)
        {
            cout << -1 << '\n';
        }
        else
        {
            for (int i = 1; i <= n - 4; i++)
            {
                cout << i << ' ';
            }

            cout << n << ' '
                << n - 1 << ' '
                << n - 2 << ' '
                << n - 3 << '\n';
        }
    }

    return 0;
}