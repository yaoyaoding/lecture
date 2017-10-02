#include <bits/stdc++.h>
using namespace std;

const int N = 65;

int n;
int aa[N];
bool dp[N][N][1830 + 100];
int op[N][N][1830 + 100];
int prej[N][N][1830 + 100];
int in[N], out[N], ee[N][N];
int ord[N];

bool cmp(int i, int j) {
	return out[i] < out[j];
}
void adde(int i, int j) {
	ee[i][j] = true;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", aa + i);
	sort(aa + 1, aa + 1 + n);
	for(int curn = n; curn <= 61; curn++) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = true;
		for(int i = 0; i <= curn; i++)
			for(int j = 0; j <= n; j++) {
				int maxk = i * aa[j];
				for(int k = 0; k <= maxk; k++) {
					if(dp[i][j][k] && i * (i - 1) / 2 > k) 
						dp[i][j][k] = false;
					if(dp[i][j][k] == false) continue;
					if(i == curn) continue;
					if(j != 0) {
						dp[i+1][j][k + aa[j]] = true;
						op[i+1][j][k + aa[j]] = j;
						prej[i+1][j][k + aa[j]] = j;
					}
					if(j + 1 <= n) {
						dp[i+1][j+1][k + aa[j+1]] = true;
						op[i+1][j+1][k + aa[j+1]] = j + 1;
						prej[i+1][j+1][k + aa[j+1]] = j;
					}
				}
			}
		int cnt = curn * (curn - 1) / 2;
		if(dp[curn][n][cnt] == true) {
			vector<int> vc;
			int curi = curn;
			int curj = n;
			int curk = cnt;
			while(curi != 0) {
				vc.push_back(aa[op[curi][curj][curk]]);
				int pi = curi - 1;
				int pj = prej[curi][curj][curk];
				int pk = curk - aa[op[curi][curj][curk]];
				curi = pi, curj = pj, curk = pk;
			}
			for(int i = 1; i <= curn; i++) {
				out[i] = vc[i-1]; 
				in[i] = curn - 1 - vc[i-1];
			}
//			printf("%d\n", curn);
			for(int i = 1; i <= curn; i++) {
				ord[i] = i;
//				printf("%d %d\n", in[i], out[i]);
			}
			int remain = curn;
			do {
				sort(ord+1,ord+1+remain,cmp);
//				for(int i = 1; i <= remain; i++)
//					printf("%d(%d) ", ord[i], out[ord[i]]);
//				printf("\n");
				for(int i = 1 + 1; i <= 1 + out[ord[1]]; i++) {
					in[ord[i]]--;
					adde(ord[1],ord[i]);
				}
				for(int i = 1 + out[ord[1]] + 1; i <= remain; i++) {
					out[ord[i]]--;
					adde(ord[i],ord[1]);
				}
				swap(ord[1], ord[remain]);
				remain--;
			}while(remain);
			printf("%d\n", curn);
			for(int i = 1; i <= curn; i++) {
				for(int j = 1; j <= curn; j++)
					printf("%d", ee[i][j]);
				printf("\n");
			}
			return 0;
		}
	}
	printf("-1\n");
}

