#include <iostream>
#include <list>
using namespace std;

class Hash {
  int BUCKET;
  list<int> *table;
  int numCollisions; // Number of collisions in the hash table

public:
  Hash(int V);
  ~Hash();
  void insertItem(int key);
  void deleteItem(int key);
  int hashFunction(int x) { return (x % BUCKET); }
  void displayHash();
  int getNumCollisions() { return numCollisions; }
};

Hash::Hash(int b) {
  this->BUCKET = b;
  numCollisions = 0;
  table = new list<int>[b];
}

Hash::~Hash() {
  delete[] table;
}

void Hash::insertItem(int key) {
  int index = hashFunction(key);

  if (!table[index].empty()) {
    numCollisions++;
  }

  table[index].push_back(key);
}

void Hash::deleteItem(int key) {
  int index = hashFunction(key);
  if (!table[index].empty()) {
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
      if (*it == key) {
        table[index].erase(it);
        break;
      }
    }
  }
}
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << "-->" << x;
    cout << endl;
  }
}

int main() {
  cout << "Display Hash Table:" << endl;
  Hash h(10);
  // create array to use with insertItem Function
  string valuesToInsert[] = {"1", "2"};
  int n = sizeof(valuesToInsert) / sizeof(valuesToInsert[0]);
  for (int i = 0; i < n; i++) {
    h.insertItem(stoi(valuesToInsert[i]));
  }
  h.displayHash();
  h.deleteItem(17);

  cout << "Updated Hash Table:" << endl;
  h.displayHash();

  cout << "Collision Hash Table:" << endl;
  h.insertItem(11);
  h.insertItem(23);
  h.displayHash();

  return 0;
}
