#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void PrintTree(Node* root) {
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << "\n";
    }
}

void TreeToList(Node* root, Node*& head, Node*& prev) {
    if (root == nullptr)
        return;

    TreeToList(root->left, head, prev);

    if (prev == nullptr) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    TreeToList(root->right, head, prev);
}

void PrintList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << "\n";
}

void TreeFun1() {
    int arr[] = {10, 6, 14, 4, 8, 12, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "исходное дерево (извините что не сделал ветки я очень устал):" << endl;
    PrintTree(root);

    Node* head = nullptr;
    Node* prev = nullptr;
    TreeToList(root, head, prev);

    cout << "\n2связный список:" << endl;
    PrintList(head);
}

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) { }
    ~BinaryTree() {
        clear(root);
    }

    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node* current = root;
        while (true) {
            if (val < current->data) {
                if (!current->left) {
                    current->left = new Node(val);
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = new Node(val);
                    break;
                }
                current = current->right;
            }
        }
    }

    void clear(Node* node) {
        if (!node) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    int height(Node* node) {
        if (!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return max(lh, rh) + 1;
    }

    void printVertical() {
        if (!root) return;
        int h = height(root);
        int maxNodes = pow(2, h) - 1; 
        int maxWidth = maxNodes * 4;

        queue<Node*> q;
        q.push(root);

        int level = 0;
        while (!q.empty() && level < h) {
            int nodesInLevel = q.size();
            int spaceBetween = maxWidth / (nodesInLevel + 1);

            cout << string(spaceBetween, ' ');
            vector<Node*> nextLevel;
            for (int i = 0; i < nodesInLevel; i++) {
                Node* cur = q.front();
                q.pop();

                if (cur) {
                    cout << setw(3) << cur->data;
                    nextLevel.push_back(cur->left);
                    nextLevel.push_back(cur->right);
                } else {
                    cout << "   ";
                    nextLevel.push_back(nullptr);
                    nextLevel.push_back(nullptr);
                }
                cout << string(spaceBetween, ' ');
            }
            cout << "\n";
            bool allNull = true;
            for (Node* n : nextLevel) {
                if (n != nullptr) {
                    allNull = false;
                    break;
                }
            }
            if (allNull)
                break;
            
            for (Node* n : nextLevel) {
                q.push(n);
            }
            level++;
            maxWidth /= 2;
        }
    }

    class Iterator {
    public:
        Iterator(Node* root) {
            pushLeft(root);
        }

        int operator*() const {
            return nodeStack.top()->data;
        }

        Iterator& operator++() {
            Node* curr = nodeStack.top();
            nodeStack.pop();

            if (curr->right) {
                pushLeft(curr->right);
            }
            return *this;
        }

        bool operator==(const Iterator& other) const {
            if (nodeStack.empty() && other.nodeStack.empty()) {
                return true;
            }
            if (!nodeStack.empty() && !other.nodeStack.empty()) {
                return nodeStack.top() == other.nodeStack.top();
            }
            return false;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        stack<Node*> nodeStack;

        void pushLeft(Node* node) {
            while (node) {
                nodeStack.push(node);
                node = node->left;
            }
        }
    };

    Iterator begin() {
        return Iterator(root);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

void TreeFun3() {
    BinaryTree tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "дерево:" << endl;
    tree.printVertical();
    cout << "\nлево корень право че-то там:" << endl;
    for(auto it = tree.begin(); it != tree.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void TreeFun13() {
    
}