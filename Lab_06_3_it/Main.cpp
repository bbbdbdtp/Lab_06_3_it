#include <iostream>
#include <iomanip>

using namespace std;

void fillArray(int arr[], int size) {
    cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << setw(4);
    }
    cout << endl;
}

template <typename T>
void fillArray(T arr[], int size) {
    cout << "Enter " << size << " elements for the array <T>:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << setw(4);
    }
    cout << endl;
}

int countNegativeElements(const int arr[], const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            ++count;
        }
    }
    return count;
}

template <typename T>
int countNegativeElementsT(const T arr[], const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count += (arr[i] < 0 ? 1 : 0);
    }

    cout << "Number of negative elements in array <T>: " << count << endl;
    return count;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cerr << "Invalid array size\n";
        return 1;
    }

    int* arr = new int[size];

    fillArray(arr, size);
    printArray(arr, size);

    double* arrDouble = new double[size];
    fillArray(arrDouble, size);
    printArray(arrDouble, size);

    int result = countNegativeElements(arr, size);
    cout << "Number of negative elements in array: " << result << endl;

    int resultArrayT = countNegativeElementsT(arr, size);

    delete[] arr;
    delete[] arrDouble;

    return 0;
}