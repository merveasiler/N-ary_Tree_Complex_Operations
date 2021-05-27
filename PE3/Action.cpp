#include "Action.h"
#include "Exception.h"

/********************** Complete **************************/

Complete::Complete(const Node& node) {
	Node* memberNode = new Node(node);
}

Complete::~Complete() {
	delete memberNode;
}

Node* act_helper(const Node& node, Node* actingNode) {

	if (node.getId() == actingNode->getId()) {
		Node* cnode1 = new Node(node);	// copy constructor ekleyeyim
		Node* cnode2 = actingNode;
		Node* output = *cnode1 & *cnode2;
		for (int i = 0; i < cnode1->getChildren().size(); i++) {
			for (int j = 0; j < cnode2->getChildren().size(); j++)
				if (cnode1->getChildren()[i]->getId() == cnode2->getChildren()[j]->getId()) {
					Node* child = act_helper(*cnode1->getChildren()[i], cnode2->getChildren()[j]);
					*output += *child;
					break;
				}
		}
		delete cnode1;
		return output;
	}

}

Node* Complete::act(const Node& node) {
	
	return act_helper(node, memberNode);

}

/************************* Cut ***************************/

Cut::Cut(char character) {
	this->memberChar = character;
}

Cut::~Cut() {

}

int Cut::count2Gen(Node* node) {
	int total = 0;
	vector<Node*>& children = node->getChildren();
	for (int i = 0; i < children.size(); i++) {
		try {
			char data = children[i]->getData();
			if (data == memberChar)
				total++;
		}
		catch (InvalidRequest e) {}
		vector<Node*>& grandchildren = children[i]->getChildren();
		for (int j = 0; j < grandchildren.size(); j++) {
			try {
				char data = grandchildren[j]->getData();
				if (data == memberChar)
					total++;
			}
			catch (InvalidRequest e) {}
		}
	}
	return total;
}
bool doesHaveGrandChild(Node* node) {
	
	vector<Node*>& children = node->getChildren();
	for (int i = 0; i < children.size(); i++)
		if (children[i]->getChildren().size() > 0)
			return false;
	return true;
}

void deleteChildren(Node* node) {
	for (int j = 0; j < node->getChildren().size(); j++) {
		delete node->getChildren()[j];
		node->getChildren()[j] = NULL;
	}
	node->getChildren().clear();
}

Node* Cut::act(const Node& node) {

	Node* cnode = new Node(node);
	for (int i = 0; i < cnode->getChildren().size(); i++) {
		Node* child = cnode->getChildren()[i];
		if (doesHaveGrandChild(child)) {
			Node* newChild = act(*child);
			delete child;
			cnode->getChildren()[i] = newChild;
		}
		else {
			if (count2Gen(child) >=2) {
				deleteChildren(child);
				Node* newChild = new DataNode(*child, memberChar);
				delete child;
				cnode->getChildren()[i] = newChild;
			}
		}
	}

	if (count2Gen(cnode) >= 2) {
		deleteChildren(cnode);
		Node* newNode = new DataNode(*cnode, memberChar);
		delete cnode;
		cnode = newNode;
	}

	return cnode;
}