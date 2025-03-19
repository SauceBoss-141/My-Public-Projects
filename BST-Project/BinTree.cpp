#include "BinTree.h"
// ------------------------------------------ BinTree.cpp ---------------------------------------------
// Jacob Brown CSS343 
// 01/21/2025
// 01/28/25
// ---------------------------------------------------------------------------------------------------
// Purpose - Creates a binary search tree 
// ---------------------------------------------------------------------------------------------------
// Capable of Inserting and removing elements. Printing in multiple ways
// Can trasnfer elements to an arry, can trasnfer elements from an array
// Has a height and size
// Able to reterieve a specfici element 
// Can copy itself to another tree and can delete itself
// ---------------------------------------------------------------------------------------------------

// ------------------------------------BinTree Constructor---------------------------------------------
// Description: Creates a defualt "empty" Binary Search Tree with head set to null and size = 0
// ---------------------------------------------------------------------------------------------------
BinTree::BinTree()
{ 
    head_ = nullptr;
    size_=0;

}

// ------------------------------------BinTree Copy Constructor----------------------------------------
// Description: Creates a copy of another tree named 'other' 
// ---------------------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree &other)
{

    *this = other;
}

// ------------------------------------BinTree De-constructor------------------------------------------
// Description: Deletes all dynamically allocated memory, sets size to 0 and head to nullptr
// ---------------------------------------------------------------------------------------------------
BinTree::~BinTree()
{
    DeleteBST();
}

// ------------------------------------BinTree Insert -------------------------------------------------
// Description: Inserts a NodeData object into the tree and increments size by 1
// ---------------------------------------------------------------------------------------------------
bool BinTree::insert(const NodeData *obj)
{   
    if(head_ == nullptr){
        head_ = new Node();
        head_->data= new NodeData(*obj);
        size_++;
        return true;
    }else{
        Node *temp = head_;
        
        while(((*obj< *temp->data)? temp->left: temp->right) != nullptr){
            if(*obj==*temp->data){
                return false;
                }
            temp = (*obj< *temp->data)? temp->left: temp->right;  
        }
        if(*obj<*temp->data){
            Node *inserter = new Node();
            inserter->data= new NodeData(*obj);
            temp->left = inserter;
            size_++;
            return true;
        }else if (*obj==*temp->data){
                return false;
        }else{
             Node* inserter = new Node();
            inserter->data = new NodeData(*obj);
            temp->right = inserter;
            size_++;
            return true;
            }
        }
           
    return false;
}

// ------------------------------------BinTree remove -------------------------------------------------
// Description: removes a target NodeData
// ---------------------------------------------------------------------------------------------------
bool BinTree::remove(NodeData *target)
{
    return removeNode(head_, target);;
}

// ------------------------------------BinTree removeNode ---------------------------------------------
// Description: Helper Method to help remove a target node.
// Recursivley traverse a BST to find a target Node. Takes two Nodes, the start for the traversla and
// The target. Returns a boolean upon completion. 
// ---------------------------------------------------------------------------------------------------
bool BinTree::removeNode(Node *&node, NodeData *target)
{
    if (node == nullptr) return false; // Node not found
    if (*target < *node->data) {
        return removeNode(node->left, target);
    } else if (*target > *node->data) {
        return removeNode(node->right, target);
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
            Node* temp = findMin(node->right);
            *node->data = *temp->data;
            removeNode(node->right, temp->data);
        }
        size_--;
        return true;
    }
    return false;
}

// ------------------------------------BinTree isEmpty ------------------------------------------------
// Description: Returns a boolean value wether or not the tree is empty or contains a value
// ---------------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{   
    if(head_ == nullptr){
        return true;
    }else{
        return false;
    }
}

// ------------------------------------BinTree makeEmpty ----------------------------------------------
// Description: Deletes all nodes and data isnide of the tree
// ---------------------------------------------------------------------------------------------------
void BinTree::makeEmpty()
{
    DeleteBST();
}

// ------------------------------------BinTree getSize ------------------------------------------------
// Description: Returns the size (number of nodes) inside of the tree
// ---------------------------------------------------------------------------------------------------
int BinTree::getSize()
{
    return size_;
}

