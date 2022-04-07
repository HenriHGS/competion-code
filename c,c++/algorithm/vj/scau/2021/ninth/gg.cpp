#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)2e6 + 100;
int n;
char s[N];
int z[N];
pii st[N];
int m;
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	for (int i = n - 1; i > 0; i--)
		s[2 * i] = s[i];
	for (int i = 1; i < 2 * n; i += 2)
		s[i] = s[2 * n - 1 - i];
	int l = 0, r = 0;
    //马拉车
	for (int i = 1; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[l + r - i + 1]);
		while(i > z[i] && s[i - z[i] - 1] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) {
			l = i - z[i];
			r = i + z[i] - 1;
		}
	}
    s[2*n] = '\0';
    //cout<<s<<endl;
    /*
    for(int i = 0; i < 2*n; i ++ )cout<<s[i]<<"  ";
    cout<<endl;
    for(int i = 0; i < 2*n;i ++ )printf("%-3d", i);
    cout<<endl;
    cout<<"z[i]"<<endl;
    for(int i = 0; i < n; i ++ )printf("%-3d", z[i]);
    cout<<endl;
	for (int i = 1; i < n; i += 2) {
		l = i - z[i];
        //用一个单调栈，来维护左端点，最靠左的点。i越大，的回文长度越长。
		while(m > 0 && st[m - 1].first >= l) m--;
		st[m++] = mp(l, i);
	}
    */
	for (int i = 0; i <= n; i++)
		ans[i] = -1;
	for (int i = 0; i < m; i++) {
		r = st[i].second;
		if (i + 1 < m) r = min(r, st[i + 1].first);
		for (int j = st[i].first; j < r; j++)
			ans[j] = st[i].second - j;
	}
    cout<<"debug"<<endl;
    for(int i =0; i  < n; i ++ )cout<<ans[i]<<' ';
    cout<<endl;
    cout<<"ans"<<endl;
	for (int i = 0; i < n; i += 2)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
/*
hack1:
15
bcabcabcabcabca
out:
b  a  c  c  a  b  b  a  c  c  a  b  b  a  c  c  a  b  b  a  c  c  a  b  b  a  c  c  a  b  
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
z[i]
0  0  0  3  0  0  6  0  0  9  0  0  12 0  0  
debug
9 8 7 6 5 4 3 2 1 -1 -1 -1 -1 -1 -1
ans
9 7 5 3 1 -1 -1 -1

hack2:
24
abaaabaaaabaaabaaaabaaab
out:
24
abaaabaaaabaaabaaaabaaab
a  b  b  a  a  a  a  a  a  b  b  a  a  a  a  a  a  a  a  b  b  a  a  a  a  a  a  b  b  a  a  a  a  a  a  a  a  b  b  a  a  a  a  a  a  b  b  a  
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
z[i]
0  0  2  0  1  2  6  2  1  0  7  0  1  2  3  15 3  2  1  0  7  0  1  2  
   a     a     a     a     a     a     a     a     a     a     a     a
debug
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2 1 -1 -1 -1 -1 2 1 -1
ans
15 13 11 9 7 5 3 1 1 -1 -1 1
*/