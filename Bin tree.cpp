#include <iostream>
#include <string>
#define random(min,max) (min + rand() % (max - min + 1))

using namespace std;

template <typename T>
class MyBinaryTree {
private:
    class Node {
    public:
        T elem;
        Node* right;
        Node* left;
        Node(const T& value) :elem(value), left(nullptr), right(nullptr) {};
    };
    Node* root;
public:
    MyBinaryTree() : root(nullptr) {};
    ~MyBinaryTree();
    
    void insert(const T& elem) {
        this->root = insertRecursive(root, elem);
    }

    void show() {
        
        showRecursive(this->root);
    }

    void clear() {
        clearRecursive(root);
       
    }

private:

    void clearRecursive(Node* node) {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
        root = nullptr;Q
    }


    void showRecursive(Node* node) {
        if (node != nullptr) {
            showRecursive(node->left);
            cout << node->value << " ";
            showRecursive(node - right);
        }
    }









    Node* insertRecursive(Node* node, const T& elem) {
        if (node == nullptr) {
            return new Node(elem);
        }
        if (elem < node->elem) {
            node->left = insertRecursive(node->left, elem);
        }
        else if (elem > node->elem) {
            node->right = insertRecursive(node->right, elem);
        }
        return node;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
}