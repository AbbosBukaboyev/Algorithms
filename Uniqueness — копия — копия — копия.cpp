/**
Аббос Букабоев
**/
#include<bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
vector<int> a;
set<int> st;

int main() {
    cin >> n;

    a.resize(n);
    for (int &x: a) {
        cin >> x;
    }

    for (int i = 0; i < n; i ++) {
        bool validPrefix = true;
        for (int j = 0; j < i; j ++) {
            if (st.count(a[j])) {
                validPrefix = false;
                break;
            } else {
                st.insert(a[j]);
            }
        }

        int index = n;
        for (int j = n - 1; j >= i; j --) {
            if (st.count(a[j])) {
                break;
            } else {
                st.insert(a[j]);
                index = j;

            }
        }

        //cout << "i =" << i << ", valid =" << validPrefix << ", index =" << index << endl;

        if (validPrefix) {
            ans = min(ans, index - i);
        }

        st.clear();
    }

    cout << ans;
}

