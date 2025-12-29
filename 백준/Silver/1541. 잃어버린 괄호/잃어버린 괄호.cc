#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	string s;
	cin >> s;
	vector<string> str;
	while (1) {
		auto pos = s.find("-");
		if (pos == string::npos) {
			str.push_back(s);
			break;
		}

		str.push_back(s.substr(0, pos));
		s = s.substr(pos + 1);
	}

	string part = str[0];
	while (1) {
		auto pos = part.find("+");
		if (pos == string::npos) {
			sum += stoi(part);
			break;
		}
		sum += stoi(part.substr(0, pos));
		part = part.substr(pos + 1);
	}

	for (int i = 1; i < (int)str.size(); i++) {
		part = str[i];
		int temp = 0;

		while (1) {
			auto pos = part.find("+");
			if (pos == string::npos) {
				temp += stoi(part);
				break;
			}
			temp += stoi(part.substr(0, pos));
			part = part.substr(pos + 1);
		}

		sum -= temp;
	}

	cout << sum << '\n';
	return 0;
}