#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

class MyArray {
private:
    int arr[MAX_SIZE];
    int size;

public:

    MyArray() {
        size = 0;
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (size == MAX_SIZE) {
            cout << "Array is full!" << endl;
            return;
        }

        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        size++;
    }


    int Delete_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                cout << "index of " << value << " = " << i << " --Deleted-- " << endl;
            }
        }
        return 1;
    }


    void Delete_By_Index(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        cout << "Deleted By Index :" << index << endl;
        size--;
    }


    void Display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void Append(int value) {
        if (size == MAX_SIZE) {
            cout << "Array is full!" << endl;
        }
        else {
            arr[size++] = value;
        }
    }


    void Reverse() {
        int start = 0;
        int end = size - 1;
        int temp;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void Search_By_Value(int value) {
        for (int i = 0; i <= size - 1; i++) {
            if (arr[i] == value) {
                cout << "index of " <<value<<"="<< i << endl;
            }

        }
    }
};