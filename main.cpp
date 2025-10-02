/* INSTRUCTIONS:
A movie reviewer is a person who watches a film, rates how good it is, and provides comments.

Write a C++ program which could be used to efficiently store these reviews by reviewers. Implement this in a linked list in which each node contains a rating and a comment.

You'll need to write code that adds nodes to the tail of the linked list. The sample code in this module contains the code to add nodes to the head of the linked list.

At program startup, ask the user which mode to use, new nodes at the head or the tail of the linked list.

Obtain two pieces of data from the user, the rating and the comments. Store these in the linked list.

After all reviews have been input, traverse the linked list to output the data and calculate/output the average review.*/

#include <iostream>
#include <string>

using namespace std;

struct ReviewNode {
	float rating;
	string comment;
	ReviewNode* next;
};

int main() {
	ReviewNode* head = nullptr;
	int modeChoice;
	float rating;
	string comment;
	char reviewChoice;

	// Ask the user which mode they want to use
	do {
		cout << "Which linked list method should we use?\n";
		cout << "\t[1] New nodes are added at the head of the linked list\n";
		cout << "\t[2] New nodes are added at the tail of the linked list\n";
		cout << "Choice: ";
		cin >> modeChoice;
		if (modeChoice != 1 && modeChoice != 2) {
			cout << "ERROR: Please enter 1 or 2. Try again.\n";
		}
	} while (modeChoice != 1 && modeChoice != 2);

	// Prompt the user for a rating
	do {
		cout << "Enter review rating 0-5: ";
		cin >> rating;
		if (rating < 0 || rating > 5) {
			cout << "ERROR: Please enter a rating between 0 and 5. Try again\n";
		}
	} while (rating < 0 || rating > 5);
	cin.ignore();

	// Prompt the user for a comment
	cout << "Enter review comments: ";
	getline(cin, comment);

	// Add a node for the review
	if (modeChoice == 1) {
		// Add node to front
	}
	else {
		// Add node to tail
	}
	
	// Ask the user if they want to enter another review
	cout << "Enter another review? Y/N: ";
	cin >> reviewChoice;

}