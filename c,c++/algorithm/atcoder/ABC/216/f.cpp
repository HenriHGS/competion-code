#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;

constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	vector<long long>w(N);
	for (auto& i : w)cin >> i;
	vector<vector<int>>box(5001);
	for (int i = 0; i < N; i++) {
		box[v[i]].push_back(w[i]);
	}
	long long ans = 0;
	vector<long long>dp(5001);
	dp[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		vector<long long>ndp(5001);
		for (auto j : box[i]) {
			for (int k = 5000; k >= j; k--) {
				ndp[k] += dp[k - j];
				ndp[k] %= MOD;
				ndp[k] += ndp[k - j];
				ndp[k] %= MOD;
			}
		}
		for (int j = 0; j <= 5000; j++) {
			if (j <= i) {
				ans += ndp[j];
				ans %= MOD;
			}
			ndp[j] += dp[j];
			ndp[j] %= MOD;
		}
		dp = ndp;
	}
	cout << ans << endl;
}
/*
20
1937 3980 2689 1208 3640 1979 581 2271 4229 3948 3708 1522 4161 4661 3797 96 3388 3395 2920 2247
4485 2580 174 1156 3770 3396 3558 3500 3494 479 269 3383 1230 1711 3545 3919 134 475 3796 1017

3
1937 3980 2689 
4485 2580 174 

4
1937 3980 2689 1208
4485 2580 174 1156

20 
134 174 269 581 1230 1937 2689 2920 3388 3494 3545 3558 3640 3708 3770 3796 3797 4161 4229 4485 
475 1156 3383 2271 1711 3980 1208 2247 3395 479 3919 3500 1979 1522 3396 1017 96 4661 3948 2580 


7 
134 174 269 581 1230 1937 2689
475 1156 3383 2271 1711 3980 1208
*/