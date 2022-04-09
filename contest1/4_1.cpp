/*
Реализовать очередь с динамическим зацикленным буфером.
Обрабатывать команды push back и pop front.

Формат ввода:
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.
a = 2 - pop front
a = 3 - push back
Если дана команда pop front, то число b - ожидаемое значение. Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.
Формат вывода
Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

Пример 1:
Ввод:
3
3 44
3 50
2 44
Вывод:
YES

Пример 2:
Ввод:
2
2 -1
3 10
Вывод:
YES

Пример 3:
Ввод:
2
3 44
2 66
Вывод:
NO
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>
#include <stack>

using namespace std;

int MAX_N = 1000000;

class Queue{
    int* buffer;
    int size;
    int start = 0;
    int last = 0;
    void growSize() {
        int newSize = 1000000,
        *newBuffer = new int[1000000];
        if(start != last) {
            int j = 0;
            for(int i = start; i < size; i++) {
                if(i == last) {
                    break;
                }
                newBuffer[j++] = buffer[i];

                if(i == size - 1) {
                    i = -1;
                }
            }
            start = 0;
            last = j;
        }
        if(buffer != NULL) {
            delete[] buffer;
        }

        buffer = newBuffer;
        size = newSize;
    }
public:
    Queue(){
        buffer = NULL;
        size = 0;
        start = 0;
        last = 0;
        growSize();
    };

    ~Queue() {
        if(buffer != NULL) {
            delete[] buffer;
        }
    }

    void push(int x){
        if((last + 1) % size == start) {
            growSize();
            push(x);
        }
        else
        {
            buffer[(last) % size] = x;
            last = (last + 1) % size;
        }
    }
    int front(){
        if (start == last)return -1;
        int t =  buffer[start];
        if (start == size - 1)start = 0;
        else start ++;
        return t;
    }
    bool empty(){
        return (start == last);
    }
};



int main(){
    Queue q;
    int n;
    cin >> n;
    int command, val;
    bool flag = true;
    while(n--){
        cin >> command >> val;
        if (command == 2){
            flag*=(val==q.front());
        }else{
            q.push(val);
        }
    }
    if (flag)
        cout << "YES";
    else cout << "NO";
}
