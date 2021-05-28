#include "Node.h"
#include "Exception.h"

Node::Node(int id) {
	this->id = id;
}

Node::~Node() {
	for (int i = 0; i < children.size(); i++) {
		if (children[i] != NULL)
			delete children[i];
		children[i] = NULL;
	}
	children.clear();
}

Node::Node(const Node& node) {
	this->id = node.id;
	for (int i = 0; i < node.children.size(); i++) {
		Node* child = node.children[i];
		Node* newchild = NULL;
		try {
			char data = child->getData();
			newchild = new DataNode(*child, data);
		}
		catch (InvalidRequest e) {
			newchild = new Node(*child);
		}
		this->children.push_back(newchild);
	}
}

int Node::getId() const {
	return id;
}

char Node::getData() const {
	throw InvalidRequest();
}

vector<Node*>& Node::getChildren() {
	return children;
}

void Node::operator+=(Node& childNode) {
	this->children.push_back(&childNode);
}

Node* Node::operator&(const Node& node) const {

	Node* new_node = NULL;
	try {
		char data = node.getData();
		new_node = new DataNode(node, data);
	}
	catch (exception InvalidRequest) {
		try {
			char data = this->getData();
			new_node = new DataNode(node, data);
		}
		catch (exception InvalidRequest) {
			new_node = new Node(node);
		}
	}
	return new_node;
}

ostream& operator<<(ostream& os, const Node& node) {
	try {
		node.getData();
		os << *(DataNode*)&node;
	}
	catch (InvalidRequest e) {
		os << "[" << node.id;
		for (int i = 0; i < node.children.size(); i++)
			os << ", " << *node.children[i];
		os << "]";
		return os;
	}
}

/*************** DataNode *****************/

DataNode::DataNode(int id, char data) : Node(id) {
	this->data = data;
}

DataNode::~DataNode() {
	// automatically calls base class destructor
}

DataNode::DataNode(const DataNode& dataNode) : Node(dataNode) {

	this->data = dataNode.data;
}

DataNode::DataNode(const Node& node, char data) : Node(node) {
	this->data = data;
}

char DataNode::getData() const {
	return data;
}

ostream& operator<<(ostream& os, const DataNode& dataNode) {
	os << "[" << "(" << dataNode.id << "," << dataNode.data << ")";
	for (int i = 0; i < dataNode.children.size(); i++)
		os << ", " << *dataNode.children[i];
	os << "]";
	return os;
}