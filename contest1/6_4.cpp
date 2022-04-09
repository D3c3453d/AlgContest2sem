/*
Дан массив целых чисел A[0..n), n не превосходит 100 000. 
Так же задан размер некотрого окна (последовательно расположенных элементов массива) в этом массиве k, k<=n. 
Требуется для каждого положения окна (от 0 и до n-k) вывести значение максимума в окне. 
Скорость работы O(n log n), память O(n).

Формат ввода:
Вначале вводится n - количество элементов массива. Затем вводится n строк со значением каждого элемента. Затем вводится k - размер окна.

Формат вывода:
Разделенные пробелом значения максимумов для каждого положения окна.

Пример 1:
Ввод:
1
1
1
Вывод:
1

Пример 2:
Ввод:
3
1 2 3
3
Вывод:
3

Пример 3:
Ввод:
3
1 2 3
1
Вывод:
1 2 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

void print_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void input_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }
}



int find_max_in_set(multiset<int>& s){
    int max = *s.begin();
    for (auto i : s){
        if (i > max)max = i;
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    input_vector(arr);
    int k;
    cin >> k;
    multiset<int> window;
    for (int i  = 0; i < k; ++ i){
        window.insert(arr[i]);
    }
    int cur_max = find_max_in_set(window);
    cout << cur_max << " ";
    for (int i = 1; i + k <= n; ++i){
        window.erase(window.find(arr[i - 1]));
        window.insert(arr[i+k-1]);
        if (arr[i+k-1]>cur_max)cur_max=arr[i+k-1];
        if (arr[i - 1] == cur_max)cur_max = find_max_in_set(window);
        cout << cur_max << " ";
    }


}
