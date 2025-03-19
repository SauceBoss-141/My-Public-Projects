#ifndef graphm_H
#define graphm_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "nodedata.h"
using namespace std;
const int MAXNODES_ =500;
struct TableType {
    bool visited = false; // whether node has been visited
    int dist; // shortest distance from source known so far
    int path; // previous node in path of min dist
};


// ------------------------------------------------ GraphM -----------------------------------------------------------
// Jacob Brown CSS343
// 02/08/25
// 02/20/25
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Representation of a Graph using an array matrix 
// Reads a txt data file
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses Dijkstras algorithm to find the shortest possible path from a node to all other nodes
// Able to display all nodes and theire edges as well as their shortest path
// Able to display One nodes shortest path 
// --------------------------------------------------------------------------------------------------------------------
class GraphM{

    public:
    // ------------------------------------GraphM Constructor --------------------------------------------
    // Description: Builds a Graph M object. 
    // Sets size = 0 and sets the matrix to -1 values as in un populated
    // ---------------------------------------------------------------------------------------------------
    GraphM();

    // ------------------------------------GraphM buildGraph ---------------------------------------------
    // Description: Takes in a file and reads it by refrence 
    // Sets size and populates Node names
    // Reads file and populates matrix 
    // ---------------------------------------------------------------------------------------------------
    void buildGraph(ifstream &infile1);

    // ------------------------------------GraphM Insert Edge --------------------------------------------
    // Description: Takes in three ints, from node too node and weight
    // Assings weight value to the matrix indexes on [from][too]
    // ---------------------------------------------------------------------------------------------------
    void insertEdge(int from, int too, int weight);

    // ------------------------------------GraphM remove Edge --------------------------------------------
    // Description: Takes in two ints
    // Removes weight for that edge of the matrix and re sets it too -1
    // ---------------------------------------------------------------------------------------------------
    void removeEdge(int from, int too);

    // ------------------------------------GraphM Display All --------------------------------------------
    // Description: Displays all datas and there asscoiated edges and shortest paths
    // ---------------------------------------------------------------------------------------------------
    void displayAll();

    // ------------------------------------GraphM dsipaly --------------------------------------------
    // Description: This method will dsiplay the shortest path from one node to another
    // Takes in two int's a from node and a too node
    // ------------------------------------------------------------------------------------------------
    void display(int from, int too);

    // ------------------------------------GraphM Find shortest Path -------------------------------------
    // Description: Finds the shortest path from the given array matrix. 
    // Storse said path 
    // ---------------------------------------------------------------------------------------------------  
    void findShortestPath();




    private:
    NodeData data[MAXNODES_]; // data for graph nodes
    int C[MAXNODES_][MAXNODES_]; // Cost array, the adjacency matrix
    int size_=0;
    TableType T[MAXNODES_][MAXNODES_];

    // ------------------------------------GraphM Dsiplay Helepr -----------------------------------------
    // Description: Displays the edge given in two ints from and two
    // Dsiplays the shortets path from the 'from' node to the 'too' node. 
    // Returns an int vector of the path
    // ---------------------------------------------------------------------------------------------------
    vector<int> displayHelper(int from, int too);

    // ------------------------------------GraphM Find min node ------------------------------------------
    // Description: Takes in one int source, to represent a node from the matrix
    // Returns an int represening the next node with the shortest weight/distance
    // ---------------------------------------------------------------------------------------------------
    int findMinNode(int source);

};
#endif