#include <iostream>
#include "config.h"

using namespace std;

int main() {
	#ifdef PRINT_VERSION
	cout << "Version : " << VERSION << endl;
	#endif

	cout << "main" << endl;

	return 0;
}
