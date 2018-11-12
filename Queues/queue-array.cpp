#include <iostream>
using namespace std;

struct node {
      int front, rear;
      int size;
      unsigned capacity;
      int *array;
};

struct node *createQueue(unsigned capacity);
int isFull(struct node *ptr);
int isEmpty(struct node *ptr);
void enQueue(struct node *ptr, int data);
void deQueue(struct node *ptr);
int front(struct node *ptr);
int rear(struct node *ptr);
void displayQueue(struct node *ptr);

int main(int argc, char const *argv[]) {
      // This program implements operations on Queue using linked lists
      struct node *queue;
      int size, value, choice;

      cout << "Enter the number of elements you want to enter into the queue..." << endl;
      cin >> size;
      queue = createQueue(size);

      cout << "Enter 1 to fill " << size << " elements in the queue : " << endl;
      cin >> choice;

      while (choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Enter the elements..." << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              enQueue(queue, value);
                        }
                        break;
                  case 2:
                        cout << "Enter the element..." << endl;
                        cin >> value;
                        enQueue(queue, value);
                        break;
                  case 3:
                        cout << "Removing an element from the queue..." << endl;
                        deQueue(queue);
                        break;
                  case 4:
                        cout << "Current last element in the queue is: " << rear(queue) << endl;
                        break;
                  case 5:
                        cout << "Current first element in the queue is: " << front(queue) << endl;
                        break;
                  case 6:
                        cout << "------------------------" << endl;
                        displayQueue(queue);
                        cout << "------------------------" << endl;
                        break;
                  default:
                        cout << "Invalid choice..." << endl;
                        break;
            }
            cout << "Enter a selection to continue..." << endl;
            cout << "Enter 2 to insert a new element in the queue..." << endl;
            cout << "Enter 3 to remove an element in the queue..."  << endl;
            cout << "Enter 4 to view the last element in the queue..." << endl;
            cout << "Enter 5 to view the first element in the queue..." << endl;
            cout << "Enter 6 to display the queue..." << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << endl;
      return 0;
}

struct node *createQueue(unsigned capacity) {
      struct node *temp = new struct node;

      temp->capacity = capacity;
      temp->front = temp->size = 0;
      temp->rear = (capacity - 1);
      temp->array = (int*)malloc(temp->capacity * sizeof(int));

      return temp;
}

int isFull(struct node *ptr) {
      return (ptr->size == ptr->capacity);
}

int isEmpty(struct node *ptr) {
      return (ptr->size == 0);
}

void enQueue(struct node *ptr, int data) {
      if(isFull(ptr)) {
            return;
      }

      ptr->rear = ((ptr->rear + 1) % ptr->capacity);
      ptr->array[ptr->rear] = data;
      ptr->size += 1;
}

void deQueue(struct node *ptr) {
      if(isEmpty(ptr)) {
            return;
      }

      int temp = ptr->array[ptr->front];
      ptr->front = ((ptr->front + 1) % ptr->capacity);
      ptr->size -= 1;
}

int front(struct node *ptr) {
      if(isEmpty(ptr)) {
            return 0;
      }

      return ptr->array[ptr->front];
}

int rear(struct node *ptr) {
      if(isEmpty(ptr)) {
            return 0;
      }

      return ptr->array[ptr->rear];
}

void displayQueue(struct node *ptr) {
      for(int i = 0; i < ptr->size; i++) {
            cout << ptr->array[i] << " ";
      }
      cout << endl;
}
