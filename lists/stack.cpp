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

    void push(T);
    T pop();
    T top();
    void print();

    Stack() : head() { }
    Stack(T data) {
        push(data);
    }
    Stack(Node<T> * set_head) {
        head = set_head;
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
}

/**
 * Returns the top element of the stack
 * @return the top element in the stack
 */
template <typename T>
T Stack<T>::top() {
    if (head != nullptr) {
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
    if (head != nullptr) {
        T temp = head->data;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node<T> * to_delete = head;
            head = head->next;
            delete to_delete;
            to_delete = nullptr;
        }
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
    if (head != nullptr) {
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

int main() {
    // Testing
    Stack<int> stack;
    stack.push(-1);
    stack.push(1);
    stack.push(2);
    stack.print();
    std::cout << "Top: " << stack.top() << std::endl;
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Removed: " << stack.pop() << std::endl;
    stack.print();
}
