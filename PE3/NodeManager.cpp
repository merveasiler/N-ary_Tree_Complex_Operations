
#include "NodeManager.h"

NodeManager::NodeManager() {

}

NodeManager::~NodeManager() {

}

bool recursiveAdder(Node* tree, int parent, int child) {
	if (*tree == parent) {
		vector<Node*> children = tree->getChildren();
		for (int j = 0; j < children.size(); j++)
			if (*children[j] == child)
				return true;
		Node* node = new Node(child);
		*tree += *node;
		return true;
	}

	vector<Node*> children = tree->getChildren();
	for (int j = 0; j < children.size(); j++)
		if (recursiveAdder(children[j], parent, child))
			return true;
	
	return false;
}

void NodeManager::addRelation(int parent, int child) {
	
	for (int i = 0; i < trees.size(); i++) {
		if (recursiveAdder(trees[i], parent, child))
			return;
	}

	for (int i = 0; i < trees.size(); i++) {
		if (*trees[i] == child) {
			Node* node = new Node(parent);
			*node += *trees[i];
			trees[i] = node;
		}
	}

	Node* parentNode = new Node(parent);
	Node* childNode = new Node(child);
	*parentNode += *childNode;
	trees.push_back(parentNode);
}

int findRank(vector<Node*> treeSet, int id) {
	for (int i = 0; i < treeSet.size(); i++)
		if (*treeSet[i] == id)
			return i;
	return -1;
}

vector<Node*>& finder(vector<Node*> treeSet, int id) {
	vector<Node*> pair;	// parent-child where child is the node whose id is given

	for (int i = 0; i < treeSet.size(); i++) {
		if (*treeSet[i] == id) {
			pair.push_back(NULL);
			pair.push_back(treeSet[i]);
			return pair;
		}

		pair = finder(treeSet[i]->getChildren(), id);
		if (pair[1] != NULL) {
			if (pair[0] == NULL)
				pair[0] = treeSet[i];
			return pair;
		}
	}
}

void NodeManager::setDataToNode(int id, char data) {
	DataNode* dataNode = new DataNode(id, data);
	Node* node = NULL;

	vector<Node*>& found = finder(this->trees, id);
	if (found[1] != NULL) {
		node = found[1];
		if (found[0] == NULL) {
			int rank = findRank(this->trees, id);
			this->trees[rank] = dataNode;
		}
		else {
			int rank = findRank(found[0]->getChildren(), id);
			found[0]->getChildren()[rank] = dataNode;
		}
	}

	if (node == NULL)
		this->trees.push_back(dataNode);	// may get returned exception
	else {
		for (int i = 0; i < node->getChildren().size(); i++)
			*dataNode += *node->getChildren()[i];
	}	
	
	delete node;
}

const Node& NodeManager::getNodeTree(int index) {
	return *trees[index];
}

const Node& NodeManager::getNode(int id) {
	vector<Node*>& found = finder(this->trees, id);
	return *found[1];
}