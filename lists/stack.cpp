#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T> * next;
    Node(T data, Node<T> * next) : data(data), next(next) { }
};

template <typename T>
struct Stack {
    Node<T> * head;
    int size;

    void push(T);
    T pop();
    T top();
    void print();
    int length();

    Stack() : head(), size(0) { }
    Stack(T data) {
        size = 0;
        push(data);
    }
    Stack(Node<T> set_head) {
        head = set_head;
        size = 1;
    }
};

/**
 * Inserts an element into the top of the stack
 * @param data The element to be added to the stack
 */
template <typename T>
void Stack<T>::push(T data) {
    if (head == nullptr) {
        head = new Node<T>(data, nullptr);
    } else {
        head = new Node<T>(data, head);
    }
    size++;
}

/**
 * Returns the top element of the stack
 * @return the top element in the stack
 */
template <typename T>
T Stack<T>::top() {
    if (size > 0) {
        return head->data;
    }
    return T();
}

/**
 * Remove an element from the stack
 * @return the element that was removed from the stack
 */
template <typename T>
T Stack<T>::pop() {
    if (size > 0) {
        T temp = head->data;
        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node<T> * to_delete = head;
            head = head->next;
            delete to_delete;
        }
        size--;
        return temp;
    }
    return T();
}

/**
 * Prints the stack to the console in order
 * where the leftmost printed value is the top of the stack
 */
template <typename T>
void Stack<T>::print() {
    if (size > 0) {
        Node<T> * current = head;
        std::cout << "Stack: ";
        while (current->next != nullptr) {
            std::cout << current->data << " <- ";
            current = current->next;
        }
        if (current != nullptr) {
            std::cout << current->data << std::endl;
        }
    } else {
        std::cout << "The stack is empty." << std::endl;
    }
}

/**
 * Returns the size of the stack
 * @return the size of the stack
 */
template <typename T>
int Stack<T>::length() {
    return size;
}

int main() {
    // Testing
    Stack<int> stack;
    stack.push(-1);
    stack.push(1);
    stack.push(2);
    stack.print();
    std::cout << "Top: " << stack.top() << std::endl;
    std::cout << "Length: " << stack.length() << std::endl;
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Length: " << stack.length() << std::endl;
}
