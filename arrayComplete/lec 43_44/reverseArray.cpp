#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main() {
    int arr[7];
    int size = 7;
    cout << "Enter the 7 values in array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
   
    cout << "Your array is: ";
    printArray(arr, size); 
    cout << endl;
    
    int start = 0;
    int end = size - 1;
    cout << "Your reversed array is: ";
    
    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printArray(arr, size); 

    return 0;
}