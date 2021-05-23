#pragma once

#include "Node.h"
#include <vector>
using namespace std;

class NodeManager {

	vector<Node*> trees;
public:
	NodeManager();
	~NodeManager();
	void addRelation(int, int);
	void setDataToNode(int, char);
	const Node& getNodeTree(int);		// remove
	const Node& getNode(int);
};