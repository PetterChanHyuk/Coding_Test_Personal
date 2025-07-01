#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int count;
	stack<int> s;
	long long answer = 0;
	// 빌딩의 개수 입력
	cin >> count;

	for (int i = 0; i < count; i++) {
		// 빌딩 높이 입력
		int height;
		cin >> height;

		if (s.empty()) {
			//비어있으면 높이 push하고 continue
			s.push(height);
			continue;
		}
		// 안 비어있고 스택의 마지막보다 들어온 빌딩의 높이가 크거나 같으면 top을 pop한다.
		while (!s.empty() && s.top() <= height) s.pop();
		// 정답에 스택의 사이즈 + 한다
		answer += s.size();
		// 빌딩의 높이 넣는다.
		s.push(height);
	}
	// 0+1+1+2+0+1
	

	cout << answer;

}