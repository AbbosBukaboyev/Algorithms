#include<bits/stdc++.h>
using namespace std;
const int mxn = 2 * 100001;
int n, k, x;

vector<int> a, t, nu, result;
vector<bool> used;
set<int> my_set;
int main() {
    cin >> n >> k;
    a.resize(n), result.resize(n), t.resize(n + 1), used.resize(n + 1, false);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];

        t[a[i]] = i;
        my_set.insert(i);
    }

    int j = 1, bd = n;

    while (true) {
        while(used[bd]) bd --;
        if (bd == 0) break;

        auto f = my_set.find(t[bd]);
        auto fr = f, fl = f;

         nu.push_back(*f);

         int cnt = 0;
         while (cnt < k && ++ fr != my_set.end()) {
            nu.push_back(*fr);
            cnt ++;
         }

         cnt = 0;
         while (cnt < k && fl -- != my_set.begin()) {
            nu.push_back(*fl);
            cnt ++;
         }

         for (int x: nu) {
            result[x] = j;
            my_set.erase(my_set.find(x));
            used[a[x]] = true;
         }

         nu.clear();
         j = 3 - j;
    }

    for (int x: result) {
        cout << x;
    }

    return 0;
}

/****
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.rbegin(), a.rend());
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		q.push(a[i].second);
	}

	set<int> idx;
	for (int i = 0; i < n; ++i) {
		idx.insert(i);
	}
	string ans(n, '0');
	int who = 0;
	while (!idx.empty()) {
		while (!idx.count(q.front())) {
			q.pop();
		}
		int pos = q.front();
		q.pop();

		vector<int> add;
		auto it = idx.find(pos);
		for (int i = 0; i <= k; ++i) {
			add.push_back(*it);
			if (it == idx.begin()) break;
			--it;
		}
		it = next(idx.find(pos));
		for (int i = 0; i < k; ++i) {
			if (it == idx.end()) break;
			add.push_back(*it);
			++it;
		}
		for (auto it : add) {
			idx.erase(it);
			ans[it] = '1' + who;
		}
		who ^= 1;
	}

	cout << ans << endl;

	return 0;
}
****/
