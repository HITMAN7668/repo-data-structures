#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *next;
};

class LinkedList {
public:
      struct node *head;

      LinkedList(int num) {
            cout << "--------------------------------" << endl;
            cout << "Initialising List..." << endl;
            this->head = NULL;
            cout << "Linked list initialised" << endl;
            cout << "--------------------------------" << endl;
      }

      void insertElements(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *newNode = new struct node;

            newNode->data = data;
            newNode->next = (*head);
            (*head) = newNode;
            cout << "--------------------------------" << endl;
      }

      void insertElementAfter(struct node *previous, int position, int value) {
            cout << "--------------------------------" << endl;
            if(previous == NULL) {
                  cout << "Operation can't be performed..." << endl;
                  return;
            }

            struct node *temp = new struct node;

            for(int i = 0; i < (position + 1); i++) {
                  if(temp != NULL && temp->next != NULL) {
                        temp = temp->next;
                  }
            }

            temp->data = value;
            temp->next = previous->next;
            previous->next = temp;
            cout << "--------------------------------" << endl;
      }

      void insertAtBeginning(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = new struct node;

            temp->data = data;
            temp->next = (*head);
            (*head) = temp;
            cout << "--------------------------------" << endl;
      }

      void insertAtEnd(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = new struct node;
            struct node *last = (*head);

            temp->data = data;
            temp->next = NULL;

            if((*head) == NULL) {
                  (*head) = temp;
                  return;
            }

            while(last->next != NULL) {
                  last = last->next;
            }

            last->next = temp;
            return;
            cout << "--------------------------------" << endl;
      }

      void deleteAnElement(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = *head, *previous;

            if(temp != NULL && temp->data == data) {
                  (*head) = temp->next;
                  free(temp);
                  return;
            }

            while(temp != NULL && temp->data != data) {
                  previous = temp;
                  temp = temp->next;
            }

            if(temp == NULL) {
                  return;
            }

            previous->next = temp->next;
            free(temp);
            cout << "--------------------------------" << endl;
      }

      void searchElement(struct node *head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = head;
            bool flag = false;

            while(temp != NULL) {
                  if(temp->data == data) {
                        cout << "Element found" << endl;
                        flag = true;
                  }
                  temp = temp->next;
            }

            if(flag == false) {
                  cout << "Element not found" << endl;
            }
            cout << "--------------------------------" << endl;
      }

      void printList(struct node *head) {
            cout << "--------------------------------" << endl;
            while(head != NULL) {
                  cout << head->data << " ";
                  head = head->next;
            }
            cout << endl;
            cout << "--------------------------------" << endl;
      }

      void deleteList(struct node **head) {
            cout << "--------------------------------" << endl;
            struct node *current = (*head);
            struct node *next;

            while(current != NULL) {
                  next = current->next;
                  free(current);
                  current = next;
            }

            (*head) = NULL;
            cout << "--------------------------------" << endl;
      }
};

int main(int argc, char const *argv[]) {
      cout << "--------------------------------" << endl;
      // This Program function implements all the operations on the Linked List Class;
      int size, value, choice, position;

      cout << "Enter the size of the linked list: ";
      cin >> size;

      LinkedList list(size);

      cout << "Enter 1 to fill " << size << " elements in the linked list." << endl;
      cin >> choice;

      while(choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Inserting elements" << endl;
                        cout << "Enter the elements: " << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              list.insertElements(&list.head, value);
                        }
                        break;
                  case 2:
                        cout << "Insertion at specified position" << endl;
                        cout << "Enter a position: ";
                        cin >> position;
                        cout << "Enter a value: ";
                        cin >> value;
                        list.insertElementAfter(list.head, position, value);
                        break;
                  case 3:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        list.insertAtEnd(&list.head, value);
                        break;
                  case 4:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        list.insertAtBeginning(&list.head, value);
                        break;
                  case 5:
                        cout << "Deleting..." << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        list.deleteAnElement(&list.head, value);
                        break;
                  case 6:
                        cout << "Performing Search \n Enter a value: " << endl;
                        cin >> value;
                        list.searchElement(list.head, value);
                        break;
                  case 7:
                        cout << endl;
                        list.printList(list.head);
                        break;
                  case 8:
                        cout << "------------------------->" << endl;
                        list.deleteList(&list.head);
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
            cout << "Enter 7 to display the linked list." << endl;
            cout << "Enter 8 to clear the whole linked list" << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << "--------------------------------" << endl;
      return 0;
}
