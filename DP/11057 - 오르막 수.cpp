#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#define S_MAX 10007
using namespace std;

int dp[11][1001]; //i(숫자)가 j(마지막자릿수)에 올 수 있는 경우의 수
int N;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i <= 9; i++) {
		dp[i][1] = 1; //i의 첫번째 자리수가 첫(마지막)자리에 올수있는경우
	}

	for(int j = 2; j <= N; j++) {
		for (int i = 0; i <= 9; i++) {
			if (i == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = (dp[i][j - 1]  + dp[i - 1][j]) % S_MAX;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[i][N]) % S_MAX;
	}

	sum %= S_MAX;

	printf("%d\n", sum);

	return 0;
}
