#include <iostream>;
#include <string>;
using namespace std;

bool my_fun(int* arr, int size, int element) {
	for (int i = 0; i < size; ++i) {
		if (*(arr + i) == element) {
			return false;
		}
	}
	return true;
}

bool in_arr(int* arr, int size, int element) {
	for (int i = 0; i < size; ++i) {
		if (*(arr + i) == element) {
			return true;
		}
	}
	return false;
}

int main() {
	int M, N;
	int* A = new int[M];
	cout << "Enter the M: ";
	cin >> M;
	cout << "Enter the elements of the first array: ";
	
	for (int i = 0; i < M; ++i) {
		cout << "Enter the " << i + 1 << " element: ";
		cin >> A[i];
	}

	cout << "Enter the N: ";
	cin >> N;
	int* B = new int[N];
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < N; ++i) {
		cout << "Enter the " << i + 1 << " element: ";
		cin >> B[i];
	}

	int max_width = M + N;
	int* C = new int[max_width];
	int k = 0;

	for (int i = 0; i < M; ++i) {
		if (!in_arr(C, k, A[i])) {
			C[k] = A[i];
			++k;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (!in_arr(C, k, B[i])) {
			C[k] = B[i];
			++k;
		}
	}

	cout << "Unique elements in A and B that are not common: ";
	for (int i = 0; i < k; ++i) {
		cout << C[i] << " ";
	}
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] C;

	system("pause");
	return 0;
}