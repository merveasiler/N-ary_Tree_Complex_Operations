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

	// Returns a reference to the collection of children
	vector<Node*>& getChildren();

	// Operator overload +=	: Adds the reference of the  
	void operator+=(Node&);

	// Operator overload &	:
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