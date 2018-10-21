#include <iostream>
using namespace std;

class MergeSort {
public:
      MergeSort(int arr[], int left, int right) {
            if(left < right) {
                  int middle = ((left + (right - 1)) / 2);

                  MergeSort(arr, left, middle);
                  MergeSort(arr, (middle + 1), right);

                  merge(arr, left, middle, right);
            }
      }

      void merge(int arr[], int left, int middle, int right) {
            int a = ((middle - left ) + 1);
            int b = (right - middle);
            int tempArr1[a];
            int tempArr2[b];

            for(int i = 0; i < a; i++) {
                  tempArr1[i] = arr[left + i];
            }
            for(int j = 0; j < b; j++) {
                  tempArr2[j] = arr[(middle + 1) + j];
            }

            int i = 0, j = 0, k = left;

            while(i < a && j < b) {
                  if(tempArr1[i] <= tempArr2[j]) {
                        arr[k] = tempArr1[i];
                        i++;
                  }
                  else {
                        arr[k] = tempArr2[j];
                        j++;
                  }
                  k++;
            }
            while(i < a) {
                  arr[k] = tempArr1[i];
                  i++;
                  k++;
            }
            while(j < b) {
                  arr[k] = tempArr2[j];
                  j++;
                  k++;
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
      MergeSort sorting(arr, 0, (size - 1));
      cout << "Sorted..." << endl;

      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
