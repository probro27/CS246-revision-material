#include <iostream>
#include <memory>
#include <utility>

using namespace std;

struct IntArray {
    int size;
    int capacity;
    shared_ptr<int*> contents;
};

IntArray readIntArray() {
    int element;
    IntArray a;
    while(true) {
        if(cin >> element) {
            if(a.capacity == 0){
                a.contents = make_shared<int*>(new int[5]);
                *(a.contents)[0] = element;
                a.capacity = 5;
                a.size = 1;
            } else if (a.capacity == a.size + 1){
                a.capacity *= 2;
                shared_ptr<int*> temp = make_unique<int*>(new int[a.capacity]);
                for(int i = 0; i < a.size; i++) {
                    *temp[i] = *(a.contents)[i];
                }
                *temp[a.size] = element;
                std::swap(a.contents, temp); // temp should pop off the stack so a.contents should remain without memory leak
            } else {
                *(a.contents)[a.size] = element;
                a.size += 1;
            }
        } else {
            cin.ignore();
            cin.clear();
            break;
        }
    }
    return a;
}

void addToIntArray(IntArray& a) {
    int element;
    while(true) {
        if(cin >> element) {
            if(a.capacity == 0){
                a.contents = make_shared<int*>(new int[5]);
                *(a.contents)[0] = element;
                a.capacity = 5;
                a.size = 1;
            } else if (a.capacity == a.size + 1){
                a.capacity *= 2;
                shared_ptr<int*> temp = make_unique<int*>(new int[a.capacity]);
                for(int i = 0; i < a.size; i++) {
                    *temp[i] = *(a.contents)[i];
                }
                *temp[a.size] = element;
                std::swap(a.contents, temp); // temp should pop off the stack so a.contents should remain without memory leak
            } else {
                *(a.contents)[a.size] = element;
                a.size += 1;
            }
        } else {
            cin.ignore();
            cin.clear();
            break;
        }
    } 
}

void printIntArray(const IntArray& seq) {
    for(int i = 0; i < seq.size; i++) {
        cout << *(seq.contents)[i] << " ";
    }
    cout << endl;
}

int main()
{ // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;

  while (!done)
  {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl; // Valid commands:  ra, rb, rc, rd,
                                //                  +a, +b, +c, +d,
                                //                  pa, pb, pc, pd,
                                //                  q
    cin >> c;                   // Reads r, +, p, or q
    if (cin.eof())
      break;
    switch (c)
    {
    case 'r':
      cin >> which; // Reads a, b, c, or d
    //   delete[] a[which - 'a'].contents;
      a[which - 'a'].contents = nullptr;
      a[which - 'a'] = readIntArray();
      break;
    case '+':
      cin >> which; // Reads a, b, c, or d
      addToIntArray(a[which - 'a']);
      break;
    case 'p':
      cin >> which; // Reads a, b, c, or d
      printIntArray(a[which - 'a']);
      cout << "Capacity: " << a[which - 'a'].capacity << endl;
      break;
    case 'q':
      done = true;
    }
  }

//   for (int i = 0; i < 4; ++i)
//     delete[] a[i].contents;
}
