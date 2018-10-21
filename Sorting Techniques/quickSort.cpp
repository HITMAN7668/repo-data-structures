#include <iostream>
using namespace std;

class QuickSort {
public:
      QuickSort(int arr[], int low, int high) {
            if(low < high) {
                  int index = pivoting(arr, low, high);

                  QuickSort(arr, low, (index - 1));
                  QuickSort(arr, (index + 1), high);
            }
      }

      void swap(int *a, int *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
      }

      int pivoting(int arr[], int low, int high) {
            int pivot = arr[high];
            int i = (low - 1);

            for(int j = low; j <= (high - 1); j++) {
                  if(arr[j] <= pivot) {
                        i++;
                        swap(&arr[i], &arr[j]);
                  }
            }

            swap(&arr[i + 1], &arr[high]);

            return (i + 1);
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
      QuickSort sorting(arr, 0, (size - 1));
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
