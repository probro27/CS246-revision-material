# RAII

- Resource Acquisition is initialization

A "resource" is anything that requires manual management.

## Classes that manage resources

Some of these resources are "unique" and some are "duplicable" (heap allocations).
- there is some explicit application by the program to free the resource.

Naive implementation of the vector

```C++
class NaiveVector {
    int *ptr_;
    size_t size_;
public:
    NaiveVector(): ptr_{nullptr}, size{0} {} // initializes ptr with a resource
    void push_back(int newvalue) {
        int *newptr = new int[size_ + 1]; // replaces the resource managed by ptr_
        std::copy(ptr_, ptr_ + size_, newptr);
        delete[] ptr_;
        ptr_ = newptr;
        ptr_[size_++] = newvalue;
    }
};


int main() {
    NaiveVector vec; // here ptr_ is initialized with 0 elements

    vec.push_back(1); // ptr_ is initialized with 1 elements

    vec.push_back(2); // ptr_ is initialized with 2 elements

    // when we are done with the object it doesn't delete
    // add destructor
}

```

```c++
~NaiveVector() {
    delete[] ptr_; // deleting the pointer
}
```

No longer leaks memory when the vector is  destroyed.

We can't make copy of the vector because default copy constructor called. 
Only the pointers are copied. So when deleted *double free* is the issue. 

Introduce the copy constructor

```C++
NaiveVector(const NaiveVector &other) {
    ptr = new int[other.size_];
    size_ = other.size_;
    std::copy(other.ptr_, other.ptr_ + size_, ptr_); // copy the pointer into the array
}
```

Need to also make a copy assignment operator

```C++
NaiveVector &operator=(const NaiveVector &other) {
    NaiveVector copy = other; // copy constructor
    copy.swap(*this); // copy and swap idiom
    return *this;
```

## Why Copy and Swap?

- Could do memory management but we need to be careful about self assignment
- Trouble for templted or recursive data structure

### Benefits
- We make a complete copy of rhs before the first modification of *this
- Any aliasing between rhs and *this cannot trip us up. 

## RAII and Exception Safety

- The slogan is about initialization, but meaning is really about **cleanup**.


