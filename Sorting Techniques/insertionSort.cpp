#include <iostream>
using namespace std;

class InsertionSort {
public:
      InsertionSort(int arr[], int n) {
            int key = 0, j = 0;

            for(int i = 1; i < n; i++) {
                  key = arr[i];
                  j = (i - 1);
                  while(j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j -= 1;
                  }

                  arr[j + 1] = key;
            }
      }
};

int main(int argc, char const *argv[]) {
      int size;
      cout << "Enter the size of the array: ";
      cin >> size;

      int arr[size];
      cout << "Fill the array: " << endl;
      for(int i = 0; i < size; i++) {
            cin >> arr[i];
      }

      cout << "Sorting the array" << endl;
      InsertionSort sorting(arr, size);
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
