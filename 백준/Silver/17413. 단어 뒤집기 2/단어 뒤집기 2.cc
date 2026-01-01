#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool inTag = false;

	string s;
	getline(cin, s);

	string word = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			reverse(word.begin(), word.end());
			cout << word;
			word = "";
			inTag = true;
			word += s[i];
			continue;
		}
		if (s[i] == '>') {
			inTag = false;
			word += s[i];
			cout << word;
			word = "";
			continue;
		}
		if (!inTag) {
			word += s[i];
			if (s[i] == ' ') {
				reverse(word.begin(), word.end() - 1);
				cout << word;
				word = "";
				continue;
			}
		}
		if(inTag){
			word += s[i];
		}
	}
	reverse(word.begin(), word.end());
	cout << word;

}