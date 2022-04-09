/*
��� ������ ����� ����� A[0..n), n �� ����������� 100 000. 
��� �� ����� ������ ��������� ���� (��������������� ������������� ��������� �������) � ���� ������� k, k<=n. 
��������� ��� ������� ��������� ���� (�� 0 � �� n-k) ������� �������� ��������� � ����. 
�������� ������ O(n log n), ������ O(n).

������ �����:
������� �������� n - ���������� ��������� �������. ����� �������� n ����� �� ��������� ������� ��������. ����� �������� k - ������ ����.

������ ������:
����������� �������� �������� ���������� ��� ������� ��������� ����.

������ 1:
����:
1
1
1
�����:
1

������ 2:
����:
3
1 2 3
3
�����:
3

������ 3:
����:
3
1 2 3
1
�����:
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
