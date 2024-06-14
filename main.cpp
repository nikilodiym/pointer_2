#include <iostream>;
#include <string>;
using namespace std;

int main() {
    int M;

    cout << "Enter the size of the array (M): ";
    cin >> M;
    int* A = new int[M];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < M; ++i) {
        cin >> *(A + i);
    }

    int choice;
    cout << "Choose what to remove: \n";
    cout << "1. Remove even values\n";
    cout << "2. Remove odd values\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int new_size = 0;
    for (int i = 0; i < M; ++i) {
        if ((choice == 1 && *(A + i) % 2 != 0) || (choice == 2 && *(A + i) % 2 == 0)) {
            new_size++;
        }
    }

    int* B = new int[new_size];
    int index = 0;
    for (int i = 0; i < M; ++i) {
        if ((choice == 1 && *(A + i) % 2 != 0) || (choice == 2 && *(A + i) % 2 == 0)) {
            *(B + index) = *(A + i);
            index++;
        }
    }

    cout << "Resulting array: ";
    for (int i = 0; i < new_size; ++i) {
        cout << *(B + i) << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;

	system("pause");
	return 0;
}