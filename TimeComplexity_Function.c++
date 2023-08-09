#include <iostream>
using namespace std;

// O (1)
void printHelloWorld() { cout << "Hello, World!" << endl; }

// O(n)
void printHelloWorld1() {
  int i, n = 8;
  for (i = 1; i <= n; i++) {
    cout << "Hello World !!! \n";
  }
}

// O(log n)
void printHelloWorld2() {
  int i, n = 8;
  for (i = 1; i <= n; i = i * 2) {
    cout << "Hello World!!! \n";
  }
}
// Quadratictime—O(n2)
void printHelloWorld3() {
  int n = 8;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << "Hello World!!! \n";
    }
  }
}

// Linear time — O(n + m)
void printHelloWorld4() {
  int n = 8;
  int m = 4;

  for (int i = 1; i <= n; i++) {
    cout << "Hello World!!! \n";
  }

  for (int j = 1; j <= m; j++) {
    cout << "Hello Again!!! \n";
  }
}
int main() {
  cout << " O(1) \n";
  printHelloWorld();
  cout << "O(n) \n";
  printHelloWorld1();
  cout << " O(log n) \n";
  printHelloWorld2();
  cout << "Quadratictime—O(n2) \n";
  printHelloWorld3();
  cout << "Linear time — O(n + m) \n";
  printHelloWorld4();
  return 0;
}
