#ifndef BinTree_H_
#define BinTree_H_
#include <iostream>
#include <string>
#include "nodedata.h"
#include "queue"
using namespace std;

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
class BinTree{
    
    public:
    //Node Class
    //Contains a NodeData pointer
    //Left and right Node pointers
    struct Node{
        NodeData *data = nullptr;
        Node *right = nullptr;
        Node * left = nullptr;

    };

    // ------------------------------------BinTree Constructor---------------------------------------------
    // Description: Creates a defualt "empty" Binary Search Tree with head set to null and size = 0
    // ---------------------------------------------------------------------------------------------------
    BinTree();

    // ------------------------------------BinTree Copy Constructor----------------------------------------
    // Description: Creates a copy of another tree named 'other' 
    // ---------------------------------------------------------------------------------------------------
    BinTree(const BinTree&other);

    // ------------------------------------BinTree De-constructor------------------------------------------
    // Description: Deletes all dynamically allocated memory, sets size to 0 and head to nullptr
    // ---------------------------------------------------------------------------------------------------
    ~BinTree();
    // ------------------------------------BinTree Insert -------------------------------------------------
    // Description: Inserts a NodeData object into the tree and increments size by 1
    // ---------------------------------------------------------------------------------------------------
    bool insert(const NodeData *obj);
    // ------------------------------------BinTree remove -------------------------------------------------
    // Description: removes a target NodeData
    // ---------------------------------------------------------------------------------------------------
    bool remove(NodeData* target);

    // ------------------------------------BinTree isEmpty ------------------------------------------------
    // Description: Returns a boolean value wether or not the tree is empty or contains a value
    // ---------------------------------------------------------------------------------------------------
    bool isEmpty()const;

    // ------------------------------------BinTree makeEmpty ----------------------------------------------
    // Description: Deletes all nodes and data isnide of the tree
    // ---------------------------------------------------------------------------------------------------
    void makeEmpty();

    // ------------------------------------BinTree getSize ------------------------------------------------
    // Description: Returns the size (number of nodes) inside of the tree
    // ---------------------------------------------------------------------------------------------------
    int getSize();

    // ------------------------------------BinTree getHeight ----------------------------------------------
    // Description: Returns an Integer of the height of a Node contaning the passed in NodeData
    // ---------------------------------------------------------------------------------------------------
    int getHeight(const NodeData& start);

    // ------------------------------------BinTree retrieve -----------------------------------------------
    // Description: Looks for a target NodeData object and will assign its value to a passed in empty NodeData
    // If NodeData is not found it will be set to nullptr
    // ---------------------------------------------------------------------------------------------------
    bool retrieve(const NodeData& target ,  NodeData *&nodeData);

    // ------------------------------------BinTree operator << --------------------------------------------
    // Description: Prints the contents of the BST 
    // Reutrns an ostream
    // ---------------------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& stream, const BinTree& list);

    // ------------------------------------BinTree = operator ---------------------------------------------
    // Description: Creates a deep copy of the rhs BST and returns a new BST
    // ---------------------------------------------------------------------------------------------------
    BinTree &operator=(const BinTree& rhs);

    // ------------------------------------BinTree == Operator --------------------------------------------
    // Description: Compares two BSTs and determines if they are equal
    // ---------------------------------------------------------------------------------------------------
    bool operator==(const BinTree& other);

    // ------------------------------------BinTree != Operator --------------------------------------------
    // Description: Compares two BSTs and determines if they are not equal
    // ---------------------------------------------------------------------------------------------------
    bool operator!=(const BinTree& other);

    // ------------------------------------BinTree to an Array --------------------------------------------
    // Description: Takes BST values and puts them into sorted order into a given NodeData pointer array 
    // Turns all values in the BST to nullptr once done
    // ---------------------------------------------------------------------------------------------------
    void bstreeToArray(NodeData*arr []);

