// Priority Queue implementation in C++

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Function to swap position of two elements
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree after adding a new element
void heapify(vector<int> &hT) {
  int i = hT.size()-1;

  int parent = floor((i-1)/2);
  while (hT[i]>hT[parent]) {
    swap(&hT[i],&hT[parent]);
    if (parent == 0) {
      break;
    }
    i = parent;
    parent = floor((i-1)/2);
  }
  
}

void heapifyDown(vector<int> &hT) {
  int i = 0;
  while (hT.size()-1>=(i*2)+1) {
    int left = (i*2)+1;
    int right = left+1;
    if (hT[i]<=hT[left]) {
      swap(&hT[i],&hT[left]);
      i = left;
    } else if (hT.size()-1>=right && hT[i]<=hT[right]) {
      swap(&hT[i],&hT[right]);
      i = right;
    } else {
      break;
    }
  }

}
// Function to insert an element into the tree
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    heapify(hT);
  }
}

// Print the tree
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int peek(vector<int> &hT) {
  return hT[0];
}
bool remove(vector<int> &hT) {
  if (hT.size()<1) {
    return false;
  }
  int value = hT[0];
  hT[0] = hT[hT.size()-1];
  hT.pop_back();
  heapifyDown(hT);
  return true;
}

bool empty(vector<int> &hT) {
  return (hT.size()<1);
  }


// Driver code
int main() {
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);
  insert(heapTree, 12);
  insert(heapTree, 7);
  insert(heapTree, 10);
  insert(heapTree, 14);
  insert(heapTree, 1);
  
  cout << "Max-Heap array: ";
  printArray(heapTree);

  while (!empty(heapTree)) {
    cout << "Next: " << peek(heapTree) << endl;
    remove(heapTree);
  }

}
