#include <cstring>
#include <iostream>
#include <list>

using namespace std;

class Hash {
  int BUCKET;
  list<const char *> *table; // Change data type to store strings
  int numCollisions;

public:
  Hash(int V);
  ~Hash();
  void insertItem(const char *key); // Change parameter type to accept strings
  void deleteItem(const char *key); // Change parameter type to accept strings
  int hashFunction(int x) { return (x % BUCKET); }
  void displayHash();
  int getNumCollisions() { return numCollisions; }
};

Hash::Hash(int b) {
  this->BUCKET = b;
  numCollisions = 0;
  table = new list<const char *>[b]; // Allocate memory for string lists
}

Hash::~Hash() { delete[] table; }

void Hash::insertItem(const char *key) {
  int index = hashFunction(strlen(key)); // Calculate index using key length

  if (!table[index].empty()) {
    numCollisions++;
  }

  table[index].push_back(key);
}

void Hash::deleteItem(const char *key) {
  int index = hashFunction(strlen(key));

  if (!table[index].empty()) {
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
      if (strcmp(*it, key) == 0) { // Compare strings using strcmp function
        table[index].erase(it);
        break;
      }
    }
  }
}

void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i << " "; // Add space after index
    for (auto x : table[i])
      cout << "-->" << x;
    cout << endl;
  }
}

int main() {
  const char *fruit[5] = {"Apple", "Banana", "Cherry", "Strawberry", "Papaya"};
  Hash h(10);

  // Insert strings
  for (int i = 0; i < 5; i++) {
    h.insertItem(fruit[i]);
  }

  h.displayHash();

  // Delete string
  h.deleteItem("Cherry");

  cout << "Updated Hash Table:" << endl;
  h.displayHash();

  cout << "Collision Hash Table:" << endl;
  h.insertItem("Orange");
  h.insertItem("Kiwi");
  h.displayHash();

  return 0;
}
