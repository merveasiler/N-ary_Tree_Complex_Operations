#include "Search.h"
#include "Exception.h"

vector<char> PreOrder::match(const Node* node) const {

	Node* cnode = new Node(*node);	// bu tarz konularda uyarý yap, panikleyip soru sormaya kalkýþmasýnlar

	vector<char> password;
	try {
		password.push_back(node->getData());
	}
	catch (InvalidRequest e) {}

	while (cnode->getChildren().size() > 0) {
		Node* minNode = cnode->getChildren()[0];
		int min_ind;
		for (int i = 0; i < cnode->getChildren().size(); i++) {
			if (cnode->getChildren()[i]->getId() < minNode->getId()) {
				minNode = cnode->getChildren()[i];
				min_ind = i;
			}
		}
		vector<char> output = match(minNode);
		for (int i = 0; i < output.size(); i++)
			password.push_back(output[i]);
		vector<Node*>& children = cnode->getChildren();
		children.erase(children.begin() + min_ind, children.begin() + min_ind + 1);
	}

	delete cnode;
	return password;
}

vector<char> PostOrder::match(const Node* node) const {

	Node* cnode = new Node(*node);	// bu tarz konularda uyarý yap, panikleyip soru sormaya kalkýþmasýnlar
	vector<char> password;

	while (cnode->getChildren().size() > 0) {
		Node* minNode = cnode->getChildren()[0];
		int min_ind;
		for (int i = 0; i < cnode->getChildren().size(); i++) {
			if (cnode->getChildren()[i]->getId() < minNode->getId()) {
				minNode = cnode->getChildren()[i];
				min_ind = i;
			}
		}
		vector<char> output = match(minNode);
		for (int i = 0; i < output.size(); i++)
			password.push_back(output[i]);
		vector<Node*>& children = cnode->getChildren();
		children.erase(children.begin() + min_ind, children.begin() + min_ind + 1);
	}

	try {
		password.push_back(node->getData());
	}
	catch (InvalidRequest e) {}

	delete cnode;
	return password;

}