    // ------------------------------------Array to BinTree ----------------------------------------------
    // Description: Takes an array of NodeData pointers and adds them to a BST
    // Sorted Arrays willl yeild the best and most balanced tree 
    // --------------------------------------------------------------------------------------------------
    void arrayToBSTree(NodeData*arr[]);

    // ------------------------------------BinTree displaySideWays ----------------------------------------
    // Description: Displays the Tree vissually 
    // ---------------------------------------------------------------------------------------------------
    void displaySideways() const; 

    private:
    int size_ =0;
    Node *head_= nullptr;

    // ------------------------------------BinTree removeNode ---------------------------------------------
    // Description: Helper Method to help remove a target node.
    // Recursivley traverse a BST to find a target Node. Takes two Nodes, the start for the traversla and
    // The target. Returns a boolean upon completion. 
    // --------------------------------------------------------------------------------------------------- 
    bool removeNode(Node*& node, NodeData *target);

    // ------------------------------------BinTree fidnMin ----------------------------------------------
    // Description: finds the most minimum left node. 
    // This is used for help in rthe rmeove method
    // Reutrns Node pointer
    // -------------------------------------------------------------------------------------------------
    Node* findMin(Node* node);

    // ------------------------------------BinTree findNode -----------------------------------------------
    // Description: recurisvly traverses the BST until the target node is found or not found
    // if found, will return a pointer to that node
    // if not found, nullptr will be returned
    // ---------------------------------------------------------------------------------------------------
    Node* findNode(Node* node, const NodeData& target);

    // ------------------------------------BinTree DeleteBst ----------------------------------------------
    // Description: Deletes all Nodes and there data
    // Sets size to 0 and head_ to nullptr
    // ---------------------------------------------------------------------------------------------------
    void DeleteBST();

    // ------------------------------------BinTree DeleteBST ----------------------------------------------
    // Description: Recursivley deletes the BST. Sets head_ to nullptr
    // ---------------------------------------------------------------------------------------------------
    void DeleteBST(Node* node);

    // ------------------------------------BinTree Assignment help ----------------------------------------
    // Description: Assists = operator in copying each value over
    // ---------------------------------------------------------------------------------------------------
    Node* assignmentHelper( Node* other);

    // ------------------------------------BinTree PrintInOrder -------------------------------------------
    // Description: Prints the contents of the BST in order, starts from a given node
    // Reutrns an ostream
    // ---------------------------------------------------------------------------------------------------
    ostream & printInOrder(std::ostream &os, Node *node) const;

    // ---------------------------------BinTree to an Array Helper ----------------------------------------
    // Description: Helper method, recursivley does an inorder traversal of the BST
    // Inorder to assign values from BST to the Array in sorted order
    // ---------------------------------------------------------------------------------------------------
    void bstreeToArrayHelper(NodeData* arr[], Node * node, int&index);

    // ------------------------------------Array to BinTree Helper ----------------------------------------
    // Description: This methods helps take NodeData pointers and put them into a BST 
    // Taking the array needed to pull from, a start and an ending index
    // Returns a Node object
    // ---------------------------------------------------------------------------------------------------
    Node* arrayToBSTreeHelper(NodeData* arr[],  int start, int end);

    // ------------------------------------BinTree sideWays -----------------------------------------------
    // Description: Helper method for displaying the tree
    // Recursivley travserses the tree keeping track of the level for indentation 
    // ---------------------------------------------------------------------------------------------------
    void sideways(Node*currrent , int level) const;

    // ------------------------------------BinTree equalsHelper -------------------------------------------
    // Description: Recursivly traverse the tree comparing each value. Returns true or false 
    // ---------------------------------------------------------------------------------------------------
    bool equalsHelper(const Node* current, const Node* other);

    // ------------------------------------BinTree heightHelper -------------------------------------------
    // Description: This method helps the getHeight method, by recursivley traversing the tree counting 
    // the height fro the strat node
    // Reutrn Integer 
    // ---------------------------------------------------------------------------------------------------
    int heightHelper( Node* current);
};
#endif