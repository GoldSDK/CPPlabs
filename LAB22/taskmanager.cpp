#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(istringstream &iss) {
    string token;
    iss >> token;
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        int op = (token == "+") ? -1 : (token == "-") ? -2 : (token == "*") ? -3 : -4;
        Node* node = new Node(op);
        node->left = buildTree(iss);
        node->right = buildTree(iss);
        return node;
    }
    return new Node(stoi(token));
}

int evaluate(Node* root) {
    if (!root->left && !root->right) return root->value;
    int a = evaluate(root->left);
    int b = evaluate(root->right);
    return (root->value == -1) ? a + b :
           (root->value == -2) ? a - b :
           (root->value == -3) ? a * b : a / b;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

Node* transformTree(Node* root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;
    root->left = transformTree(root->left);
    root->right = transformTree(root->right);
    if (root->value == -1 || root->value == -2) {
        int val = evaluate(root);
        freeTree(root->left);
        freeTree(root->right);
        root->value = val;
        root->left = root->right = nullptr;
    }
    return root;
}

void CalcTree5() {
    ifstream fin("filename");
    string input;
    getline(fin, input);
    istringstream iss(input);
    Node* root = buildTree(iss);
    root = transformTree(root);
    cout << root << endl;
    freeTree(root);
}

void CalcTree23() {
	
}
