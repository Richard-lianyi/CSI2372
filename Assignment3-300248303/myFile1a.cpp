/*Ex1a - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card{
	Color color;
	Face face;
};

// Function to display the name of the color (suit)
string getColorName(Color color) {
	switch (color) {
		case club: return "Club";
		case diamond: return "Diamond";
		case spades: return "Spades";
		case heart: return "Heart";
		default: return "Unknown";
	}
}

// Function to display the name of the face value
string getFaceName(Face face) {
	switch (face) {
		case seven: return "7";
		case eight: return "8";
		case nine: return "9";
		case ten: return "10";
		case jack: return "Jack";
		case queen: return "Queen";
		case king: return "King";
		case ace: return "Ace";
		default: return "Unknown";
	}
}

int main2(){
	Card game[32];
	//YOUR CODE HERE

	// Initialize the deck
    int index = 0;
    for (int c = club; c <= heart; ++c) {  // Loop through suits
        for (int f = seven; f <= ace; ++f) {  // Loop through face values
            game[index].color = static_cast<Color>(c);
            game[index].face = static_cast<Face>(f);
            index++;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 32; ++i) {
        cout << "Card " << i + 1 << ": Suit " << game[i].color << ", Face " << game[i].face << endl;
    }
	////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
	
}

