

#ifndef MATRIX_LIST_H
#define MATRIX_LIST_H

#endif //MATRIX_LIST_H

#include <iostream>
template <typename T>
class Queue {
     std:: vector<T> data;
     int last; // индекс последнего элемента
public:

    explicit Queue(int n) {
        if(n<=0) {
            throw std::out_of_range("Invalid lenght");
        }
        data =  std::vector<T> (n);
        last = -1;
    }

    T pop() {
        if (last < 0) {
            throw std::out_of_range("Empty queue");
        }
        T tmp = data[0];
        for (int i = 1; i < last; i++) {
            data[i-1] = data [i];
        }

        //delete data[last];
        last--;
        return tmp;
    }

    void push(T value) {
        if (last == (data.size()-1)) {
            throw std::out_of_range("Queue overflow");
        }
        last++;
        data[last] = value;
    }

    T top() {
        if (last < 0) {
            throw std::out_of_range("Empty stack");
        }
        return data[last];
    }

    int size() {
        return last+1;
    }

    bool empty() {
       if(last<0) {
           return true;
       }
        return false;
    };
    ///for tests
    bool operator== (const Queue& other) const {
        if (last != other.last) {
            return false;
        }
        for (int i = 0; i<last; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!= (const Queue& other) const {
        return !(this==other);
    }
};