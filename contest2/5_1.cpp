/*
Дан массив строк. Количество строк не больше 100000. Отсортировать массив методом поразрядной сортировки MSD по символам. 
Размер алфавита - 256 символов. Последний символ строки = ‘0’.

Пример:
Ввод:
ab
a
aaa
aa

Вывод:
a
aa
aaa
ab

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int _k = 256;



void print_vector(vector<string>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << endl;
    }
    cout << endl;
}



void countingSort(vector<string>::iterator beg, vector<string>::iterator end, int n, vector<int>& counter, int byte){
    for(int i = 0; i < _k; i++)
        counter[i] = 0;
    for(auto i = beg; i!= end; ++i)
        counter[(*i)[byte]]++;

    int sum = 0;
    for(int i = 0; i < _k; i++){
        int tmp = counter[i];
        counter[i] = sum;
        sum += tmp;
    }
    vector<string> brr(n);
    for(auto i = beg; i!= end; ++i){
        brr[counter[(*i)[byte]]++] = *i;
    }
    for (auto i = beg; i!= end; ++i){
        *i = brr[i - beg];
    }
}

void MSD(vector<string>::iterator beg, vector<string>::iterator end, int n, int byte){
    if(n <= 1)
        return;

    vector<int> counter(_k+1);
    counter[_k] = n - 1;

    countingSort(beg, end, n, counter, byte);

    for(int i = 1; i < _k; i++)
        MSD(beg + counter[i], beg + counter[i+1], counter[i + 1] - counter[i], byte + 1);

}
int main() {
   
    string c;
    vector<string> arr, answer;

    while(cin >> c){
        arr.push_back(c);
    }
    int n = arr.size();
    vector<int> counter(_k);
    MSD(arr.begin(), arr.end(), n,0);
    print_vector(arr);
    return 0;
}
