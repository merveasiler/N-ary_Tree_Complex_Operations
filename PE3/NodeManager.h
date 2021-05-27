#pragma once

#include "Node.h"
#include <vector>
using namespace std;

class NodeManager {

	vector<Node*> trees;

	// DO NOT MODIFY BELOW
	public:
		// Contsructor : You can initialize your variables depending on your implementation
		NodeManager();

		// Destructor  : totally depends on your implementation
		// Note that it is responsible of destroying any tree (node) it contains
		~NodeManager();

		// It takes 2 integer such that
		//    - the first one is parent node id
		//    - the second one is child node id
		// If there does not exist any node with the given id(s), you should construct it (them) first
		// Later, you should attach the given <parent-child> to the correct position in your collection
		void addRelation(int, int);

		// This converts the Node object whose id is given in the first argument into DataNode
		// It assigns the given char value in the second argument to the final DataNode object
		// You should delete the current Node object and construct a new DataNode object
		// Do not forget to attach the new DataNode object into the position of destroyed Node object!
		void setDataToNode(int, char);

		// It returns a reference to the node whose id is given in the argument
		const Node& getNode(int);
};