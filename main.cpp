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

    cout << "Enter the size of the first array (M): ";
    cin >> M;
    int* A = new int[M];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < M; ++i) {
        cin >> *(A + i);
    }

    cout << "Enter the size of the second array (N): ";
    cin >> N;
    int* B = new int[N];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < N; ++i) {
        cin >> *(B + i);
    }

    int max_size = M;
    int* C = new int[max_size];
    int current_size = 0;

    for (int i = 0; i < M; ++i) {
        if (!in_arr(B, N, *(A + i)) && my_fun(C, current_size, *(A + i))) {
            *(C + current_size) = *(A + i);
            current_size++;
        }
    }

    cout << "Elements of array A that are not in array B (without duplicates): ";
    for (int i = 0; i < current_size; ++i) {
        cout << *(C + i) << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

	system("pause");
	return 0;
}