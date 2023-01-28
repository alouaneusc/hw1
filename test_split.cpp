/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
		//emp case//sing value odd/single even/ dbl vsl even evem/ dobl val even odd/ dbl val
		Node* a = new Node(1, nullptr);
		Node* b = new Node(2, nullptr);
		Node* c = new Node(3, nullptr);
		a->next = b;
		b->next = c;
		c->next = nullptr;

		Node* r = nullptr;

		// std::cout << r <<std::endl;

		// if (!r) return 1;

		Node* odds = nullptr;
		Node* evens = nullptr;

	split(r, odds, evens);

	// std::cout << odds->value << " " << odds->next->value << std::endl;
	// std::cout << evens->value << std::endl;
		
}
