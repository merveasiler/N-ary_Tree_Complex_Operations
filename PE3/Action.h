#pragma once

#include "Node.h"

class Action {

public:
	virtual Node* act(const Node&) = 0;
};

class Complete : public Action {
	Node* memberNode;
public:
	Complete(const Node&);
	~Complete();
	Node* act(const Node&);
};

class Cut : public Action {	// Truncate
	char memberChar;
	int count2Gen(Node* node);
public:
	Cut(char);
	~Cut();
	Node* act(const Node&);
};