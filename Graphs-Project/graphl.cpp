#include "graphl.h"

// ------------------------------------GraphL Constructor -------------------------------------------
// Description: Sets size to 0
// --------------------------------------------------------------------------------------------------
GraphL::GraphL()
{
    size_=0;
    
}//End GraphL Constructor 

// ------------------------------------GraphL De-Constructor -----------------------------------------
// Description: Deletes all dynamically alocated memory
// ---------------------------------------------------------------------------------------------------
GraphL::~GraphL()
{
    for (int i = 1; i <= size_; i++) {
        delete graph[i].data;
        graph[i].data= nullptr;
        graph[i].visited=false;
        EdgeNode* currentEdge = graph[i].edgeHead;
        while (currentEdge != nullptr) {
            EdgeNode* temp = currentEdge;
            
            currentEdge = currentEdge->nextEdge;
            delete temp;
        }
        //delete graph[i];
        graph[i].edgeHead = nullptr;
        
        
    }
    size_=0;
}//End Graphl De-constructor

// ------------------------------------GraphL Build graph --------------------------------------------
// Description: Reads a data file by refrence 
// builds ajecency list with Nodedata for hte name of the nodes and edges
// ---------------------------------------------------------------------------------------------------
void GraphL::buildGraph(ifstream &infile1)
{   

    string line;
    
    // Read the size of the graph
    if (getline(infile1, line)) {
        stringstream ss(line);
        ss >> size_;
    }

    // Read node names
    for (int i = 1; i <=size_; i++) {
        string nodeName;
        if (getline(infile1, nodeName)) {
            //GraphNode *temp = new GraphNode();
           // temp->data =  new NodeData(nodeName);
            graph[i].data = new NodeData(nodeName);
            graph[i].edgeHead= nullptr;
        }
    }
    int from, to;
    while (getline(infile1, line)){
        stringstream ss(line);
        ss >> from >> to;

        // If we reach the end marker (0 0 0), break the loop
        if (from == 0 && to ==0) {
            break;
        }
        EdgeNode *temp = new EdgeNode;
        temp->adjGraphNode =to;
        
        temp->nextEdge= graph[from].edgeHead;
        graph[from].edgeHead =temp;
       
    }

}//End GraphL build graph

// ------------------------------------GraphL displayGraph -------------------------------------------
// Description: Displays graph by the name of the starting node and its edges
// ---------------------------------------------------------------------------------------------------
void GraphL::displayGraph()
{
    cout<<"Graph:"<<endl;
    for(int i = 1; i <=size_; i++){
        cout<<" Node"<<i<<"\t"<<*graph[i].data<<endl;
        EdgeNode* temp = graph[i].edgeHead;
        while (temp!= nullptr){
            cout<<"    "<<i<< "\t"<<(temp->adjGraphNode)<<endl;
            temp = temp->nextEdge;
        }
    }
}//End GraphL Display graph

// ------------------------------------GraphL Depth First Search -------------------------------------
// Description: Calculates the path using Depth first search on the Adjcency list
// Prints out the path
// ---------------------------------------------------------------------------------------------------
void GraphL::depthFirstSearch()
{   
    string output;
    stack<int> path;

    // Reset visited nodes before traversal
    for (int i = 1; i <= size_; i++) {
        graph[i].visited = false;
    }

    // Perform DFS starting from node 1
    path.push(1);
    graph[1].visited = true;

    while (!path.empty()) {
        int node = path.top();
        path.pop();
        output += to_string(node) + " ";

        // Use a temporary stack to push nodes in correct order
        stack<int> tempStack;
        EdgeNode *temp = graph[node].edgeHead;
        while (temp != nullptr) {
            if (!graph[temp->adjGraphNode].visited) {
                tempStack.push(temp->adjGraphNode);
                graph[temp->adjGraphNode].visited = true;
            }
            temp = temp->nextEdge;
        }

        // Push nodes from tempStack to maintain correct DFS order
        while (!tempStack.empty()) {
            path.push(tempStack.top());
            tempStack.pop();
        }
    }

    cout << "\nDepth First Search:\n" << output << endl;
}//End GraphL Depth First Search