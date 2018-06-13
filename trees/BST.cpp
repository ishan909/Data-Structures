// Unbalanced Binary Search Tree to store keys and values
#include <iostream>
#include <queue>

template <typename K, typename V>
struct TreeNode {
    K key;
    V value;
    TreeNode<K, V> * left;
    TreeNode<K, V> * right;
    TreeNode(K key, V val, TreeNode<K, V> * left, TreeNode<K, V> * right)
        : key(key), value(val), left(left), right(right) { }
};

template <typename K, typename V>
struct BST {
    TreeNode<K, V> * root;

    bool insert(K, V);
    V find(K);
    V remove(K);
    K tree_root();
    void print_preorder();
    void print_level_order();

    BST() : root(nullptr) { }
    BST(K key, V value) {
        insert(key, value);
    }
    BST(TreeNode<K, V> set_head) {
        root = &set_head;
    }
};

/**
 * Inserts a key and value to the BST
 * @param key - the key to be added to the Tree
 * @param value - the value to be added to the Tree
 */
template<typename K, typename V>
bool insert_helper(K key, V value, TreeNode<K, V> *& current) {
    if (current != nullptr) {
        if (key < current->key) {
            return insert_helper(key, value, current->left);
        } else if (key > current->key) {
            return insert_helper(key, value, current->right);
        } else {
            return false;
        }
    } else {
        current = new TreeNode<K, V>(key, value, nullptr, nullptr);
        return true;
    }
}
template<typename K, typename V>
bool BST<K, V>::insert(K key, V value) {
    return insert_helper(key, value, root);
}

/**
 * Return the value of the data at the desired key
 * @param key - the key we are searching for
 * @return the data stored at the key
 */
template<typename K, typename V>
bool find_helper(K key, TreeNode<K, V> *& current) {
    if (current != nullptr) {
        if (key < current->key) {
            return find_helper(key, current->left);
        } else if (key > current->key) {
            return find_helper(key, current->right);
        } else {
            return current->value;
        }
    } else {
        return V();
    }
}
template<typename K, typename V>
V BST<K, V>::find(K key) {
    return find_helper(key, root);
}

/**
 * Removes the key and value from the BST at the passed in key
 * @param key - the key for the node that is being removed
 * @return the value at the removed key
 */
template<typename K, typename V>
V remove_helper(K key, TreeNode<K, V> *& current) {
    if (current != nullptr) {
        if (key < current->key) {
            return remove_helper(key, current->left);
        } else if (key > current->key) {
            return remove_helper(key, current->right);
        } else {
            if (current->left == nullptr && current->right == nullptr) {
                // no child delete
                V val = current->value;
                delete current;
                current = nullptr;
                return val;
            } else if (current->left != nullptr && current->right != nullptr) {
                // two child delete
                V val = current->value;
                TreeNode<K, V> * IOP = current->left;
                while (IOP->right != nullptr) {
                    IOP = IOP->right;
                }
                current->key = IOP->key;
                current->value = IOP->value;
                remove_helper(IOP->key, current->left);
                return val;
            } else {
                // one child delete
                V val = current->value;
                TreeNode<K, V> * temp = current;
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current = current->right;
                }
                delete temp;
                temp = nullptr;
                return val;
            }
        }
    } else {
        return V();
    }
}
template<typename K, typename V>
V BST<K, V>::remove(K key) {
    return remove_helper(key, root);
}

/**
 * Returns the key at the root of the tree
 * @return the key at the root of the tree
 */
template <typename K, typename V>
K BST<K, V>::tree_root() {
    if (root != nullptr) {
        return root->key;
    } else {
        return K();
    }
}

/**
 * Prints the BST to the console using a preorder traversal
 */
template <typename K, typename V>
void print_helper(TreeNode<K, V> * current) {
    if (current->left != nullptr) {
        print_helper(current->left);
    }
    std::cout << current->key << ", " << current->value << " || ";
    if (current->right != nullptr) {
        print_helper(current->right);
    }
}
template <typename K, typename V>
void BST<K, V>::print_preorder() {
    if (root != nullptr) {
        std::cout << "|| ";
        print_helper(root);
        std::cout << std::endl;
    } else {
        std::cout << "The tree is empty." << std::endl;
    }
}

/**
 * Prints the BST to the console using a level order traversal
 */
template <typename K, typename V>
void BST<K, V>::print_level_order() {
    if (root != nullptr) {
        std::queue<TreeNode<K, V> *> queue;
        queue.push(root);
        std::cout << "|| ";
        while (!queue.empty()) {
            TreeNode<K, V> * current = queue.front();
            queue.pop();
            std::cout << current->key << ", " << current->value << " || ";
            if (current->left != nullptr) {
                queue.push(current->left);
            }
            if (current->right != nullptr) {
                queue.push(current->right);
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "The tree is empty." << std::endl;
    }
}

int main() {
    // Testing
    BST<int, int> bst;
    bst.insert(5, 5);
    bst.insert(2, 2);
    bst.insert(7, 7);
    bst.insert(4, 4);
    bst.insert(3, 3);
    bst.insert(8, 8);
    bst.insert(6, 6);
    bst.insert(9, 9);
    std::cout << "preorder:    ";
    bst.print_preorder();
    std::cout << "level order: ";
    bst.print_level_order();
    std::cout << "root: " << bst.tree_root() << std::endl;
    bst.remove(5);
    std::cout << "preorder:    ";
    bst.print_preorder();
    std::cout << "level order: ";
    bst.print_level_order();
    std::cout << "root: " << bst.tree_root() << std::endl;
    bst.remove(2);
    bst.remove(7);
    bst.remove(5);
    bst.remove(4);
    bst.remove(3);
    bst.remove(8);
    bst.remove(6);
    bst.remove(9);
    std::cout << "preorder:    ";
    bst.print_preorder();
    std::cout << "level order: ";
    bst.print_level_order();
    std::cout << "root: " << bst.tree_root() << std::endl;
}
