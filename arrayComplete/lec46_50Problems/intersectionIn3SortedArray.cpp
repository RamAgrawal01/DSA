#include<iostream>
#include<vector>
using namespace std;



vector<int> intersectionOfSortedArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    vector<int> ans;
    int i, j, k;
    i = j = k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    return ans;
}

void takingArrayInput(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

int main() {
    int p, q, r;
    cout << "Enter number of elements in array 1: ";
    cin >> p;

    vector<int> arr1(p);
    cout << "Enter increasing order elements in array 1: ";
    takingArrayInput(arr1);

    cout << "Enter number of elements in array 2: ";
    cin >> q;

    vector<int> arr2(q);
    cout << "Enter increasing order elements in array 2: ";
    takingArrayInput(arr2);

    cout << "Enter number of elements in array 3: ";
    cin >> r;

    vector<int> arr3(r);
    cout << "Enter increasing order elements in array 3: ";
    takingArrayInput(arr3);

    vector<int> commonElements = intersectionOfSortedArrays(arr1, arr2, arr3);

    cout << "Common elements are: ";
    for (int i = 0; i < commonElements.size(); i++) {
        cout << commonElements[i] << " ";
    }
    cout << endl;

    return 0;
}