#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *next;
};

class CircularLinkedList {
public:
      struct node *last;

      CircularLinkedList() {
            cout << "--------------------------------" << endl;
            cout << "Initialising List..." << endl;
            this->last = NULL;
            cout << "Circular Linked list initialised" << endl;
            cout << "--------------------------------" << endl;
      }

      struct node *insertElements(struct node *last, int data) {
            cout << "--------------------------------" << endl;
            if(last != NULL) {
                  return last;
            }

            struct node *temp = new struct node;
            temp->data = data;
            last = temp;

            return last;
            cout << "--------------------------------" << endl;
      }

      struct node *insertElementAfter(struct node *previous, int value, int position) {
            cout << "--------------------------------" << endl;
            if(previous == NULL) {
                  return NULL;
            }

            struct node *temp, *ptr = previous->next;

            do {
                  if(ptr->data == position) {
                        temp = new struct node;
                        temp->data = value;
                        temp->next = ptr->next;
                        ptr->next = temp;

                        if(ptr == previous) {
                              previous = temp;
                        }

                        return previous;
                  }
                  ptr = ptr->next;
            } while(ptr != previous->next);

            cout << "Operation can't be performed" << endl;
            return previous;

            cout << "--------------------------------" << endl;
      }

      struct node *insertAtBeginning(struct node *last, int data) {
            cout << "--------------------------------" << endl;
            if(last == NULL) {
                  return insertElements(last, data);
            }

            struct node *temp = new struct node;
            temp->data = data;
            temp->next = last->next;
            last->next = temp;

            return last;
            cout << "--------------------------------" << endl;
      }

      struct node *insertAtEnd(struct node *last, int data) {
            cout << "--------------------------------" << endl;
            if(last == NULL) {
                  return insertElements(last, data);
            }

            struct node *temp = new struct node;
            temp->data = data;
            temp->next = last->next;
            last->next = temp;
            last = temp;

            return last;
            cout << "--------------------------------" << endl;
      }

      void deleteAnElement(struct node *last, int data) {
            cout << "--------------------------------" << endl;
            if(last == NULL) {
                  return;
            }

            struct node *current = last, *previous;
            while(current->data != data) {
                  if(current->next == last) {
                        cout << "Element not found..." << endl;
                        break;
                  }

                  previous = current;
                  current = current->next;
            }

            if(current->next == last) {
                  last = NULL;
                  free(current);
                  return;
            }
            if(current == last) {
                  previous = last;
                  while(previous->next != last) {
                        previous = previous->next;
                  }

                  last = current->next;
                  previous->next = last;
                  free(current);
            }
            else if(current->next == last) {
                  previous->next = last;
                  free(current);
            }
            else {
                  previous->next = current->next;
                  free(current);
            }

            cout << "--------------------------------" << endl;
      }

      void searchElement(struct node *last, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = last;
            bool flag = false;

            do {
                  if(temp == NULL) {
                        return;
                  }
                  if(temp->data == data) {
                        cout << "Element found" << endl;
                        flag = true;
                  }

                  temp = temp->next;
            } while(temp != last);

            if(flag == false) {
                  cout << "Element not found" << endl;
            }
            cout << "--------------------------------" << endl;
      }

      void printList(struct node *last) {
            cout << "--------------------------------" << endl;
            struct node *temp;

            if(last == NULL) {
                  cout << "Circular linked list is empty" << endl;
                  return;
            }

            temp = last->next;
            do {
                  cout << temp->data << " ";
                  temp = temp->next;
            } while(temp != last->next);

            cout << "\n--------------------------------" << endl;
      }
};

int main(int argc, char const *argv[]) {
      cout << "--------------------------------" << endl;
      // This Program function implements all the operations on the Circular Linked List Class;
      int size, value, choice, position;

      cout << "Enter the size of the circular linked list: ";
      cin >> size;

      CircularLinkedList cirList;

      cout << "Enter 1 to fill " << size << " elements in the circular linked list." << endl;
      cin >> choice;

      while(choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Inserting elements" << endl;
                        cout << "Enter the elements: " << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              cirList.last = cirList.insertElements(cirList.last, value);
                        }
                        break;
                  case 2:
                        cout << "Insertion at specified position" << endl;
                        cout << "Enter a position: ";
                        cin >> position;
                        cout << "Enter a value: ";
                        cin >> value;
                        cirList.last = cirList.insertElementAfter(cirList.last, value, position);
                        break;
                  case 3:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        cirList.last = cirList.insertAtEnd(cirList.last, value);
                        break;
                  case 4:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        cirList.last = cirList.insertAtBeginning(cirList.last, value);
                        break;
                  case 5:
                        cout << "Deleting..." << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        cirList.deleteAnElement(cirList.last, value);
                        break;
                  case 6:
                        cout << "Performing Search \n Enter a value: " << endl;
                        cin >> value;
                        cirList.searchElement(cirList.last, value);
                        break;
                  case 7:
                        cout << endl;
                        cirList.printList(cirList.last);
                        break;
                  default:
                        cout << "Enter a valid value..." << endl;
                        break;
            }

            cout << "Enter a selection to continue" << endl;
            cout << "Enter 2 to insert a new element after an element." << endl;
            cout << "Enter 3 to insert a new element at the end."  << endl;
            cout << "Enter 4 to insert a new element at the beginning." << endl;
            cout << "Enter 5 to delete an element with a provided value." << endl;
            cout << "Enter 6 to search for an element" << endl;
            cout << "Enter 7 to display the circular linked list." << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << "--------------------------------" << endl;
      return 0;
}
