/*
Дана очень длинная последовательность целых чисел длины n. Требуется вывести в отсортированном виде её наименьшие k элементов. 
Последовательность может не помещаться в память. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.

Пример:
Ввод:
9 4
3 7 4 5 6 1 15 4 2

Вывод:
1 2 3 4

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Heap{
    vector<int> arr;
    void SiftDown(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if (left < arr.size() && arr[left] > arr[largest])largest = left;
        if (right < arr.size() && arr[right] > arr[largest])largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            SiftDown(largest);
        }
    }

    void SiftUp(int i){
        while (i >0){
            int parent = (i-1)/2;
            if (arr[i] <= arr[parent]) return;
            swap(arr[i], arr[parent]);
            i = parent;
        }
    }
    int size(){
        return arr.size();
    }
    void add(int x){
        arr.push_back(x);
        SiftUp(arr.size() - 1);
    }
    int pop_max(){
        if (arr.empty())return -1;
        int to_ret = arr[0];
        arr[0] = *arr.rbegin();
        arr.resize(arr.size() - 1);
        SiftDown(0);
        return to_ret;
    }
    int see_max(){
        return arr[0];
    }
    void print(){
        cout << "|";
        for (auto i: arr){
            cout << i << " " ;
        }
        cout << "|\n";
    }
    void get_sorted(){
        sort(arr.begin(), arr.end());
        for (auto i: arr){
            cout << i << " ";
        }
        cout << endl;
    }
};

void print_vector(std::vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main ()
{
    Heap h;
    int n, k;
    cin >> n >> k;
    while(n --){
        int a;
        cin >> a;
        if (h.size() == k){
            h.add(min(h.pop_max(), a));
        } else{
            h.add(a);
        }
    }
    h.get_sorted();
}
