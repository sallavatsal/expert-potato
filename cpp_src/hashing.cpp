#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

void init() { std::cout << "\n*************** Out ***************\n\n"; }

void end() { std::cout << "\n\n***********************************\n\n"; }

void hashTestUnorderedSet(std::unordered_set<int> &s, int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    s.insert(arr[i]);
  }
  std::cout << "Size = " << s.size() << std::endl;

  std::cout << "Set = ";
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
  }
  s.clear();
  std::cout << "Cleared" << std::endl;
  std::cout << "Size after clearing = " << s.size() << std::endl;
  std::cout << "Set after clearing = ";
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
  }
  int item = 15;
  std::cout << "\nAdding a new element in the array = " << item << std::endl;
  s.insert(item);
  auto it = s.find(item);

  // Find function
  if (it == s.end()) {
    std::cout << "Not found!" << std::endl;
  } else {
    std::cout << "Found " << *it << " using find" << std::endl;
  }

  // Count function
  if (!s.count(item)) {
    std::cout << "Not found!" << std::endl;
  } else {
    std::cout << "Found using count!" << std::endl;
  }

  // Adding again the set elements
  for (int i = 0; i < size; ++i) {
    s.insert(arr[i]);
  }
  std::cout << "Size = " << s.size() << std::endl;
  std::cout << "Set = ";
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
  }

  // Erase function
  s.erase(item);
  std::cout << "\nErasing " << item << std::endl;
  std::cout << "Set = ";
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\nErasing all elements using ranges" << std::endl;
  std::cout << "Set = ";
  s.erase(s.begin(), s.end());
  std::cout << "Size after erasing range = " << s.size() << std::endl;
}

void hashMapTestUnorderedSet(std::unordered_map<std::string, int> &m) {
  const char arr[][10] = {"gfg", "ide", "courses"};
  size_t size = sizeof(arr) / sizeof(arr[0]);
  std::string key = "vatsal";
  int val = 3;
  std::cout << "Key - value pairusing member access op: " << key << ", " << val;
  m[std::string(key)] = val; // [] brackets are member access operators

  for (auto i = 0; i < size; ++i) {
    m[std::string(arr[i])] = i;
  }
  std::cout << std::endl << std::endl;
  // Iterator based loop
  for (auto it = m.begin(); it != m.end(); it++) {
    std::cout << "Key - value pairs: " << it->first << ", " << it->second;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // Range based loop
  for (auto it : m) {
    std::cout << "Key - value pairs: " << it.first << ", " << it.second;
    std::cout << std::endl;
  }
  std::cout << std::endl;

  auto it = m.find({"vatsal"});
  int i = m.count({"vatsal"});
  if (i) {
    std::cout << "Found key using count at value = " << it->second;
    std::cout << std::endl;
    std::cout << std::endl;

  } else {
    std::cout << "Did not find using count key using !";
    std::cout << std::endl;
    std::cout << std::endl;
  }

  std::cout << "Size of the map before erase is " << m.size() << std::endl;
  std::cout << "Erasing using erase. Key = " << it->first << std::endl;
  m.erase(it->first);
  std::cout << "Size of the map after erase is " << m.size() << std::endl;
  m.erase(m.begin(), m.end());
  std::cout << "Size of the map after erase all is " << m.size() << std::endl;
}

void selfPacedDsa() {
  std::unordered_set<int> s;
  std::unordered_map<std::string, int> m;

  std::cout << "Hashing!" << std::endl;

  int arr[] = {10, 15, 20, 25};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  // hashTestUnorderedSet(s, arr, size);
  hashMapTestUnorderedSet(m);
}

int main() {
  init();
  selfPacedDsa();
  end();

  return 0;
}