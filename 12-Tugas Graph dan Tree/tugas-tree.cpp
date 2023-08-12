#include <iostream> //Muhamad Bayu Fadayan - 065121100
using namespace std;

/*Inilah Tipe data pada setiap node.
Artinya Tiap-Tiap Node akan mempunya ketiganya, ada datanya, pointer kiri, dan pointer kanan*/
struct Tree {
    int data;
    Tree *left;
    Tree *right;
};
/*Pendeklarasian pointer dengan tipe data struct tree.
artinya pointer pointer ini hanya bisa menyimpan alamat yang memiliki tipe data yang sama pada struct tree. Dan pointer ini pun hanya bisa menunjuk kepada bagian yang ada didalam struct tree*/
Tree *baru, *root;

/*Sebuah fungsi dengan tipe data Tree yang berguna untuk membuat node baru.
Kenapa pakai tipe data tree? karena yang akan di return juga bertipe data yang sama.
Kenapa nama fungsinya pakai bintang(seperti pointer)? karena sesuatu yang akan direturn juga merupakan pointer.
parameter formalnya diisi dengan nilai data yang akan kita masukan.
Kenapa pakai fungsi return? Agar fungsinya dapat di inisialisasi kan atau disama dengankan dengan pointer root(pointer dgn tipedata Tree) difungsi main nanti*/
Tree *NewTree(int data) {
    baru = new Tree;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

/*Memakai void karena tujuannya untuk menampilkan juga.
Parameter formal diisi dengan pointer root
Terdapat fungsi rekrusif yang akan dijelaskan pada bagian illustrasi*/
void PreOrder(Tree *root){
    if (root == NULL)
    {
        return;
    }else
    {
        cout << "[" << root->data << "] >> ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

//kurang lebih sama seperti penjelasan fungsi preorder yang akan dijelaskan pada bagian illustrasi
void PostOrder(Tree *root){
    if (root == NULL)
    {
        return;
    }else
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << "[" << root->data << "] >> ";
    }
}

//kurang lebih sama seperti penjelasan fungsi preorder yang akan dijelaskan pada bagian illustrasi
void InOrder(Tree *root){
    if (root == NULL)
    {
        return;
    }else
    {
        InOrder(root->left);
        cout << "[" << root->data << "] >> ";
        InOrder(root->right);
    }
}

//program utama   
int main(){

    /*Pengisian tree, yang mana yang dimulai dari akar atau node yang tidak punya parent sampai selanjutnya*/
    root = NewTree(30);
    root->left = NewTree(26);
    root->right = NewTree(22);
    root->left->left = NewTree(21);
    root->left->right = NewTree(20);
    root->right->left = NewTree(19);
    root->right->right = NewTree(13);
    root->left->left->left = NewTree(12);
    root->left->left->right = NewTree(11);
    root->left->right->left = NewTree(9);
    root->left->right->right = NewTree(8);
    root->right->right->left = NewTree(7);
    root->left->left->left->left = NewTree(4);
    root->left->right->right->left = NewTree(2);
    root->left->right->right->right = NewTree(1);

    //menampilkan program dengan metode penelusuran preorder
    cout << "PreOrder : " << endl;
    PreOrder(root);
    cout << endl << endl;

    //menampilkan program dengan metode penelusuran postorder
    cout << "PostOrder : " << endl;
    PostOrder(root);
    cout << endl << endl;

    //menampilkan program dengan metode penelusuran inorder
    cout << "InOrder : " << endl;
    InOrder(root);
    cout << endl << endl;

    return 0;
    //MUHAMAD BAYU FADAYAN - 065121100
    //#maap klo salah :)
}
