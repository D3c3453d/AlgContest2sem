/*
Дана последовательность целых чисел из диапазона (-1000000000 .. 1000000000). 
Длина последовательности не больше 1000000. Числа записаны по одному в строке. 
Количество чисел не указано. Пусть количество элементов n, и числа записаны в массиве a = a[i]: i из [0..n-1]. 
Требуется напечатать количество таких пар индексов (i,j) из [0..n-1], что (i < j и a[i] > a[j]). 
Указание: количество инверсий может быть больше 4*1000000000 - используйте int64_t.

Пример 1:
Ввод:
1
2
3
4

Вывод:
0

Пример 2:
Ввод:
4
3
2
1

Вывод:
6

Пример 3:
Ввод:
3
2
2

Вывод:
2

*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end, long long& k){
    vector<int> to_return;
    auto i = begin;
    auto j = mid;
    for (; i != mid && j != end;){
        if (*i <= *j){
            to_return.push_back(*i);
            ++i;
        }else{
            to_return.push_back(*j);
            k += (mid - i);
            ++j;
        }
    }
    while (i != mid){
        to_return.push_back(*i);
        ++i;
    }
    while (j != end){
        to_return.push_back(*j);
        ++j;
    }
    for (i = begin; i != end;++i){
        *i = to_return[i - begin];
    }
}
long long merge_sort(vector<int>::iterator begin, vector<int>::iterator end){
   long long k = 0;
    if (begin+1 == end)return k;
    auto mid = begin + (end-begin)*0.5;
    k += merge_sort(begin, mid);
    k += merge_sort(mid, end);
    merge(begin, mid, end, k);
    return k;
}

int main() {
    int tmp;
    vector<int> arr;
    while (cin >> tmp)arr.push_back(tmp);
    long long k = merge_sort(arr.begin(), arr.end());
    cout << k << endl;
}
