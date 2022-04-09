/*
Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 1000000. 
Отсортировать массив методом поразрядной сортировки LSD по байтам.

Пример:
Ввод:
3
4 1000000 7

Вывод:
4 7 1000000

*/

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int getByte(long long number, size_t n) {
    return number >> (8 * n) & 255;
}


void countingSort(vector<ll>& arr, const size_t n) {
    size_t counters[256];

    for(size_t i = 0; i < 256; i++) {
        counters[i] = 0;
    }

    for(auto i : arr) {
        counters[getByte(i, n)]++;
    }

    for(int i = 1; i < 256; i++) {
        counters[i] += counters[i - 1];
    }

    vector<ll> tmp (arr.size());

    for(int i = arr.size() - 1; ; i--) {
        tmp[--counters[getByte(arr[i], n)]] = arr[i];
        if(i == 0)
            break;
    }
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = tmp[i];
    }
}

void LSDSort(vector<ll>& arr) {
    int totalBytes = sizeof(long long);

    for(int byte = 0; byte < totalBytes; byte++) {
        countingSort(arr, byte);
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    vector<ll> arr (n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    LSDSort(arr);

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}