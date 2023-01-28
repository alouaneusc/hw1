/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

/* Add a prototype for a helper function here if you need */
Node*& helper(Node*& in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
    // WRITE YOUR CODE HERE
	// in = nullptr;
	
	if (!in) {
		in = nullptr;
		odds = nullptr;
		evens = nullptr;
		return;
		
	}
	else {
		
		
  Node* arbitrary = helper(in, odds, evens);

		int r_val = (*arbitrary).value % 2; // check for even values
    if (r_val == 0) 
		{
        (*arbitrary).next = evens;
				// set evens to next value
        evens = arbitrary;
    }
    
    else 
		{
        (*arbitrary).next = odds;	 //check for odds values
				// set odds to next value
        odds = arbitrary;
    }
	}

std::cout <<"Fallen" << std::endl;

}

/* If you needed a helper function, write it here */
Node*& helper(Node*& in, Node*& odds, Node*& evens) 

// WRITE YOUR CODE HERE
{
	// hold val for bit
    Node* hold;

    if ((*in).next == nullptr) 
		{
    std::cout << "reached base case" << std::endl;

        return in;
    }
    else 
		{
    std::cout << "reached recursive" << std::endl;
			
        hold = helper((*in).next, odds, evens);
    }

    if ((*hold).value % 2 == 0) 
		{ // evens checker

        (*hold).next = evens;

        evens = hold;
        return in;
    }
    
    else

		 {// odds checker

        (*hold).next = odds;

        odds = hold;

        return in;
    }
}
