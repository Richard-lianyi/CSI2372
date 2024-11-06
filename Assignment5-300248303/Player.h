//
// Created by liany on 2024-11-05.
//
#include <iostream>
#include <vector>
class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer
    (isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();
};
// Method to play by drawing cards until the player chooses to stop or exceeds 21 points
int Player::play() {
    bool drawMore = !computer; // Only the user decides; computer logic is predefined
    while (drawMore) {
        Card drawnCard = packet.take();   // Draw a card from the common deck
        inHand.put(drawnCard);            // Add the drawn card to the player's hand
        int points = countPoints();       // Calculate current points

        std::cout << "Current points: " << points << std::endl;
        drawnCard.write();                // Display the drawn card (optional, for user feedback)

        // Check if the player wants to draw more (only if it's the user)
        if (!computer) {
            std::cout << "Do you want another card? (1 for yes, 0 for no): ";
            std::cin >> drawMore;
        } else {
            // Computer logic: stop if points are 17 or higher
            drawMore = points < 17;
        }

        // Stop if points exceed 21
        if (points > 21) {
            std::cout << (computer ? "Computer" : "User") << " busts with " << points << " points." << std::endl;
            break;
        }
    }
    return countPoints();
}

// Private method to count points, treating Ace as 14 unless over 21 points
int Player::countPoints() {
    int totalPoints = 0;
    bool hasAce = false;
    for (int i = 1; i <= inHand.numCards(); ++i) {
        Card currentCard = inHand.lookIn(i);
        int cardValue = currentCard.value();

        if (cardValue == 1) {
            hasAce = true;
            totalPoints += 14; // Start by counting Ace as 14
        } else if (cardValue >= 11 && cardValue <= 13) {
            totalPoints += 10; // Face cards (Jack, Queen, King) are worth 10 points
        } else {
            totalPoints += cardValue; // All other cards retain their face value
        }
    }

    // Adjust Ace to be worth 1 if total points exceed 21
    if (totalPoints > 21 && hasAce) {
        totalPoints -= 13; // Subtract 13 to count Ace as 1 instead of 14
    }

    return totalPoints;
}