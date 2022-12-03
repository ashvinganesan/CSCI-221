/*
Ashvin Ganesan
Charlie Mcguffey
Friday, December 2nd 2022
Evaluation 7: C++ Intro Eval
*/
#include <cmath>
#include <iostream>
#include <string>
#include<list>
#include <iterator>
#include <vector>
#include "compare.h"
using namespace Mynamespace;
using namespace std;
 
class SortedList {
    private:
        list<string> arr;
        bool SortByString;
        
    public:

        SortedList() : arr() {
            SortByString = true;
        }
        SortedList(list<string> l, bool sortByS) {
            arr = l;
            SortByString = sortByS;
            if(!sortByS) {
                using namespace Mynamespace;
            }
        }
        SortedList(list<string> l) {
            arr = l;
            SortByString = true;
        }
        SortedList(bool sortByS) : arr() { 
            SortByString = sortByS;
            if(!sortByS) {
                using namespace Mynamespace;
            }
        }
        void sortList() {
            arr.sort();
        }
        void add(string s) {
            if(s.compare(arr.back()) < 0) {
                arr.push_back(s);
                return;
            }
            list<string>::iterator it = arr.begin();
            while(s.compare(*it) < 0) {
                it++;
            }
            arr.insert(it,s);
            return;
        }
        void clearList() {
            arr.clear();
        }
        void remove(string s) {
            list<string>::iterator it;
            for (it=arr.begin(); it!=arr.end(); ++it) {
                if(s.compare(*it) == 0) {
                    arr.erase(it);
                }
            }
            while(!(s.compare(*it) == 0)) {
                it++;
            }
            arr.insert(it,s);
            return;
        }
        int length() {
            return arr.size();
        }
        string * returnArr() {
            string* retArr= new string[length()];
            list<string>::iterator it;
            int counter = 0;
            for (it=arr.begin(); it!=arr.end(); ++it) {
                retArr[counter] = *it;
                counter++;
            }
            return retArr;
        }
        string ithelement(int i) {
            list<string>::iterator it;
            int counter = 0;
            for (it=arr.begin(); it!=arr.end(); ++it) {
                if(i == counter) {
                    return *it;
                }
            }
            return *arr.begin();
        }
        void SwapToStringSorted() {
            SortByString = true;
            using namespace std;
            arr.sort();
        }
        void SwapToLenSorted() {
            SortByString = false;
            using namespace Mynamespace;
            arr.sort();
        }
        bool SortedByString() {
            return SortByString;
        }
        bool sortedByLen() {
            return !SortByString;
        }


};

// SortedList copy(SortedList l) {
//     SortedList c(l)
// };

int main(){

}