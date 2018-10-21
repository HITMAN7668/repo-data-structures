#include <iostream>
using namespace std;

class HeapSort {
public:
      HeapSort(int arr[], int n) {
            for(int i = ((n / 2) - 1); i >= 0; i--) {
                  heapify(arr, n, i);
            }

            for(int i = (n - 1); i >= 0; i--) {
                  swap(&arr[0], &arr[i]);
                  heapify(arr, i, 0);
            }
      }

      void heapify(int arr[], int n, int i) {
            int max = i;
            int left = ((2 * i) + 1);
            int right = ((2 * i) + 2);

            if(left < n && arr[left] > arr[max]) {
                  max = left;
            }
            if(right < n && arr[right] > arr[max]) {
                  max = right;
            }

            if(max != i) {
                  swap(&arr[i], &arr[max]);
                  heapify(arr, n, max);
            }
      }

      void swap(int *a, int *b) {
            *a = *a ^ *b;
            *b = *a ^ *b;
            *a = *a ^ *b;
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
      HeapSort sorting(arr, size);
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
