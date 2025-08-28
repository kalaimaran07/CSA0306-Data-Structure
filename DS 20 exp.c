#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;
int height(Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }
Node* newNode(int key) {
    Node* n = malloc(sizeof(Node));
    n->key = key; n->left = n->right = NULL; n->height = 1;
    return n;
}
Node* rotateRight(Node *y) {
    Node *x = y->left; y->left = x->right; x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node* rotateLeft(Node *x) {
    Node *y = x->right; x->right = y->left; y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(Node *n) { return n ? height(n->left) - height(n->right) : 0; }
Node* insert(Node* n, int key) {
    if (!n) return newNode(key);
    if (key < n->key) n->left = insert(n->left, key);
    else if (key > n->key) n->right = insert(n->right, key);
    else return n;
    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);
    if (b > 1 && key < n->left->key) return rotateRight(n);
    if (b < -1 && key > n->right->key) return rotateLeft(n);
    if (b > 1 && key > n->left->key) { n->left = rotateLeft(n->left); return rotateRight(n); }
    if (b < -1 && key < n->right->key) { n->right = rotateRight(n->right); return rotateLeft(n); }
    return n;
}
Node* minValue(Node* n) {
    while (n->left) n = n->left;
    return n;
}
Node* delete(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = delete(root->left, key);
    else if (key > root->key) root->right = delete(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;
            free(root); return temp;
        }
        Node* temp = minValue(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int b = getBalance(root);

    if (b > 1 && getBalance(root->left) >= 0) return rotateRight(root);
    if (b > 1 && getBalance(root->left) < 0) { root->left = rotateLeft(root->left); return rotateRight(root); }
    if (b < -1 && getBalance(root->right) <= 0) return rotateLeft(root);
    if (b < -1 && getBalance(root->right) > 0) { root->right = rotateRight(root->right); return rotateLeft(root); }
    return root;
}
int search(Node* root, int key) {
    if (!root) return 0;
    if (key == root->key) return 1;
    return key < root->key ? search(root->left, key) : search(root->right);
}
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = delete(root, 30);
    printf("Search 70: %s\n", search(root, 70) ? "Found" : "Not Found");
    return 0;
}
