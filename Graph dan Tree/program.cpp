// #include <iostream>
// #include <conio.h>
// using namespace std;

// struct Node
// {
//     int data;

//     Node *right, *left;
// };
// Node *tree, *baru;

// void AddNode(Node **root, int data){
//     if ((*root) == NULL)
//     {
//         baru = new Node;
//         baru->data = data;
//         baru->left = NULL;
//         baru->right = NULL;
//         (*root) = baru;
//         (*root)->left = NULL;
//         (*root)->right = NULL;

//     }else if (data < (*root)->data)
//     {
//         AddNode(&(*root)->left, data);

//     }else if (data > (*root)->data)
//     {
//         AddNode(&(*root)->right, data);
//     }
    
// }

// void preOrder(Node *root)
// {
//     if(root != NULL){
//         cout << root->data << endl;
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// int main (){

//     Node *tree = NULL;
//     AddNode(&tree, 42);
//     AddNode(&tree, 54);
//     AddNode(&tree, 12);
//     AddNode(&tree, 89);
//     AddNode(&tree, 43);
//     AddNode(&tree, 92);
//     AddNode(&tree, 58);
    
//     preOrder(tree);

//     getch();
//     return 0;
// }
#include <iostream>

struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

// Preorder traversal
void preorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  std::cout << node->value << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  std::cout << node->value << "->";
}

// Inorder traversal
void inorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  inorderTraversal(node->left);
  std::cout << node->value << "->";
  inorderTraversal(node->right);
}

// Referensi: https://stackoverflow.com/a/51730733/5561144
void print(const std::string &prefix, const Node *node, bool isLeft)
{
  if (node != NULL)
  {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");

    std::cout << node->value << std::endl;

    auto ikon = isLeft ? "│   " : "    ";
    print(prefix + ikon, node->left, true);
    print(prefix + ikon, node->right, false);
  }
}
// Referensi: https://www.programiz.com/dsa/tree-traversal
int main()
{
  Node *root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  root->left->right->left = new Node(2);
  root->left->right->right = new Node(3);

  print("", root, false);

  std::cout << "Inorder traversal: ";
  inorderTraversal(root);

  std::cout << "\nPreorder traversal: ";
  preorderTraversal(root);

  std::cout << "\nPostorder traversal: ";
  postorderTraversal(root);
}