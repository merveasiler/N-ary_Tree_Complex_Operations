#include "Node.h"
#include "NodeManager.h"
#include "Search.h"
#include "Action.h"

int main() {

	NodeManager* nodeManager = new NodeManager();
	nodeManager->addRelation(10, 12);
	nodeManager->addRelation(3, 10);
	nodeManager->addRelation(12, 2);
	nodeManager->addRelation(3, 5);
	nodeManager->addRelation(5, 40);
	nodeManager->addRelation(5, 37);
	nodeManager->addRelation(37, 20);
	nodeManager->addRelation(12, 9);
	nodeManager->addRelation(12, 39);
	nodeManager->addRelation(22, 38);
	nodeManager->addRelation(39, 15);
	nodeManager->addRelation(3, 22);
	nodeManager->addRelation(22, 4);
	nodeManager->addRelation(22, 38);	// input verirken unique'lik olsun mu

	cout << nodeManager->getNodeTree(0);

}