#include <iostream>
using namespace std;

int main() {
    char line[101];  // 각 줄이 최대 100글자이므로 101로 선언 (널 문자를 포함해야 함)
    
    while (cin.getline(line, 101)) {  // 최대 100글자까지 입력받음
        cout << line << endl;
    }

    return 0;
}
