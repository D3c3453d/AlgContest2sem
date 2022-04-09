/*
Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго возрастают, а на интервале [m, n-1] строго убывают. 
Найти m за O( log m ).
2 ≤ n ≤ 10000.

Пример:
Ввод:
10
1 2 3 4 5 6 7 6 5 4

Вывод:
6
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

int bin_p(vector<int>& arr){
    int l = 0, r= arr.size();
    int m = l + (r-l)/2;
    while (r-l > 1) {
        m = l + (r - l) / 2;
        if (arr[m-1]<arr[m] && arr[m] > arr[m+1])
            return m;
        if (arr[m-1]>arr[m] && arr[m] > arr[m+1])
            r = m;
        if (arr[m-1]<arr[m] && arr[m] < arr[m+1])
            l = m;
    }
    return l;
}

int main(){
    int n, m;
    cin >> n;
    vector<int> a(n);
    input_vector(a);
    cout << bin_p(a);
}

