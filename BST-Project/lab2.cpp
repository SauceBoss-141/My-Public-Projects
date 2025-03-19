// I will test your BinTree class using either this main or
// a very similar one, and this buildTree.  
// You will want to do thorough testing on your own, 
// which is done by altering the data.

// Windows and unix store files slightly differently. Windows does not
// always store an end-of-line char on the last line, where unix does.
// On windows, always make sure the cursor is on the line after
// the last line of data so it acts like unix/linux.

// presumably bintree.h includes nodedata.h so the include is not needed here
#include "BinTree.h"
#include <fstream>
#include <iostream>
using namespace std;

const int ARRAYSIZE = 100;

//global function prototypes
void buildTree(BinTree&, ifstream&);      // 
void initArray(NodeData*[]);             // initialize array to NULL
void insertAndRemoveTest();
void arrayToBSTreeTest();
void deepCopyTest();

int main() {
	// create file object infile and open it
	// for testing, call your data file something appropriate, e.g., data2.txt
	ifstream infile("data2.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	// the NodeData class must have a constructor that takes a string
	NodeData notND("not");
	NodeData andND("and");
	NodeData sssND("sss");
	NodeData ttttND("tttt");
	NodeData oooND("ooo");
	NodeData yND("y");
	NodeData eND("e");
	NodeData mND("m");
	NodeData tND("t");

	BinTree T, T2, dup;
	NodeData* ndArray[ARRAYSIZE];
	initArray(ndArray);
	cout << "Initial data:" << endl << "  ";
	buildTree(T, infile);              // builds and displays initial data
	cout << endl;
	BinTree first(T);                  // test copy constructor
	dup = dup = T;                     // test operator=, self-assignment
	while (!infile.eof()) {
		cout << "Tree Inorder:" << endl << T;             // operator<< does endl
		T.displaySideways();

		// test retrieve 
		NodeData* p;                    // pointer of retrieved object
		bool found;                     // whether or not object was found in tree
		found = T.retrieve(andND, p);
		cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
		found = T.retrieve(notND, p);
		cout << "Retrieve --> not:  " << (found ? "found" : "not found") << endl;
		found = T.retrieve(sssND, p);
		cout << "Retrieve --> sss:  " << (found ? "found" : "not found") << endl;

		// test getHeight 
		cout << "Height    --> and:  " << T.getHeight(andND) << endl;
		cout << "Height    --> not:  " << T.getHeight(notND) << endl;
		cout << "Height    --> sss:  " << T.getHeight(sssND) << endl;
		cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;
		cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
		cout << "Height    --> y:  " << T.getHeight(yND) << endl;

		// test ==, and != 
		T2 = T;
		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
		cout << "T != first?  " << (T != first ? "not equal" : "equal") << endl;
		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
		dup = T;

		// somewhat test bstreeToArray and arrayToBSTree
		T.bstreeToArray(ndArray);
		T.arrayToBSTree(ndArray);
		T.displaySideways();

		T.makeEmpty();                  // empty out the tree
		initArray(ndArray);             // empty out the array

		cout << "---------------------------------------------------------------"
			<< endl;
		cout << "Initial data:" << endl << "  ";
		buildTree(T, infile);
		cout << endl;
	}
	insertAndRemoveTest();
	arrayToBSTreeTest();
	deepCopyTest();
	return 0;
}

//------------------------------- buildTree ----------------------------------
// YOU COMMENT

// To build a tree, read strings from a line, terminating when "$$" is
// encountered. Since there is some work to do before the actual insert that is
// specific to the client problem, it's best that building a tree is not a 
// member function. It's a global function. 

void buildTree(BinTree& T, ifstream& infile) {
	string s;

	for (;;) {
		infile >> s;
		cout << s << ' ';
		if (s == "$$") break;                // at end of one line
		if (infile.eof()) break;             // no more lines of data
		NodeData* ptr = new NodeData(s);     // NodeData constructor takes string
		// would do a setData if there were more than a string

		bool success = T.insert(ptr);
		
		delete ptr;                       // duplicate case, not inserted 
	}
}

//------------------------------- initArray ----------------------------------
// initialize the array of NodeData* to NULL pointers

void initArray(NodeData* ndArray[]) {
	for (int i = 0; i < ARRAYSIZE; i++)
		ndArray[i] = NULL;
}

void insertAndRemoveTest()
{
	NodeData notND= NodeData("not");
	NodeData andND= NodeData("and");
	NodeData sssND= NodeData("sss");
	NodeData hhhND= NodeData("hhh");
	NodeData ttttND= NodeData("tttt");
	NodeData oooND= NodeData("ooo");
	NodeData yND= NodeData("y");
	NodeData eND= NodeData("e");
	NodeData mND= NodeData("m");
	NodeData tND= NodeData("t");
	BinTree tree1 ;
	tree1.insert(&hhhND);
	tree1.insert(&eND);
	tree1.insert(&andND);
	tree1.insert(&oooND);
	tree1.insert(&mND);
	tree1.insert(&yND);
	cout<<tree1<<endl;
	tree1.remove(&andND);
	cout<<tree1<<endl;

}

void arrayToBSTreeTest()
{
	const int arrSize =20;
	NodeData* inArray[arrSize+1];
	for(int i = 0; i<arrSize;i++){
		string temp = to_string(i);
		NodeData* tmp = new NodeData(temp);
		inArray[i]=tmp;
	}
	inArray[arrSize]= nullptr;
	BinTree tree1 ;
	tree1.arrayToBSTree(inArray);
	cout<<tree1<<endl;	
	
	NodeData* outArray[arrSize];
	tree1.bstreeToArray(outArray);

	cout<<tree1<<endl;
	cout<<"Now the tree contents in the new array:"<<endl;
	for(int i=0; i < arrSize;i++){
		cout<<*outArray[i]<<" ";
	}
	cout<<""<<endl;

	for(int i = 0; i <arrSize; i++){
		delete(outArray[i]);
	}
}

void deepCopyTest()
{
	BinTree tree1;
	BinTree tree2;
	NodeData notND= NodeData("3");
	NodeData andND= NodeData("2");
	NodeData sssND= NodeData("4");
	NodeData hhhND= NodeData("1");
	tree1.insert(&notND);
	tree1.insert(&andND);
	tree1.insert(&sssND);
	tree1.insert(&hhhND);
	tree2 = tree1;
	BinTree tree3 = tree1;
	cout<<"Tree 1:"<<endl;
	cout<<tree1<<endl;
	cout<<"Tree 2:"<<endl;
	cout<<tree2<<endl;
	cout<<"Tree 3:"<<endl;
	cout<<tree3<<endl;
	cout<<"Deleting 1 from tree 1. Deleting 3 from tree 2. Deleting 4 from tree 3"<<endl;
	tree1.remove(&hhhND);
	tree2.remove(&notND);
	tree3.remove(&sssND);
	cout<<"Tree 1:"<<endl;
	cout<<tree1<<endl;
	cout<<"Tree 2:"<<endl;
	cout<<tree2<<endl;
	cout<<"Tree 3:"<<endl;
	cout<<tree3<<endl;	

	NodeData* p;                    // pointer of retrieved object
	bool found;   
	cout<<"--------------------------"<<endl;                  // whether or not object was found in tree
	cout<<"Tree 1:"<<endl;
	found = tree1.retrieve(notND, p);
	cout << "Retrieve --> 3:  " << (found ? "found" : "not found") << endl;
	found = tree1.retrieve(hhhND, p);
	cout << "Retrieve --> 1:  " << (found ? "found" : "not found") << endl;
	cout<<"--------------------------"<<endl;   
	cout<<"Tree 2:"<<endl;         
	found = tree2.retrieve(sssND, p);
	cout << "Retrieve --> 4:  " << (found ? "found" : "not found") << endl;
	found = tree2.retrieve(notND, p);
	cout << "Retrieve --> 3:  " << (found ? "found" : "not found") << endl;
	cout<<"--------------------------"<<endl;  
	cout<<"Tree 3:"<<endl;          
	found = tree3.retrieve(notND, p);
	cout << "Retrieve --> 3:  " << (found ? "found" : "not found") << endl;
	found = tree3.retrieve(sssND, p);
	cout << "Retrieve --> 4:  " << (found ? "found" : "not found") << endl;
	cout<<"--------------------------"<<endl;  
	cout<<"Testing Make empty"<<endl;
	tree1.makeEmpty();
	cout<<"Is Tree 1 empty: "<<tree1.isEmpty()<<endl;
	cout<<tree1<<endl;
}
