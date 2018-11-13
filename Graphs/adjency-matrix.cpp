#include <iostream>
using namespace std;

class Graph {
private:
      bool** adjMatrix;
      int numVertices;
public:
      Graph(int num) {
            this->numVertices = num;
            adjMatrix = new bool*[numVertices];

            for (int i = 0; i < numVertices; i++) {
                  adjMatrix[i] = new bool[numVertices];
                  for (int j = 0; j < numVertices; j++){
                        adjMatrix[i][j] = false;
                  }
            }
      }

      void addEdge(int i, int j) {
            adjMatrix[i][j] = true;
            adjMatrix[j][i] = true;
      }

      void removeEdge(int i, int j) {
            adjMatrix[i][j] = false;
            adjMatrix[j][i] = false;
      }

      bool isEdge(int i, int j) {
            return adjMatrix[i][j];
      }

      void print() {
            for (int i = 0; i < numVertices; i++) {
                  cout << i << " : ";
                  for (int j = 0; j < numVertices; j++) {
                        cout << adjMatrix[i][j] << " ";
                  }
                  cout << endl;
            }
      }

      ~Graph() {
            for (int i = 0; i < numVertices; i++){
                  delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
      }
};


int main(int argc, char const *argv[]) {
      int a = 0, b = 0, count = 0, choice = 0;
      cout << "Enter the number of vertices in the graph : ";
      cin >> count;

      Graph gr(count);

      cout << "Now specify all the edges in the graph : " << endl;
      do {
            cout << "a: "; cin >> a;
            cout << "b: "; cin >> b;

            if(a <= count && b <= count)
                  gr.addEdge(a, b);
            else
                  cout << "Check your input" << endl;

            cout << "-------" << "        enter 1 to continue..." << endl;
            cin >> choice;
            cout << "-------" << endl;
      } while(choice == 1);

      cout << "The adjency matrix thus formed >>" << endl;
      gr.print();

      return 0;
}
