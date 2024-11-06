//
// Created by liany on 2024-11-05.
//

#include <iostream>
using namespace std;
#include <cassert> //for assert()

enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
};

/*Constructor*/
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}
void Card::write() {
    // Display color
    switch (col) {
        case club:    std::cout << "Club ";    break;
        case diamond: std::cout << "Diamond "; break;
        case heart:   std::cout << "Heart ";   break;
        case spade:   std::cout << "Spade ";   break;
    }

    // Display value
    if (val == 1)
        std::cout << "Ace";
    else if (val == 11)
        std::cout << "Jack";
    else if (val == 12)
        std::cout << "Queen";
    else if (val == 13)
        std::cout << "King";
    else
        std::cout << val;

    std::cout << std::endl;
}