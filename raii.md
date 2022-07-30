# RAII and Constructors revised

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

## Defaulted Special Member functions
```C++
class Book {
    // ...
    public:
        Book(const Book&) = default;
        Book &operator=(const Book &) = default;
        ~Book() = default;
};
```

# The Rule of Zero

- If your class does not directly manage any resource but merely uses library components such as vectors and strings, then write no special member functions.
    - Let the compiler implicitly generate a defaulted constructor
    - Let the compiler generate the copy constructor
    - Let the compiler generate the copy assignment operator
    - (But your own swap might improve performance)
- Known as **Rule of Zero**.

Two kinds of well-designed C++ classes-

- **Business-logic classes** that do not manually manage any resources, and follow the Rule of Zero
    - They delegate the job of resource management to data memberes of types such as `std::string`

- **Resource-management classes** (small, single-purpose) that follow the Rule of Three
    - Acquire the resource in each constructor; free the resource in the destructor; copy and swap in the assignment operator.

### Rule of Five

- If you need to write any one of the constructor, move, copy, delete, you write all of them.
- Includes -
	- Constructor
	- Copy Constructor
	- Move Constructor
	- Copy Assignment Operator
	- Move Assignment Operator

**No Longer NaiveVector**

```c++
class Vec {
    Vec(const Vec &rhs) {
        ptr_ = new int[rhs.size_];
        size_ = rhs.size_;
        std::copy(rhs.ptr_, rhs.ptr_ + size, ptr_);
    }

    Vec(Vec &&rhs) noexcept {
        ptr_ = std::exchange(rhs.ptr_, nullptr);
        size_ = std::exchange(rhs.size_, 0);
    }

    ~Vec() {
        delete[] ptr;
    }

    Vec &operator=(Vec copy) noexcept {
        copy.swap(*this);
        return *this;
    }

    Vec &swap(Vec &rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(size_, rhs.size_);
    }

    friend void swap(Vec &a, Vec &b) noexcept {
        a.swap(b);
    }
};
```

## Closer to the Rule-Of-Zero

```c++

class Vec {
    std::unique_ptr<int[]> uptr_;
    int size_;

    Vec(const Vec& rhs) {
        uptr_ = std::make_unique<int[]>(rhs.size_);
        size_ = rhs.size_;
        std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_); // how does this even work??
    }

    Vec(Vec &&rhs) noexcept = default;

    ~Vec() = default;

    // rest are the same
};
```

## True Rule-Of-Zero

```c++
class Vec {
    std::vector<int> vec_;

    Vec(const Vec &rhs) = default;
    Vec(Vec &&rhs) noexcept = default;
    Vec &operator=(const Vec &rhs) = default;
    Vec &operator=(Vec &&rhs) = default;
    ~Vec() = default;

    void swap(Vec &rhs) noexcept {
        vec_.swap(rhs.swap_);
    }

    friend void swap(Vec &a, Vec &b) noexcept {
        a.swap(b);
    }
}
```

`shared_ptr` manages the reference count

- Destructor decrements the reference count (frees if it is 0)
- Copy constructor increments the reference count
- Move Constructor transfers ownership of the resource (leaves the reference count same)
- Copy assignment operator Decrements the old reference count, increments the new count
- Move assignment operator Decrements the old reference count, then disengages the right hand side.
