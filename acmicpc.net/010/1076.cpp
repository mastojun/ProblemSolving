#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	map<string, int> valueMap = {
		{"black", 0},
		{"brown", 1},
		{"red", 2},
		{"orange", 3},
		{"yellow", 4},
		{"green", 5},
		{"blue", 6},
		{"violet", 7},
		{"grey", 8},
		{"white", 9}
	};

	string v1, v2, v3;
	cin >> v1 >> v2 >> v3;

	cout << (valueMap[v1] * 10 + valueMap[v2]) * (long long)pow(10, valueMap[v3]) << endl;

	return 0;
}