// ------------------------------------BinTree getHeight ----------------------------------------------
// Description: Returns an Integer of the height of a Node contaning the passed in NodeData
// ---------------------------------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &start) 
{   
    Node* temp = findNode(head_, start);
    return temp ? heightHelper(temp) :0;
}

// ------------------------------------BinTree heightHelper -------------------------------------------
// Description: This method helps the getHeight method, by recursivley traversing the tree counting 
// the height fro the strat node
// Reutrn Integer 
// ---------------------------------------------------------------------------------------------------
int BinTree::heightHelper( Node* current)
{
    if (current == nullptr) {
        return 0; // Base case: node not found
    }
    return 1+ max(heightHelper(current->left), heightHelper(current->right));
}

// ------------------------------------BinTree DeleteBst ----------------------------------------------
// Description: Deletes all Nodes and there data
// Sets size to 0 and head_ to nullptr
// ---------------------------------------------------------------------------------------------------
void BinTree::DeleteBST()
{   if(head_==nullptr)return;
    DeleteBST(head_);
    head_= nullptr;
    size_ = 0;
}

// ------------------------------------BinTree DeleteBST ----------------------------------------------
// Description: Recursivley deletes the BST. Sets head_ to nullptr
// ---------------------------------------------------------------------------------------------------
void BinTree::DeleteBST(Node *node)
{
    if (node == nullptr)
    {
        bool why = true; 
        return;
    }
    DeleteBST(node->left);
    DeleteBST(node->right);
    delete node->data;
    delete node;
}

