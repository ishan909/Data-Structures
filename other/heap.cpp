#include <iostream>
#include <vector>

template <typename T>
struct heap {
    vector<T> min_heap;

    heap();
    T peek();
    void insert(T);
    T remove();
    int size();

    size_t left_child_index(size_t);
    size_t right_child_index(size_t);
    size_t parent_index(size_t);
    size_t root_index();
    bool has_child(size_t);
    void heapify_up(size_t);
    void heapify_down(size_t);
}

template <typename T>
heap<T>::heap() {
    // garbage value at index 0 of the vector
    min_heap.push_back(T());
}

template <typename T>
T heap<T>::peek() {
    if (size() > 0) {
        return min_heap[1];
    } else {
        return T();
    }
}

template <typename T>
void heap<T>::insert(T data) {
    min_heap.push_back(data);
    heapify_up(min_heap.size() - 1);
}

template <typename T>
T heap<T>::remove() {
    // swap the index with the last element
    T temp = min_heap[root_index()];
    min_heap[root_index()] = min_heap[size()];
    min_heap[size()] = temp;
    min_heap.pop_back();
    heapify_down(1);
}

template <typename T>
size_t heap<T>::size() {
    return min_heap.size() - 1;
}

template <typename T>
size_t heap<T>::left_child_index(size_t index) {
    if (index * 2 <= size()) {
        return index * 2;
    }
    return -1;
}

template <typename T>
size_t heap<T>::right_child_index(size_t index) {
    if (index * 2 + 1 <= size()) {
        return index * 2 + 1;
    }
    return -1;
}

template <typename T>
size_t heap<T>::parent_index(size_t index) {
    if (index != 1) {
        return index / 2;
    }
    return -1;
}

template <typename T>
size_t heat<T>::root_index() {
    return 1;
}

template <typename T>
bool heap<T>::has_child(size_t index) {
    return index * 2 <= size();
}

template <typename T>
void heap<T>::heapify_up(size_t index) {
    while (parent_index(index) != -1 && min_heap[parent_index(index)] < min_heap[index]) {
        // need to swap
        T temp = min_heap[parent_index(index)];
        min_heap[parent_index(index)] = min_heap[index];
        min_heap[index] = temp;
        index = parent_index(index);
    }
}

template <typename T>
void heap<T>::heapify_down(size_t index) {
    // heapify down at index
    while (has_child(index)) {
        if (right_child_index(index) != -1) {
            // compare index val with both children
            T left_val = min_heap[left_child_index(index)];
            T right_val = min_heap[right_child_index(index)];
            if (left_val < right_val) {
                if (left_val < min_heap[index]) {
                    // swap left child with indexs
                    min_heap[index] = left_val;
                    min_heap[left_child_index(index)] = min_heap[index];
                    index = left_child_index(index);
                } else {
                    break;
                }
            } else {
                if (right_val < min_heap[index]) {
                    // swap right child with index
                    min_heap[index] = right_val;
                    min_heap[right_child_index(index)] = min_heap[index];
                    index = right_child_index(index);
                } else {
                    break;
                }
            }
        } else {
            // compare index val with left child only
            if (left_val < min_heap[index]) {
                // swap left child with indexs
                min_heap[index] = left_val;
                min_heap[left_child_index(index)] = min_heap[index];
            }
            break;
        }
    }
}

int main() {
    // Testing
    // TODO
}
