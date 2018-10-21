#include <iostream>
using namespace std;

class SelectionSort {
public:
      SelectionSort(int arr[], int n) {
            int minIndex;

            for(int i = 0; i < (n - 1); i++) {
                  minIndex = i;
                  for(int j = (i + 1); j < n; j++) {
                        if(arr[j] < arr[minIndex]) {
                              minIndex = j;
                        }
                  }

                  swap(&arr[minIndex], &arr[i]);
            }
      }

      void swap(int *a, int *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
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
      SelectionSort sorting(arr, size);
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
