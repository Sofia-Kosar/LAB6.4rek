#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* createR(int n, const int Low, const int High, int i = 0) {
    if (i == n) {
        return new int[n];
    }
    int* a = createR(n, Low, High, i + 1);
    a[i] = Low + rand() % (High - Low + 1);
    return a;
}

void printR(int* a, int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << setw(7) << a[i];
    printR(a, n, i + 1);
}

int MinR(int* a, const int size, int i = 1, int min = INT_MAX) {
    if (i == size) {
        return min;
    }
    if (abs(a[i]) < abs(min)) {
        min = a[i];
    }
    return MinR(a, size, i + 1, min);
}

int sumOfModsAfterZeroR(int* a, int size, int i = 0, int sum = 0, bool foundZero = false) {
    if (i == size) {
        return sum;
    }

    if (!foundZero) {
        foundZero = (a[i] == 0);
    }
    else {
        sum += abs(a[i]);
    }

    return sumOfModsAfterZeroR(a, size, i + 1, sum, foundZero);
}

void rearrangeArray(int a[], int size, int i = 0, int rearrangedIndex = 0, int* rearrangedArray = nullptr) {
    if (i >= size) {
        for (int j = 0; j < size; ++j) {
            a[j] = rearrangedArray[j];
        }
        delete[] rearrangedArray;
        return;
    }

    if (rearrangedArray == nullptr) {
        rearrangedArray = new int[size];
    }

    if (i % 2 == 0) {
        rearrangedArray[rearrangedIndex] = a[i];
        rearrangeArray(a, size, i + 1, rearrangedIndex + 1, rearrangedArray);
    } else {
        rearrangedArray[size / 2 + rearrangedIndex] = a[i];
        rearrangeArray(a, size, i + 1, rearrangedIndex, rearrangedArray);
    }
}




int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    srand((unsigned)time(NULL));
    int Low = -100;
    int High = 100;

    int* a = createR(n, Low, High);

    printR(a, n);
    cout << "min = " << abs(MinR(a, n)) << endl;

    if (MinR(a, n) == 0) {
        cout << "Sum of absolute values after the first zero: " << sumOfModsAfterZeroR(a, n) << endl;
    }
    else {
        cout << "sumOfModsAfterZero is impossible to find because there are no 0 in this array" << endl;
    }

    rearrangeArray(a, n);
    cout << "Rearranged array: ";
    printR(a, n);

    delete[] a;
    return 0;
}