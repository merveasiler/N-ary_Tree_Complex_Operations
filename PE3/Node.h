#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Node {
	vector<Node*> children;
	int id;

public:
	Node(int);
	~Node();
	Node(const Node&);
	bool operator==(const Node&) const;
	bool operator==(int);
	bool operator<(const Node&) const;
	void operator+=(Node&);			// arg�man olarak <const Node&> vermeyi d���n, const olunca Clone() fonksiyonuna ihtiya� duyabilir. 
	Node* operator&(const Node&) const;
	vector<Node*>& getChildren();
	char getData() const;
	friend ostream& operator<<(ostream& os, const Node& node);
};

class DataNode : public Node {
	char data;
public:
	DataNode(int, char);
	~DataNode();
	DataNode(const Node&, char);
	DataNode(const DataNode&);	// buna gerek de olmuyor ama kafalar� kar���r m�?
	char getData() const;
	friend ostream& operator<<(ostream& os, const DataNode& node);
};