// ------------------------------------BinTree fidnMin ----------------------------------------------
// Description: finds the most minimum left node. 
// This is used for help in rthe rmeove method
// Reutrns Node pointer
// -------------------------------------------------------------------------------------------------
BinTree::Node *BinTree::findMin(Node *node)
{
    if(node == nullptr){
        return nullptr;
    }
     while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// ------------------------------------BinTree findNode -----------------------------------------------
// Description: recurisvly traverses the BST until the target node is found or not found
// if found, will return a pointer to that node
// if not found, nullptr will be returned
// ---------------------------------------------------------------------------------------------------
BinTree::Node *BinTree::findNode(Node *current, const NodeData& target)
{   
    if(current == nullptr)return nullptr;
    
    if(*current->data == target)return current;
    return target< *current->data? findNode(current->left, target): findNode(current->right, target);
    
    return nullptr;
}

// ------------------------------------BinTree retrieve -----------------------------------------------
// Description: Looks for a target NodeData object and will assign its value to a passed in empty NodeData
// If NodeData is not found it will be set to nullptr
// ---------------------------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData &target, NodeData *&nodeData)
{
    Node* temp = head_;
    while (temp != nullptr) {
        if (target == (*temp->data)) {
            nodeData = temp->data;
            return true;
        } else if (target < (*temp->data)) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    nodeData = nullptr;//if not found
    return false;
}

// ------------------------------------BinTree = operator ---------------------------------------------
// Description: Creates a deep copy of the rhs BST and returns a new BST
// ---------------------------------------------------------------------------------------------------
BinTree &BinTree::operator=(const BinTree &rhs)
{   
    if(*this == rhs){
        return *this;
    }
    DeleteBST();
    if(rhs.head_!= nullptr){
        head_ = assignmentHelper(rhs.head_);
    }
    return *this;
}

// ------------------------------------BinTree Assignment help ----------------------------------------
// Description: Assists = operator in copying each value over
// ---------------------------------------------------------------------------------------------------
BinTree::Node* BinTree::assignmentHelper( Node *other)
{   
    if(other==nullptr){
        return nullptr;
    }else{
        Node* newNode = new Node();
        newNode->data = new NodeData(*other->data);
        
        newNode->left = assignmentHelper(other->left);
        newNode->right = assignmentHelper(other->right);
        return newNode;
    }
}

// ------------------------------------BinTree == Operator --------------------------------------------
// Description: Compares two BSTs and determines if they are equal
// ---------------------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &other)
{
    return equalsHelper(head_, other.head_);
}

// ------------------------------------BinTree equalsHelper -------------------------------------------
// Description: Recursivly traverse the tree comparing each value. Returns true or false 
// ---------------------------------------------------------------------------------------------------
bool BinTree::equalsHelper(const Node *current, const Node *other)
{   
    if(current == nullptr && other == nullptr){
        return true;
    }
    if(current == nullptr || other == nullptr){
        return false;
    }
    
    return (*current->data == *other->data)&&(equalsHelper(current->left, other->left))&&(equalsHelper(current->right, other->right));
}

// ------------------------------------BinTree != Operator --------------------------------------------
// Description: Compares two BSTs and determines if they are not equal
// ---------------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &other)
{
    return !(*this==other);
}

// ------------------------------------BinTree to an Array --------------------------------------------
// Description: Takes BST values and puts them into sorted order into a given NodeData pointer array 
// Turns all values in the BST to nullptr once done
// ---------------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData * arr[])
{   
    if (head_ == nullptr) {
            return;
        }

    int index = 0;
    bstreeToArrayHelper(arr, head_, index);
    DeleteBST();
    
}

// ---------------------------------BinTree to an Array Helper ----------------------------------------
// Description: Helper method, recursivley does an inorder traversal of the BST
// Inorder to assign values from BST to the Array in sorted order
// ---------------------------------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(NodeData *arr[], Node *node, int & index)
{
    if(node == nullptr)return;

    bstreeToArrayHelper(arr, node->left, index);
    arr[index++]= new NodeData(*node->data);
    bstreeToArrayHelper(arr, node->right, index);
    
}

// ------------------------------------Array to BinTree ----------------------------------------------
// Description: Takes an array of NodeData pointers and adds them to a BST
// Sorted Arrays willl yeild the best and most balanced tree 
// --------------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData *arr[])
{
     if(arr==nullptr){
        return;
    }
    DeleteBST();
    int size = 0;
    while(arr[size]!=nullptr){
        size++;
    }
    head_ = arrayToBSTreeHelper(arr,0,size-1);

    for (int i = 0; i < size; i++) {
        delete(arr[i]);
        arr[i]= nullptr;
    }
    
}

// ------------------------------------Array to BinTree Helper ----------------------------------------
// Description: This methods helps take NodeData pointers and put them into a BST 
// Taking the array needed to pull from, a start and an ending index
// Returns a Node object
// ---------------------------------------------------------------------------------------------------
BinTree::Node *BinTree::arrayToBSTreeHelper(NodeData *arr[], int start, int end)
{   
    if(start>end){
        return nullptr;
    }
    int mid = (start+end)/2;

    Node *temp = new Node();
    temp->data=  new NodeData(*arr[mid]);
    temp->right=arrayToBSTreeHelper(arr, mid+1, end);
    temp->left=arrayToBSTreeHelper(arr, start, mid-1);
    return temp;
}

// ------------------------------------BinTree displaySideWays ----------------------------------------
// Description: Displays the Tree vissually 
// ---------------------------------------------------------------------------------------------------
void BinTree::displaySideways() const
{
    sideways(head_, 0);
}

// ------------------------------------BinTree sideWays -----------------------------------------------
// Description: Helper method for displaying the tree
// Recursivley travserses the tree keeping track of the level for indentation 
// ---------------------------------------------------------------------------------------------------
void BinTree::sideways(Node *current, int level) const
{
    if (current != NULL) {
        level++;
        sideways(current->right, level);
        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << " ";
        }
        cout << *current->data << endl; // display information of object
        sideways(current->left, level);
    }   
}

// ------------------------------------BinTree PrintInOrder -------------------------------------------
// Description: Prints the contents of the BST in order, starts from a given node
// Reutrns an ostream
// ---------------------------------------------------------------------------------------------------
ostream & BinTree::printInOrder(std::ostream &os, Node *node) const
{
    if(node == nullptr){
        return os; 
    }

       printInOrder(os, node->left);
       os<<*node->data<<" ";
       printInOrder(os, node->right);
       return os;
        
}

// ------------------------------------BinTree operator << --------------------------------------------
// Description: Prints the contents of the BST 
// Reutrns an ostream
// ---------------------------------------------------------------------------------------------------
ostream &operator<<(std::ostream &os, const BinTree &tree)
{
    return tree.printInOrder(os, tree.head_)<<endl;

}