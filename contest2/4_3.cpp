/*
���� ������������������ ����� ����� �� ��������� (-1000000000 .. 1000000000). 
����� ������������������ �� ������ 1000000. ����� �������� �� ������ � ������. 
���������� ����� �� �������. ����� ���������� ��������� n, � ����� �������� � ������� a = a[i]: i �� [0..n-1]. 
��������� ���������� ���������� ����� ��� �������� (i,j) �� [0..n-1], ��� (i < j � a[i] > a[j]). 
��������: ���������� �������� ����� ���� ������ 4*1000000000 - ����������� int64_t.

������ 1:
����:
1
2
3
4

�����:
0

������ 2:
����:
4
3
2
1

�����:
6

������ 3:
����:
3
2
2

�����:
2

*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end, long long& k){
    vector<int> to_return;
    auto i = begin;
    auto j = mid;
    for (; i != mid && j != end;){
        if (*i <= *j){
            to_return.push_back(*i);
            ++i;
        }else{
            to_return.push_back(*j);
            k += (mid - i);
            ++j;
        }
    }
    while (i != mid){
        to_return.push_back(*i);
        ++i;
    }
    while (j != end){
        to_return.push_back(*j);
        ++j;
    }
    for (i = begin; i != end;++i){
        *i = to_return[i - begin];
    }
}
long long merge_sort(vector<int>::iterator begin, vector<int>::iterator end){
   long long k = 0;
    if (begin+1 == end)return k;
    auto mid = begin + (end-begin)*0.5;
    k += merge_sort(begin, mid);
    k += merge_sort(mid, end);
    merge(begin, mid, end, k);
    return k;
}

int main() {
    int tmp;
    vector<int> arr;
    while (cin >> tmp)arr.push_back(tmp);
    long long k = merge_sort(arr.begin(), arr.end());
    cout << k << endl;
}
