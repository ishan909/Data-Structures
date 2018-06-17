// Vector basted implementation of a min heap

#include <iostream>
#include <vector>

template <typename T>
class Heap {
public:
    Heap();
    T peek();
    void push(T);
    T pop();
    size_t size();
    void print();

private:
    std::vector<T> _elems;
    size_t left_child_index(size_t);
    size_t right_child_index(size_t);
    size_t parent_index(size_t);
    size_t root_index();
    bool has_child(size_t);
    void heapify_up(size_t);
    void heapify_down(size_t);
};

/**
 * Heap constructor
 */
template <typename T>
Heap<T>::Heap() {
    // garbage/default value at index 0 of the vector
    _elems.push_back(T());
}

/**
 * Returns the peak of the heap which is the smallest value
 * @return min value in the structure
 */
template <typename T>
T Heap<T>::peek() {
    if (size() > 0) {
        return _elems[1];
    } else {
        return T();
    }
}

/**
 * Add a new value to the heap
 * @param data - the value you want to add to the heap
 */
template <typename T>
void Heap<T>::push(T data) {
    _elems.push_back(data);
    heapify_up(_elems.size() - 1);
}

/**
 * Removes the min value from the heap
 * @return the min value in the heap
 */
template <typename T>
T Heap<T>::pop() {
    // swap the index with the last element
    if (size() > 0) {
        T temp = _elems[root_index()];
        _elems[root_index()] = _elems[size()];
        _elems[size()] = temp;
        _elems.pop_back();
        heapify_down(1);
        return temp;
    } else {
        return T();
    }
}

/**
 * Returns the size of the heap
 * @return the size of the heap
 */
template <typename T>
size_t Heap<T>::size() {
    return _elems.size() - 1;
}

/**
 * Returns the index of the left child of the passed in index
 * @param the index whose child index we are computing
 * @return the index of the left child or -1 if it does not exist
 */
template <typename T>
size_t Heap<T>::left_child_index(size_t index) {
    if (index * 2 <= size()) {
        return index * 2;
    }
    return -1;
}

/**
 * Returns the index of the right child of the passed in index
 * @param the index whose child index we are computing
 * @return the index of the right child or -1 if it does not exist
 */
template <typename T>
size_t Heap<T>::right_child_index(size_t index) {
    if (index * 2 + 1 <= size()) {
        return index * 2 + 1;
    }
    return -1;
}

/**
 * Returns the index of the parent of the passed in index
 * @param the index whose parent index we are computing
 * @return the index of the parent or -1 if it does not exist
 */
template <typename T>
size_t Heap<T>::parent_index(size_t index) {
    if (index != 1) {
        return index / 2;
    }
    return -1;
}

/**
 * Returns the index of the root in the vector implementation
 * @return the index of the root
 */
template <typename T>
size_t Heap<T>::root_index() {
    return 1;
}

/**
 * Returns if an element has a child in the vector
 * @param the index that we are checking if it has children
 * @return if the passed in index has a child
 */
template <typename T>
bool Heap<T>::has_child(size_t index) {
    return index * 2 <= size();
}

/**
 * Helper method for push()
 * Updates values in the vector implementation of the heap to be in min heap order
 * @parem index - the index that we may swap up
 */
template <typename T>
void Heap<T>::heapify_up(size_t index) {
    while (parent_index(index) != -1 && _elems[parent_index(index)] > _elems[index]) {
        T temp = _elems[parent_index(index)];
        _elems[parent_index(index)] = _elems[index];
        _elems[index] = temp;
        index = parent_index(index);
    }
}

/**
 * Helper method for pop()
 * Updates values in the vector implementation of the heap to be in min heap order
 * @parem index - the index that we may swap down
 */
template <typename T>
void Heap<T>::heapify_down(size_t index) {
    // heapify down at index
    while (has_child(index)) {
        if (right_child_index(index) != -1) {
            // compare index val with both children
            if (_elems[left_child_index(index)] < _elems[right_child_index(index)]) {
                if (_elems[left_child_index(index)] < _elems[index]) {
                    // swap left child with index
                    std::swap(_elems[index], _elems[left_child_index(index)]);
                    index = left_child_index(index);
                } else {
                    break;
                }
            } else {
                if (_elems[right_child_index(index)] < _elems[index]) {
                    // swap right child with index
                    std::swap(_elems[index], _elems[right_child_index(index)]);
                    index = right_child_index(index);
                } else {
                    break;
                }
            }
        } else {
            // compare index val with left child only
            if (_elems[left_child_index(index)] < _elems[index]) {
                // swap left child with index
                std::swap(_elems[index], _elems[left_child_index(index)]);
            }
            break;
        }
    }
}

/**
 * Prints the heap in order
 * (Primarily for testing purposes)
 */
template <typename T>
void Heap<T>::print() {
    if (size() == 0){
        std::cout << "This heap is empty." << std::endl;
        return;
    } else {
        for (int i = 1; i < _elems.size() - 1; i++) {
            std::cout << _elems[i] << " | ";
        }
        std::cout << _elems[size()] << std::endl;
    }
}

int main() {
    // Testing
    Heap<int> h;
    h.push(5);
    h.push(3);
    h.push(8);
    h.push(4);
    h.push(1);
    h.push(2);
    h.push(7);
    h.push(6);
    h.print();
    h.pop();
    h.print();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.print();
    h.pop();
    h.pop();
    h.print();
    h.pop();
    h.print();
}
