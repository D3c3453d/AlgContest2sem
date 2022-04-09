/*
Вовочка ест фрукты из бабушкиной корзины.
В корзине лежат фрукты разной массы. Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. 
За раз он выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, 
откусывает от каждого половину и кладет огрызки обратно в корзину. 
Если фрукт весит нечетное число грамм, он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
Определить за сколько подходов Вовочка съест все фрукты в корзине.

Формат ввода:
Вначале вводится n - количество фруктов и n строк с массами фруктов. n ≤ 50000.
Затем K - "грузоподъемность". K ≤ 1000.

Формат вывода:
Неотрицательное число - количество подходов к корзине.

Пример 1:
Ввод:
3
1 2 2
2
Вывод:
4

Пример 2:
Ввод:
3
4 3 5
6
Вывод:
5

Пример 3:
Ввод:
7
1 1 1 1 1 1 1
3
Вывод:
3
*/

#include <iostream>
#include <vector>

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
    int get_max(){
        int to_ret = arr[0];
        arr[0] = *arr.rbegin();
        arr.resize(arr.size() - 1);
        SiftDown(0);
        return to_ret;
    }
    void print(){
        cout << "|";
        for (auto i: arr){
            cout << i << " " ;
        }
        cout << "|\n";
    }
};

int main() {
    int n;
    cin >> n;
    Heap h;
    while (n --){
        int tmp;
        cin >> tmp;
        h.add(tmp);
    }
    int k, steps = 0;
    cin >> k;
    while (h.size()){
        ++steps;
        vector<int> buf;
        int c = 0;
        while (c<= k && h.size()){
            int t = h.get_max();
            c += t;
            if (c <= k)
                buf.push_back(t);
            else
                h.add(t);
        }
        for (auto i: buf){
            if (i/2 !=0)
                h.add(i/2);
        }
    }
    cout << steps;
    return 0;

}
