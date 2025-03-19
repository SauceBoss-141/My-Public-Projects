#include "graphm.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <climits>

// ------------------------------------GraphM Constructor --------------------------------------------
// Description: Builds a Graph M object. 
// Sets size = 0 and sets the matrix to -1 values as in un populated
// ---------------------------------------------------------------------------------------------------
GraphM::GraphM()
{
    size_ = 0;
     for (int i = 0; i < MAXNODES_; i++){
            for (int j = 0; j < MAXNODES_; j++){
                     C[i][j] = -1;
            }
    }       
}//End of GraphM constructor 

// ------------------------------------GraphM buildGraph ---------------------------------------------
// Description: Takes in a file and reads it by refrence 
// Sets size and populates Node names
// Reads file and populates matrix 
// ---------------------------------------------------------------------------------------------------
void GraphM::buildGraph(ifstream &infile1)
{
     string line;
    
    // Read the size of the graph
    if (getline(infile1, line)) {
        stringstream ss(line);
        ss >> size_;
    }

    // Read node names
    for (int i = 1; i <= size_; i++) {
        string nodeName;
        if (getline(infile1, nodeName)) {
            data[i] = NodeData(nodeName);
        }
    }

    // Read edges
    int from, to, weight;
    while (getline(infile1, line)) {
        // Parse the line into from, to, and weight
        stringstream ss(line);
        ss >> from >> to >> weight;

        // If we reach the end marker (0 0 0), break the loop
        if (from == 0 && to == 0 && weight == 0) {
            break;
        }

        // Insert the edge into the graph (check if from and to are valid)
        if (from > 0 && to > 0) {
            insertEdge(from, to, weight);
        }
    }

}//End of Build Graph

// ------------------------------------GraphM Insert Edge --------------------------------------------
// Description: Takes in three ints, from node too node and weight
// Assings weight value to the matrix indexes on [from][too]
// ---------------------------------------------------------------------------------------------------
void GraphM::insertEdge(int from, int too, int weight)
{
    C[from][too]= weight;
}//End of Insert Edge

// ------------------------------------GraphM remove Edge --------------------------------------------
// Description: Takes in two ints
// Removes weight for that edge of the matrix and re sets it too -1
// ---------------------------------------------------------------------------------------------------
void GraphM::removeEdge(int from, int too)
{
     C[from][too]= -1;
}//End of Remove edge

// ------------------------------------GraphM Display All --------------------------------------------
// Description: Displays all datas and there asscoiated edges and shortest paths
// ---------------------------------------------------------------------------------------------------
void GraphM::displayAll()
{   
    cout<<"Description"<<"\t"<<"From Node"<<"\t"<<"To Node"<<"\t"<<"\t"<<"Dijkstra's Path"<<endl;
    cout<<endl;
    for(int i = 1; i <=size_;i++){
        cout<< data[i];
        cout<<endl;
        for(int j = 1; j<=size_; j++){
            cout<<"\t"<<"\t";
            displayHelper(i,j);
            cout<<endl;

        }
        
    }
    //cout<<endl;
    cout<<"-------------------------------------------"<<endl;
}//End of Display All

// ------------------------------------GraphM dsipaly --------------------------------------------
// Description: This method will dsiplay the shortest path from one node to another
// Takes in two int's a from node and a too node
// ------------------------------------------------------------------------------------------------
void GraphM::display(int from, int too)
{   
        vector<int> streets= displayHelper(from, too);
        if(streets.size()!= 0){
        for(int i = streets.size(); i>=0; i--){
            cout<<data[streets[i]]<<endl;
            }
        }
        cout<<endl;
}//End of Display

// ------------------------------------GraphM Find shortest Path -------------------------------------
// Description: Finds the shortest path from the given array matrix. 
// Storse said path 
// ---------------------------------------------------------------------------------------------------
void GraphM::findShortestPath()
{
    for (int source = 1; source <= size_; source++) {
        for(int i =1; i<=size_; i++){
            T[source][i].visited = false;
            T[source][i].dist = INT_MAX;
            T[source][i].path = 0;

        }
        T[source][source].dist = 0;
        // finds the shortest distance from source to all other nodes
        for (int i = 1; i<= size_; i++) {
            int v = findMinNode(source);
            //find v //not visited, shortest distance at this point
            if(v==-1)break;
            T[source][v].visited = true;
            
            for(int w =1; w<= size_; w++){
                if(!T[source][w].visited && C[v][w]!=-1){
                    int newDist = T[source][v].dist +C[v][w];
                    if(newDist < T[source][w].dist){
                        T[source][w].dist=newDist;
                        T[source][w].path=v;
                    }
                }
            }
            
            }
        }
}//End of Find Shortest Path

// ------------------------------------GraphM Dsiplay Helepr -----------------------------------------
// Description: Displays the edge given in two ints from and two
// Dsiplays the shortets path from the 'from' node to the 'too' node. 
// Returns an int vector of the path
// ---------------------------------------------------------------------------------------------------
vector<int> GraphM::displayHelper(int from, int too)
{
    if(T[from][too].dist==INT_MAX){
    cout<<"\t"<<from<<"\t"<<too;
    cout<<"\t"<<"----"<<"\t"<<endl;
  }else if(too != from){
    cout<<"\t"<<from<< "\t"<<too;
    cout<<"\t"<< T[from][too].dist<<"\t";
    string path = "";
    int current = too;
    vector<int> streets;
    do{
        path = to_string(current)+ " "+path;
        streets.push_back(current);
        current = T[from][current].path;
    }while(current != from && current !=-1);
        path = to_string(from)+ " "+path;
        streets.push_back( from);
        cout<<path<<endl;
        return streets;
    }
    vector<int> temp;
    return  temp;
}// End of Dsiplay Helper


// ------------------------------------GraphM Find min node ------------------------------------------
// Description: Takes in one int source, to represent a node from the matrix
// Returns an int represening the next node with the shortest weight/distance
// ---------------------------------------------------------------------------------------------------
int GraphM::findMinNode(int source)
{
    int minDist = INT_MAX, minIndex = -1;
    for(int i = 1; i<= size_;i++){
        if(!T[source][i].visited && T[source][i].dist<minDist){
            minDist = T[source][i].dist;
            minIndex = i;
        }
    }
    return minIndex;
}//End of Find Min Node
