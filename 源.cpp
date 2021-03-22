#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define number 10000
int comp(const void* p, const void* q) {
	return (*reinterpret_cast<const int*>(p) - *reinterpret_cast<const int*>(q));
}
int main() {
	int a[number], i, j, k, n;
	srand(time(NULL));
	for (i = 0; i < number; i++) {
		a[i] = rand();
	}
	n = rand();
	qsort(a, number, sizeof(int), comp);
	//顺序查找
	for (i = 0; i < number; i++) {
		if (a[i] == n) {
			break;
		}
	}
	if (i == number) {
		cout << 0 << endl;
	}
	else {
		cout << i + 1 << endl;
	}
	//二分查找
	i = 0;
	j = number-1;
	while (i <= j) {
		k = (i + j) / 2;
		if (n == a[k]) {
			break;
		}
		else if (n < a[k]) {
			j = k - 1;
		}
		else {
			i = k + 1;
		}
	}
	if (i > j) {
		cout << 0 << endl;
	}
	else {
		cout << k + 1 << endl;
	}
}