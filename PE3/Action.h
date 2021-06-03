#ifndef __ACTION_H__
#define __ACTION_H__

#include "Node.h"


class Action {

	// DO NOT MODIFY BELOW
public:
	virtual Node* act(const Node*) const = 0;
};

class CompleteAction : public Action {
	Node* memberNode;

	// DO NOT MODIFY BELOW
public:
	// Contsructor : initializes a Node object which takes role as the first operand of Complete action
	CompleteAction(const Node&);

	// Destructor  : totally depends on your implementation
	// Note that you should not delete the resulting tree (Node object) produced by some previous act() call
	~CompleteAction();

	// act(): It is explained and illustrated in a detailed way in the pdf
	// You have to construct a new Node by following the steps in the pdf and return that node
	Node* act(const Node*) const;
};

class CutAction : public Action {	// Truncate
	char memberChar;
	int count2Gen(Node* node) const;

	// DO NOT MODIFY BELOW
public:
	// Contsructor : initializes a char value which takes role as the first operand of Cut action
	// We will call that char value as "memberChar"
	CutAction(char);

	// Destructor  : totally depends on your implementation
	// Note that you should not delete the resulting tree (Node object) produced by some previous act() call
	~CutAction();

	// act(): It is explained and illustrated in a detailed way in the pdf
	// You have to construct a new Node by following the steps in the pdf and return that node
	Node* act(const Node*) const;
};

class CompositeAction : public Action {
	vector <const Action*> actions;

	// DO NOT MODIFY BELOW
public:
	// Contsructor : you may do your initializations
	CompositeAction();

	// Destructor  : totally depends on your implementation
	// Note that you should not delete the resulting tree (Node object) produced by some previous act() call
	// Also note that you should not delete any action added by addAction() method. 
	~CompositeAction();

	// addAction()
	// You have to save the given Action in a container and return "this" pointer for the syntactic purposes
	CompositeAction* addAction(const Action* );

	// act(): You are expected to call act() methods of the actions supplied to you by addAction() calls.
	// Please apply act() calls in the order of actions supplied by addAction()
	// You have to construct a new Node by applying the actions in the given order and return that node
	Node* act(const Node*) const;
};

#endif