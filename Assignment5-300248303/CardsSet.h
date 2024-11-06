//
// Created by liany on 2024-11-05.
//

class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};
// Method to create a new set of 52 cards (full deck)
void CardsSet::novSet() {
    number = 52;
    int idx = 0;
    for (int col = club; col <= spade; ++col) {  // Iterate over each suit
        for (int val = 1; val <= 13; ++val) {    // Iterate over each card value
            set[idx++] = Card(static_cast<color>(col), val);
        }
    }
}

// Method to shuffle the cards in the set
void CardsSet::shuffle() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator
    for (int i = 0; i < number; ++i) {
        int randIndex = rand() % number;  // Generate a random index
        // Swap cards at i and randIndex
        Card temp = set[i];
        set[i] = set[randIndex];
        set[randIndex] = temp;
    }
}

// Method to take a card from the top of the set
Card CardsSet::take() {
    assert(number > 0);  // Ensure there is at least one card to take
    return set[--number];  // Decrement number and return the top card
}

// Method to put a card on the set
void CardsSet::put(Card k) {
    assert(number < 52);  // Ensure there's space to add a card
    set[number++] = k;    // Place the card in the set and increment number
}

// Method to look at the card in a specific position (1 = top of the set)
Card CardsSet::lookIn(int no) {
    assert(no >= 1 && no <= number);  // Ensure the position is valid
    return set[no - 1];  // Return the card at the given position (1-based index)
}