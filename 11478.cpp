#include <iostream>
#include <string>
#include <set>
// BOJ 11478 - Number of partial strings different from each other
using namespace std;

set<string> S;

int main(void) {
	string temp, str = "";
	cin >> temp;

	for (int i = 0; i < temp.size(); i++) {
		for (int j = i; j < temp.size(); j++) {
			str += temp[j];
			S.insert(str);
		}
		str = "";
	}
	cout << S.size();

	return 0;
}
/*
set 자료구조를 적극적으로 활용하자.
*/
