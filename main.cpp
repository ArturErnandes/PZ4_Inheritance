#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

class DynamicArray {
protected:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        if (n <= 0) {
            cout << "Ошибка: размер массива должен быть положительным!" << endl;
            size = 0;
            data = nullptr;
        } else {
            size = n;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            return;
        }
        if (value < -100 || value > 100) {
            cout << "Ошибка диапазона значения!" << endl;
            return;
        }
        data[index] = value;
    }

    int getValue(int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            return 0;
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

class AdvancedArray : public DynamicArray {
public:
    AdvancedArray(int n) : DynamicArray(n) {}
    AdvancedArray(const DynamicArray& other) : DynamicArray(other) {}

    double average() const {
        if (size == 0) return 0.0;
        double sum = 0;
        for (int i = 0; i < size; i++) sum += data[i];
        return sum / size;
    }

    double median() const {
        if (size == 0) return 0.0;
        int* temp = new int[size];
        for (int i = 0; i < size; i++) temp[i] = data[i];
        sort(temp, temp + size);

        double med;
        if (size % 2 == 0)
            med = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        else
            med = temp[size / 2];

        delete[] temp;
        return med;
    }

    int minValue() const {
        if (size == 0) return 0;
        int minVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < minVal) minVal = data[i];
        return minVal;
    }

    int maxValue() const {
        if (size == 0) return 0;
        int maxVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > maxVal) maxVal = data[i];
        return maxVal;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "=== Тест ЗАДАНИЕ 5 ===" << endl;

    AdvancedArray arr(5);
    arr.setValue(0, 10);
    arr.setValue(1, 40);
    arr.setValue(2, 30);
    arr.setValue(3, 20);
    arr.setValue(4, 50);

    cout << "Массив: ";
    arr.print();

    cout << "Среднее значение: " << arr.average() << endl;
    cout << "Медиана: " << arr.median() << endl;
    cout << "Минимум: " << arr.minValue() << endl;
    cout << "Максимум: " << arr.maxValue() << endl;

    return 0;
}