#include <fstream>

#ifdef LOCAL
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}