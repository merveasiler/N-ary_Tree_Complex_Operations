#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Node {
protected:
	vector<Node*> children;
	int id;

	// DO NOT MODIFY BELOW
public:
	// Contsructor : initializes <id> of the object to the given integer
	Node(int);

	// Destructor  : totally depends on your implementation
	// Note that it should delete any Node/DataNode linked to it
	~Node();

	// Copy constructor	: deep copy
	// Copy the <id> of the given Node object
	// Note that it should copy any Node/DataNode linked to it also
	Node(const Node&);

	// Returns <id> of the object
	int getId() const;

	// Returns <data> of the object for the type DataNode
	// Throws InvalidRequest exception for the type Node
	virtual char getData() const;

	// Returns the reference for collection of children
	vector<Node*>& getChildren();

	// Operator overload +=	: 
	// Adds the reference of the given node into the children of the left operand
	void operator+=(Node&);

	// Operator overload &	:
	// This operator can be need in Complete::act()
	// This operator ands two node objects such that if the operands are: 
	//		- Node x & Node y               -> it returns a new Node which is a copy of x (x=y)
	//		- Node x & DataNode y           -> it returns a new DataNode which is a copy of y
	//		- DataNode x & Node y           -> it returns a new DataNode which is a copy of x
	//		- DataNode x & DataNode y       -> it returns a new DataNode which is a copy of x (x=y)
	// It is ensured that this operation is called for the nodes whose ids are equal always and
	//       if both operand is of the type DataNode, then their char data are equal too.
	Node* operator&(const Node&) const;

	// Operator overload <<	:
	friend ostream& operator<<(ostream& os, const Node& node);
};

class DataNode : public Node {
	char data;

	// DO NOT MODIFY BELOW
public:
	// Contsructor : initializes <id> of the object to the given integer
	//               and <data> of the object to the given char
	DataNode(int, char);

	// Destructor  : totally depends on your implementation
	// Note that it should delete any Node/DataNode linked to it
	~DataNode();

	// Copy constructor	: deep copy
	// Copy the <id> and <data> of the given DataNode object
	// Note that it should copy any Node/DataNode linked to it also
	DataNode(const DataNode&);

	// Copy constructor : deep copy 
	// Copy the <id> of the given Node object and assign the given char value to <data>
	// Note that it should copy any Node/DataNode linked to it also
	DataNode(const Node&, char);

	// Returns <data> of the object for the type DataNode
	char getData() const;

	// Operator overload <<	:
	friend ostream& operator<<(ostream& os, const DataNode& node);
};