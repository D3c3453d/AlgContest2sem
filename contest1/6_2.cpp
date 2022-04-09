/*
��� �������� ����� ������������ ������ ���������. �����, ������������� �� ���������� ����� ���� ����� ����� �� �����. 
����� ������� ��� ���������� ����� ����� 1,2,3 ����� ������������� ������ �����, � ����������� �� ������� ����������. 
((1+2)+3) -> 1+2 + 3+3 = 9 ((1+3)+2) -> 1+3 + 4+2 = 10 ((2+3)+1) -> 2+3 + 5+1 = 11 
��������� �������� ���������, ������� ���������� ����������� �����, 
����������� ��� ���������� ����� ��������� ������ �����. ��������� ����� ������ O(n*log(n)).

������ �����:
������� �������� n (n < 100) - ���������� �����. 
����� �������� n ����� - �������� ����� (�������� ������� ����� �� ����������� 1 000 000 000, 
����� ���� ����� �� ����������� 2 * 1 000 000 000).

������ ������:
����������� ����� - ����������� �����.

������:
����:
5
5 2 3 4 6

�����:
45
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

struct Heap{
    vector<int> arr;
    void SiftDown(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if (left < arr.size() && arr[left] < arr[largest])largest = left;
        if (right < arr.size() && arr[right] < arr[largest])largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            SiftDown(largest);
        }
    }

    void SiftUp(int i){
        while (i >0){
            int parent = (i-1)/2;
            if (arr[i] >= arr[parent]) return;
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
    int get_min(){
        if (arr.empty())return 0;
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
    for (int i = 0; i < n; ++ i){
        int t;
        cin >> t;
        h.add(t);
    }
    int time = 0;
    while (h.size() >1){
        int t = h.get_min();
        t += h.get_min();
        time += t;
        h.add(t);
    }
    cout << time;
}
