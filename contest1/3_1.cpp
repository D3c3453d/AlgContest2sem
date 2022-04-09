/*
Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. 
Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A, равного или превосходящего B[i]: A[k] >= B[i]. 
Если такого элемента нет, выведите n. Время работы поиска k для каждого элемента B[i]: O(log(k)). n, m ≤ 10000.

Формат ввода:
В первой строчке записаны числа n и m. Во второй и третьей массивы A и B соответственно.

Пример 1:
Ввод:
2 1¶
1 2¶
2¶

Вывод:
1¶

Пример 2:
Ввод:
4 3¶
2 4 5 7¶
4 6 1¶

Вывод:
1 3 0¶
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

void step(){
    char r;
    cin >> r;
}

void input_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }
}

void print_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bin_p(int x, vector<int>& arr){
    int l = 0, r= arr.size();
    int m = l + (r-l)/2;
    while (r-l > 1) {
        m = l + (r - l) / 2;
        if (arr[m] < x)l = m;
        else r = m;
    }
    return arr[l] >= x?l:r;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    input_vector(a);
    input_vector(b);
    for (int i = 0; i < m; ++ i){
        cout << bin_p(b[i], a) << " ";
    }
}

