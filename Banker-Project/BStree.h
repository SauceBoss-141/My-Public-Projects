#ifndef BStree_H_
#define BStree_H_
#include <iostream>
#include <string>
using namespace std;
template<class T>
class BStree{
    
    public:
    struct Node{
        T *data = nullptr;
        Node *right = nullptr;
        Node * left = nullptr;

    };
    BStree();
    ~BStree();
    bool Insert(const T *obj);
    void InsertTraverse(Node*&temp,const T *obj );
    bool Remove(T* target);
    int getSize();
    void DeleteBST();
     Node* FindMin(Node* node);
    bool RemoveNode(Node*& node, T *target);
    bool Retrieve(const int id, T *&p_t);//Make Sure a pointer, to change actuall account
    template<typename U>
    friend ostream& operator<<(ostream& stream, const BStree<U>& list);
    BStree operator=(const BStree& rhs);
    void DeleteBST(Node* node);
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const BStree<U>& tree);

    private:
    int size;
    Node *head_; 
    void PrintInOrder(std::ostream& os, typename BStree<T>::Node* node) const;
};
template <class T>
BStree<T>::BStree()
{
    size = 0;
    head_ = nullptr;
}
template <class T>
BStree<T>::~BStree()
{
    DeleteBST();
}
template <class T>
bool BStree<T>::Insert(const T *obj)
{   
    if(head_ == nullptr){
        head_ = new Node();
        head_->data= new T(*obj);
        size++;
        return true;
    }
    else{
        Node * temp =head_;
        InsertTraverse(temp, obj);
        return true;
    }
    return false;
}
template <class T>
void BStree<T>::InsertTraverse(Node *&temp, const T *obj)
{   
    if(*obj > (*temp->data)){
        if(temp->right != nullptr){
            temp = temp->right;
            InsertTraverse(temp, obj);
        }else{
            Node * insert_me = new Node();
            insert_me->data = new T(*obj);
            temp->right = insert_me;
            size++;
        }
    }else if( *obj<= *(temp->data)){
        if(temp->left != nullptr){
            temp = temp->left;
            InsertTraverse(temp, obj);
        }else{
            Node * insert_me = new Node();
            insert_me->data = new T(*obj);
            temp->left = insert_me;
            size++;
        }
    }
}
template<class T>
bool BStree<T>::Remove(T *target) {
    return RemoveNode(head_, target);
}
template<class T>
bool BStree<T>::RemoveNode(Node*& node, T *target) {
    if (node == nullptr) return false; // Node not found
    if (*target < *node->data) {
        return RemoveNode(node->left, target);
    } else if (*target > *node->data) {
        return RemoveNode(node->right, target);
    } else {
        // Node to be deleted
        if (node->left == nullptr && node->right == nullptr) {
            delete node->data;
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp->data;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp->data;
            delete temp;
        } else {
            Node* temp = FindMin(node->right);
            *node->data = *temp->data;
            RemoveNode(node->right, temp->data);
        }
        size--;
        return true;
    }
    return false;
}
template <class T>
int BStree<T>::getSize()
{
    return size;
}
template <class T>
typename BStree<T>::Node* BStree<T>::FindMin(Node *node)
{    if(node == nullptr){
    return nullptr;
}
     while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
template <class T>
bool BStree<T>::Retrieve(const int id, T *&p_t)
{
    Node* temp = head_;
    while (temp != nullptr) {
        if (id == (*temp->data).getAccountNum()) {
            p_t = temp->data;
            return true;
        } else if (id < (*temp->data).getAccountNum()) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}
template<class T>
void BStree<T>::DeleteBST() {
    DeleteBST(head_);
    head_ = nullptr;
    size = 0;
}
template<class T>
void BStree<T>::DeleteBST(Node* node) {
    if (node == nullptr) return;
    DeleteBST(node->left);
    DeleteBST(node->right);
    delete node->data;
    delete node;
}
template <class U>
std::ostream& operator<<(std::ostream& os, const BStree<U>& tree) {
    tree.PrintInOrder(os, tree.head_);
    return os;
}
template <class T>
void BStree<T>::PrintInOrder(std::ostream& os, typename BStree<T>::Node* node) const {
    if (node == nullptr) return;

    // Traverse the left subtree
    PrintInOrder(os, node->left);
    os<<"\n";
    // Print the current node's data
    os << "\n"<< *(node->data) << " ";

    // Traverse the right subtree
    PrintInOrder(os, node->right);
}
#endif