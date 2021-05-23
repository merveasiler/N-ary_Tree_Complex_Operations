#pragma once

#include "Action.h"
#include "Node.h"

class Search {

	Action* action;
	Search(Action*);

	public:

		Search();
		~Search();
		/**
		 * This pure virtual method determines whether a message
		 * passes this Filter or not
		 */
		virtual vector<char> match(const Node* node) const = 0;
		
		/**
		 * Gets/sets the Action associated with this Filter
		 */
		//virtual const Action* getAction() const = 0;
		//virtual void setAction(Action* action) = 0;

};

class PreOrder : public Search {

public:
	PreOrder();
	~PreOrder();
	vector<char> match(const Node*) const;
};

class PostOrder : public Search {
public:
	PostOrder();
	~PostOrder();
	vector<char> match(const Node*) const;
};

class MixSearch : public Search {

};