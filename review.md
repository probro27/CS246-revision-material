# Final Review Session

## Static Members

**Why to use them?**
- if we need to keep the state or data across all objects of the class rather than the individual objects themselves.

- can be used to keep track of the number of objects created.

- the static member is not allocated as part of object instantiation, there ot should not be freed as part of object destruction.

- They don't have a `this` parameter therefore, it can only call other static functions and only access static fields.

## Object Slicing

The derived class subject's extra attributes are sliced off to generate the base class object.

All parts specific to the derived class objects are gone.

- sliced off means that data isn't deleted, it's just that it's never created because Base copy constructor is called. 

- To tackle the slicing problem, we can use a pointer instead (or a reference)

## Exceptions

- we use *exceptions* in C++ to control the behaviour of the program when errors arise. 

- if an exception is raised/throw the program will terminate if there is no matching handler. 

```C++
try {
    throw 42;
} catch (...) { // "..." will catch any type of error
    cerr << "Caught Something" << endl;
}
```

- if the `catch` block code runs to the completion without raising another exception, control continues after the `catch` block.

**Good Practice**

- Throw by value, catch by reference (to prevent object slicing)
- Catch blocks need to be ordered from most specific to least specific. 

```C++
try {
    throw Derived{};
} catch (Base &b) { // error caught here

} catch (Derived &d) { // should put this first

}
```

Three levels of exception safety- 
- *Basic Guarantee*: If the exception is thrown, the data will be in a valid state and all class invariants are maintained. 
Invariant means that suppose an integer should always be +ve then if it becomes -ve, we lost the invariant. 

- *Strong Guarantee*: If an exception is thrown, the data will appear as if nothing happened. The copy and swap idiom in the assignment operator provides the strong guarantee. 

- *No-throw Guarantee*: An exception is never throw then the function always suceed. Example is `std::swap`

## Visitor Design Pattern

- Just need to overload the visit method to handle different parameters (one for each of the different objects being visited)


## Inheritance

```C++

struct A {
    A() {
        cout << "A Ctor" << endl;
    }
    ~A() { // should have virtual destructor
        cout << "A dtor" << endl; 
    }
};


struct B : public A{
    B() {
        cout << "B Ctor" << endl;
    }
    ~B() {
        cout << "B dtor" << endl; 
    }
};

int main() {
    B b;
    A* a = new B;
    delete a; 
}

```
Output:
```bash
    A Ctor
    B Ctor
    A Ctor
    B Ctor
    A Dtor
    B Dtor
    A Dtor
```

```C++

class Base {
private:
    virtual void f() {
        cout << "Base" << endl;
    }
};

class Derived: public Base {
public:
    void f() override {
        cout << "Derived" << endl;
    }
};


int main() {
    Base *b = new Derived();
    b->f(); // gives error because the function is private in Base class
}

```

## PIMPL

- hides the implementation in the headers and includes an interface file that compiles instantly

- hides the implementation away from client, reduces recompilation required, can be used for easy strong exception guarantee if used correctly. 

- It gives actual logical implementations for methods in a separate "implementation" class, and give the main class a pointer to an instance of the implementation.

```C++

// PIMPL with unqiue pointers

unqiue_ptr<Impl> impl;

impl{std::make_unique<Impl>(*(other.impl))} // *other.impl same as other.impl.get()

```

Testing:

```C++


int main() {
    unique_ptr<int> i {make_unique<int>(5)};
    cout << i.get() << endl; // gives memory address
    cout << *i << endl; // gives the actual value
}


```

## Bridge Pattern

- Inheritance in Impl (Impl mein inheritance)
