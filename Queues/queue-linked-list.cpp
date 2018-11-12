#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *next;
} *front = NULL, *rear = NULL, *temp, *ptr;

void enQueue(int data);
void deQueue(void);
void displayQueue(void);

int main(int argc, char const *argv[]) {
      // This program implements operations on Queue using linked lists

      int size, value, choice;

      cout << "Enter the number of elements you want to enter into the queue..." << endl;
      cin >> size;

      cout << "Enter 1 to fill " << size << " elements in the queue : " << endl;
      cin >> choice;

      while (choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Enter the elements..." << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              enQueue(value);
                        }
                        break;
                  case 2:
                        cout << "Enter the element..." << endl;
                        cin >> value;
                        enQueue(value);
                        break;
                  case 3:
                        cout << "Removing an element from the queue..." << endl;
                        deQueue();
                        break;
                  case 4:
                        cout << "------------------------" << endl;
                        displayQueue();
                        cout << "------------------------" << endl;
                        break;
                  default:
                        cout << "Invalid choice..." << endl;
                        break;
            }
            cout << "Enter a selection to continue..." << endl;
            cout << "Enter 2 to insert a new element in the queue..." << endl;
            cout << "Enter 3 to remove an element in the queue..."  << endl;
            cout << "Enter 4 to display the queue..." << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << endl;
      return 0;
}

void enQueue(int data) {
      if(rear == NULL) {
            rear = new struct node;

            rear->next = NULL;
            rear->data = data;

            front = rear;
      }
      else {
            temp = new struct node;

            rear->next = temp;
            temp->data = data;
            temp->next = NULL;

            rear = temp;
      }
}

void deQueue(void) {
      ptr = front;

      if(ptr == NULL) {
            cout << "Error !" << endl;
            cout << "Queue is empty..." << endl;
            return;
      }
      else {
            if(ptr->next != NULL) {
                  ptr = ptr->next;

                  cout << "Removed : " << ptr->data << endl;
                  free(front);
                  front = ptr;
            }
            else {
                  cout << "Removed : " << ptr->data << endl;
                  free(front);
                  front = ptr;
            }
      }
}

void displayQueue(void) {
      ptr = front;

      if((ptr == NULL) && (rear == NULL)) {
            cout << "Queue is empty..." << endl;
            return;
      }

      while(ptr != rear) {
            cout << ptr->data << " ";
            ptr = ptr->next;
      }
      if(ptr == rear) {
            cout << ptr->data << endl;
      }
}
