#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	int A;
	int B;
	int ans = 0;
	int room[2][7] = { 0, };
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		room[A][B]++;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			ans += room[i][j] / K;
			if (room[i][j] % K > 0)
				ans++;
		}
	}
	cout << ans;

}