/*
Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. 
Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i]. n ≤ 110000, m ≤ 1000. 
Время работы поиска для каждого элемента B[i]: O(log(k)).

Пример 1:
Ввод:
3
10 20 30
3
9 15 35
Вывод:
0 0 2

Пример 2:
Ввод:
3
10 20 30
4
8 9 10 32
Вывод:
0 0 0 2
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

vector<int>::iterator bin_p(vector<int>::iterator l, vector<int>::iterator r, int x){
    while (r-l != 1){
        auto m = l + (r-l)*0.5;
        if (*m > x){
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}


int main(){
    int n, m;
    cin >> n;
    vector<int> a(n);
    input_vector(a);
    cin >> m;
    vector<int> b(m);
    input_vector(b);
    for (auto i : b){
        int r = bin_p(a.begin(), a.end(), i) - a.begin();
        if (r<n-1 && i - a[r] > a[r+1] - i){
            cout << r+1 << " ";
        }else{
            cout << r << " ";
        }
    }
}

