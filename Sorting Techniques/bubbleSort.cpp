#include <iostream>
using namespace std;

class BubbleSort {
public:
      BubbleSort(int arr[], int n) {
            bool swapped = NULL;

            for(int i = 0; i < (n - 1); i++) {
                  swapped = false;
                  for(int j = 0; j < ((n - i) - 1); j++) {
                        if(arr[j] > arr[j + 1]) {
                              swap(&arr[j], &arr[j + 1]);
                              swapped = true;
                        }
                  }

                  if(swapped == false) {
                        break;
                  }
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
      BubbleSort sorting(arr, size);
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
