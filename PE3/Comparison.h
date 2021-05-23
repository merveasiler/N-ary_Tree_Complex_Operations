#pragma once

#include "Node.h"

class Comparison {

public:
	virtual void compare(const Node*, const Node*) const = 0;

};

