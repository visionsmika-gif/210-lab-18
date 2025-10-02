/* INSTRUCTIONS:
A movie reviewer is a person who watches a film, rates how good it is, and provides comments.

Write a C++ program which could be used to efficiently store these reviews by reviewers. Implement this in a linked list in which each node contains a rating and a comment.

You'll need to write code that adds nodes to the tail of the linked list. The sample code in this module contains the code to add nodes to the head of the linked list.

At program startup, ask the user which mode to use, new nodes at the head or the tail of the linked list.

Obtain two pieces of data from the user, the rating and the comments. Store these in the linked list.

After all reviews have been input, traverse the linked list to output the data and calculate/output the average review.*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

struct ReviewNode {
	float rating;
	string comment;
	ReviewNode* next;
};

void addNodeToFront(ReviewNode*& head, float newRating, const string& newComment);
void addNodeToTail(ReviewNode*& head, float newRating, const string& newComment);
// TODO: add a function to delete the linked list
void outputReviewsAndAvg(ReviewNode*& head);

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

	// Continuously add new ratings until the user doesn't want to anymore
	do {
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
			addNodeToFront(head, rating, comment);
		}
		else {
			addNodeToTail(head, rating, comment);
		}

		// Ask the user if they want to enter another review
		do {
			cout << "Enter another review? Y/N: ";
			cin >> reviewChoice;
			reviewChoice = tolower(reviewChoice);
			if (reviewChoice != 'y' && reviewChoice != 'n') {
				cout << "ERROR: Please enter Y or N. Try again.\n";
			}
		} while (reviewChoice != 'y' && reviewChoice != 'n');
	} while (reviewChoice == 'y');

	// Display the reviews and average
	outputReviewsAndAvg(head);

}

void addNodeToFront(ReviewNode*& head, float newRating, const string& newComment) {
	// Create a new node and make it the head of the linked list
	ReviewNode* newNode = new ReviewNode;
	newNode->rating = newRating;
	newNode->comment = newComment;
	newNode->next = head;
	head = newNode;
}

void addNodeToTail(ReviewNode*& head, float newRating, const string& newComment) {
	// Create a new node
	ReviewNode* newNode = new ReviewNode;
	newNode->rating = newRating;
	newNode->comment = newComment;
	newNode->next = nullptr;

	// Set the new node as the head if the linked list is empty
	if (!head) {
		head = newNode;
		return;
	}

	// If it's not empty, traverse the linked list tot he tail and add the node there
	ReviewNode* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

void outputReviewsAndAvg(ReviewNode*& head) {
	ReviewNode* current = head;
	double totalRating = 0.0;
	int numReviews = 0;
	double avgRating;
	const int RATING_PRECISION = 1;		// Used for setprecision()
	const int AVG_PRECISION = 5;		// Used for setprecision()

	if (!head) {
		cout << "The list of reviews is empty.\n";
		return;
	}

	cout << "Outputting all reviews:\n";

	// Traverse the linked list
	while (current) {
		// Output review
		++numReviews;
		cout << fixed << setprecision(RATING_PRECISION);
		cout << "\t> Review #" << numReviews << ": " << current->rating << ": " << current->comment << "\n";
	
		// Accumulate ratings
		totalRating += current->rating;

		current = current->next;
	}

	// Calculate and output the ratings' average
	avgRating = totalRating / numReviews;
	cout << fixed << setprecision(AVG_PRECISION);
	cout << "\t> Average: " << avgRating << "\n";
}