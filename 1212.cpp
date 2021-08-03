#include <iostream>
#include <string>
// BOJ - 1212 Octal to Binary

using namespace std;

int main(void) {
	string input;
	string output = "";

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (i == 0) {
			switch (input[i]) {
			case '0': output += "0"; break;
			case '1': output += "1"; break;
			case '2': output += "10"; break;
			case '3': output += "11"; break;
			case '4': output += "100"; break;
			case '5': output += "101"; break;
			case '6': output += "110"; break;
			case '7': output += "111";
			default: break;
			}
		}
		else {
			switch (input[i]) {
			case '0': output += "000"; break;
			case '1': output += "001"; break;
			case '2': output += "010"; break;
			case '3': output += "011"; break;
			case '4': output += "100"; break;
			case '5': output += "101"; break;
			case '6': output += "110"; break;
			case '7': output += "111";
			default: break;
			}
		}
	}
	cout << output;

	return 0;
}