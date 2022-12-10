/*
Ashvin Ganesan
Charlie Mcguffey
Friday, December 2nd 2022
Evaluation 8: C++ Advanced Eval
*/
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <new>
#include <memory>
#include "NodePtr.h"

using namespace std;

template <typename T>

class Node {

    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    std::unique_ptr<T> data;
    public:
        Node(T *d) {
            data = d;
            parent = NULL;
            left = NULL;
            right = NULL;
        }
        ~Node() {
            data.release();
            delete parent;
            delete right;
            delete left;
        }
        void setData(T *d) {
            data = d;
        }

        T getData() {
            return &data;
        }

        void setLeft(Node<T> *l) {
            left = l;
        }

        Node<T> *getLeft() {
            return left;
        }

        void setRight(Node<T> *r) {
            right = r;
        }

        Node<T> *getRight() {
            return right;
        }

        void setParent(Node<T> *p) {
            parent = p;
        }

        Node<T>* getParent() {
            return parent;
        }

        bool leftExists() {
            if (left == NULL) {
                return false;
            } else {
                return true;
            }
        }

        bool rightExists() {
            if (right == NULL) {
                return false;
            } else {
                return true;
            }
        }
};


template <typename T>
class BST {
    private:
        Node<T> *root;
        int count;
    public: 
        BST() {
            *root = NULL;
            count = 0;
        }
        BST(Node<T> *n) {
            *root = n;
            count = 1;
        }
        //Part C is worded really confusingly you can't have a constructor that has a return type...
        //It does it automatically, so I just made a constructor that took an array and also a method that took an array
        BST(T arr[], int size) {// CONSTRUCTORS Can't have return types so I just returned 
            BST();
            for(int i = 0; i < size; i++) {
                insert(arr[i]);
            }
        }
        ~BST() {
            del(*root);
            count = 0;
        }
        void del(Node<T> *n) {
            if(*n->getLeft != NULL) {
                del(n->getLeft);
            }
            if(*n->getRight != NULL) {
                del(n->getRight);
            }
            delete(*n);
        }
        void insert(T arr[], int size) {
            for(int i = 0; i < size; i++) {
                insert(arr[i]);
            }
        }
        void insert(T data) {
            Node<T> *node = new Node<T>(data);
            if(root == NULL) {
                root = node;
                return;
            }
            Node<T> *ptr = root;


            while(ptr != NULL) {
                if(ptr->getData() == data) {
                    delete node;
                    return;
                }
                else if(ptr->getData() > data) {
                    if(!ptr->leftExists()) {
                        ptr->setLeft(node);
                        break;
                    }
                    ptr = ptr->getLeft();
                }
                else if(ptr->getData() < data) {
                    if(!ptr->isRight()) {
                        ptr->rightExists(node);
                        break;
                    }
                    ptr = ptr->getRight();
                }
            }
            count++;
        }



        void Delete(T data) {
            if(root == NULL) {
                return;
            }

            Node<T> * ptr = root;
            Node<T> *parent = NULL;

            while(ptr) {
                if(ptr->getData() == data) {
                    break;
                }
                else if(ptr->getData() > data) {
                    parent = ptr;
                    ptr = ptr->getLeft();
                }
                else if(ptr->getData() < data) {
                    parent = ptr;
                    ptr = ptr->getRight();
                }
            }
            if(ptr == NULL) {
                return;
            }

            while(true) {
                if(!ptr->leftExists() && !ptr->rightExists()) {
                    if(parent == NULL) {
                        root = NULL;    
                    }
                    else {
                        if(parent->getLeft() == ptr)
                            parent->setLeft(NULL);
                        else
                            parent->setRight(NULL);
                    }

                    delete ptr;
                    break;
                }
                else if(ptr->leftExists() && !ptr->rightExists()) {
                    if(parent == NULL) {
                        root = ptr->getLeft();
                        delete ptr;
                        break;
                    }
                    else {
                        if(parent->getLeft() == ptr) {
                            parent->setLeft(ptr->getLeft());
                            delete ptr;
                            break;
                        }
                        else if(parent->getRight() == ptr) {
                            parent->setRight(ptr->getLeft());
                            delete ptr;
                            break;
                        }
                    }
                }
                else if(!ptr->leftExists() && ptr->rightExists()) {
                    if(parent == NULL) {
                        root = ptr->getRight();
                        delete ptr;
                        break;
                    }
                else {
                    if(parent->getLeft() == ptr) {
                        parent->setLeft(ptr->getRight());
                        delete ptr;
                        break;
                    }
                    else if(parent->getRight() == ptr) {
                        parent->setRight(ptr->getRight());
                        delete ptr;
                        break;
                    }
                }
            }
                
            Node<T> * next = ptr->getRight();
            Node<T> *nextParent = ptr;

            while(next->leftExists()) {
                nextParent = next;
                next = next->getLeft();
            }

            T data = ptr->getData();
            ptr->setData(next->getData());
            next->setData(data);

            ptr = next;
            parent = nextParent;
        }
    }
         
        

};

