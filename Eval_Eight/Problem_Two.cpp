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
#include <iostream>
#include <stack>
#include <new>
#include <memory>

using namespace std;

template <typename T>
class Node {
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    T *data;

    public:
        Node(T *d) {
            data = d;
            parent = NULL;
            left = NULL;
            right = NULL;
        }
        void setData(T *d) {
            data = d;
        }

        T getData() {
            return data;
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

        Node<T> *getParent() {}
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

