#include <stdio.h>
#include <string.h>

#define N	2000

int max(int a, int b) { return a > b ? a : b; }

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		static int dp[N + 1];
		int n, k, i, j;

		scanf("%d%d", &n, &k);
		memset(dp, -1, (n + 1) * sizeof *dp), dp[0] = 0;
		for (i = 0; i < n; i++) {
			int a;

			scanf("%d", &a);
			for (j = n; j > 0; j--)
				if (dp[j - 1] != -1)
					dp[j] = max(dp[j], dp[j - 1] + (a == j));
            printf("dp: ");
            for(int j = 1; j <= n; j ++ ){
                printf("%d %c", dp[j], j==n?'\n':' ');//cout<<dp[i][j]<<' ';
            }
		}
		for (j = n; j >= 0; j--)
			if (dp[j] >= k)
				break;
		printf("%d\n", j == -1 ? -1 : n - j);
	}
	return 0;
}
