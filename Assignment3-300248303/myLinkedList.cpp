/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
    Evaluation* head = nullptr;  // Initialize the head of the linked list
    int number = 0;              // Variable to store the count of elements in the list
    int choice;                  // Declare choice to store user's menu selection

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(head);
			break;
		case 2: head = add(head, number);
			break;
		case 3: head = remove(head, number);
			break;
		case 4: average(head, number);
			break;
		case 5: exit(0);
		default:
		    cout << "Invalid choice, please try again." << endl;

		}
	} while (true);

	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* head, int& number)
{
	int position;
    cout << "After which element do you want to insert? (0 for start): ";
    cin >> position;

    // Create a new node
    Evaluation* newNode = new Evaluation;
    cout << "Enter the student name: ";
    cin.ignore();  // Ignore any leftover newline characters from previous input
    cin.getline(newNode->student, capacity);  // Use getline to accept names with spaces

    cout << "Enter the grade: ";
    cin >> newNode->grade;
    newNode->next = nullptr;

    // Inserting at the start
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Evaluation* current = head;
        for (int i = 1; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position!" << endl;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    ++number;
    return head;  // Return the updated head of the list
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* head, int& number)
{
	int position;
    cout << "Which element do you want to delete (position)? ";
    cin >> position;

    if (position <= 0 || head == nullptr) {
        cout << "Invalid position or the list is empty!" << endl;
        return head;
    }

    Evaluation* current = head;

    // Removing the first element
    if (position == 1) {
        head = head->next;
        delete current;
    } else {
        Evaluation* prev = nullptr;
        for (int i = 1; i < position && current != nullptr; ++i) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position!" << endl;
        } else {
            prev->next = current->next;
            delete current;
        }
    }

    --number;
    return head;
}



/**
*display() Function *
**/
void display(Evaluation* head)
{
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Evaluation* current = head;
    while (current != nullptr) {
        cout << "Student: " << current->student << ", Grade: " << current->grade << endl;
        current = current->next;
    }
}



/**
*average() Function *
***/
double average(Evaluation* head, int const& number)
{
	if (number == 0) {
        cout << "No students in the list to calculate average." << endl;
        return 0;
    }

    int total = 0;
    Evaluation* current = head;
    while (current != nullptr) {
        total += current->grade;
        current = current->next;
    }

    double avg = static_cast<double>(total) / number;
    cout << "The average grade is: " << avg << endl;
    return avg;
}






