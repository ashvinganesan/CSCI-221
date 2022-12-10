#ifndef _NODEPTR_H_
#define _NODEPTR_H_
template <typename T> class NodePtr {
    public:
        NodePtr(T *ptr) : ptr_(ptr) { } // constructor
        ~NodePtr() { // destructor
            if (ptr_ != nullptr) {
                delete ptr_;
                ptr_ = nullptr;
            }
        }
        T &operator*() { return *ptr_; } // * operator
        T *operator->() { return ptr_; } // -> operator
    private:
        T *ptr_; // the pointer itself
};
#endif // _TOYPTR_H_