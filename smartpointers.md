# Smart Pointers

```C++
std::shared_ptr<String> p = std::make_shared<String>("Hello");

auto q = p;

p = nullptr;

if(q != nullptr) {
    std::cout << q->length() << *q << endl;
}
```

Use `std::unique_ptr` for *exclusive-ownership resource management*

```C++
template<class T>
class unique_ptr {
    T *p_ = nullptr;

    ~unique_ptr() {
        delete p_;
    }
};
```

`unqiue_ptr` is movable (move only), and its move constructor nulls out the source pointer.

```c++
template<class T>
class std::unique_ptr<T[]> {
    T *p_ = nullptr;

    ~unique_ptr() {
        delete[] p_;
    }
};
```

There are specializations for abtitrary "cleanup"

We can make custom deleters. 

Use `std::shared_ptr` for shared-ownership relationship 

## Simple Reference counting

We keep a jar of token sby the door. When anyone enters they put a token in the jar. When anyone leaves, they take a token with them. When the last person leaves the room, the count is empty so we delete it. 

```c++
class Widget {
    std::atomic<int> usecount_{1}; // for thread safety
    Widget *retain() { ++usecount_; return this; }
    void release() {
        if (--usecount_ == 0) {
            delete this;
        } 
    }
};
```

- Prefer `std::make_unique` and `std::make_shared` to direct use of `new`.

```C++
auto w = std::make_shared<Widget>();
use(W); // Now we have no reason to flag this code. 
// No new, no delete
```


