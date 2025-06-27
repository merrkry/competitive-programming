#include <bits/stdc++.h>
#define maxn 200010
#define ll long long

using namespace std;
ll n, m;
ll pr[maxn], sumsk[maxn];

vector<ll> ans[maxn];

struct lx {
  ll nl, id;
} sk[maxn];

bool cmp(lx a, lx b) { return a.nl > b.nl; }

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> sk[i].nl;
    sk[i].id = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> pr[i];
  }

  sort(sk + 1, sk + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    ll maxid = -1, num = 0, den = 1;
    for (int j = 1; j <= m; j++) {
      if ((__int128)pr[j] * sk[i].nl * den >
          ((__int128)sumsk[j] + sk[i].nl) * num) {
        num = pr[j] * sk[i].nl;
        den = sumsk[j] + sk[i].nl;
        maxid = j;
      }
    }
    ans[maxid].push_back(sk[i].id);
    sumsk[maxid] += sk[i].nl;
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}
