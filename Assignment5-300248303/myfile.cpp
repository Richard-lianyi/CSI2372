//
// Created by liany on 2024-11-05.
//
#include <iostream>
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

using namespace std;

int main() {
    CardsSet packet;                // Common deck of cards
    Player you(packet, false);       // User player
    Player me(packet, true);         // Computer player
    char answer[3];                  // To hold user response for new game prompt
    bool continuous = true;

    cout << "Hello! " << endl;

    while (continuous) {
        cout << "A new game? (y/n) " << endl;
        cin >> answer;
        continuous = answer[0] == 'y';

        if (continuous) {
            packet.novSet();         // Initialize a new deck of 52 cards
            packet.shuffle();        // Shuffle the deck

            int p1 = you.play();     // User plays first

            if (p1 > 21) {
                cout << "You lost! " << endl;
            }
            else if (p1 == 21) {
                cout << "You won! " << endl;
            }
            else {                    // Computer’s turn to play
                int p2 = me.play();

                if (p2 <= 21 && p2 >= p1) {
                    cout << "You lost! " << endl;
                }
                else {
                    cout << "You won! " << endl;
                }
            }
        }
    }
    return 0;
}
