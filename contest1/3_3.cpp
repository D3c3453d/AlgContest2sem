/*
Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1]. n » m. 
Найдите их пересечение. Требуемое время работы: O(m * log k), где k - позиция элементта B[m-1] в массиве A.
В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. n, k ≤ 10000.

Пример:
Ввод:
5¶
3¶
1 2 3 4 5¶
1 3 5¶
Вывод:
1 3 5¶
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
    cin >> n >> m;
    vector<int> a(n);
    input_vector(a);
    vector<int> b(m);
    input_vector(b);
    auto prev = a.begin();
    for (auto i : b){
        prev = bin_p(prev, a.end(), i);
        if (*prev == i){
            cout << i << " ";
        }
    }
}

