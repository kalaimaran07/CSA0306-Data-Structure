#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* create(int val) {
    struct Node* new = malloc(sizeof(struct Node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node* root = create(A);
    root->left = creAte(B);
    root->right = creAte(C);

    printf("Inorder: ");   inorder(root);   printf("\n");
    printf("Preorder: ");  preorder(root);  printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    return 0;
}
