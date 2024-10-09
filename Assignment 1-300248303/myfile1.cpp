#include "myfile1.h"

int main() {
    // Display sizes 
    cout << "Size in bytes of a character: " << sizeof(char) << endl;
    cout << "Size in bytes of an Integer: " << sizeof(int) << endl;
    cout << "Size in bytes of a float: " << sizeof(float) << endl;
    cout << "Size in bytes of a double: " << sizeof(double) << endl;
    cout << "Size in bytes of a short Integer: " << sizeof(short int) << endl;
    cout << "Size in bytes of an unsigned Integer: " << sizeof(unsigned int) << endl;

    // Declare variables
    int integerValue;
    float realValue;
    char characterValue;

    // Prompt input
    cout << "Enter an Integer: ";
    cin >> integerValue;

    cout << "number in decimal: " << integerValue << endl;
    cout << "number in octal: " << oct << integerValue << endl;
    cout << "number in hexa: " << hex << integerValue << endl;
    cout << endl;
    // Reset 
    cout << dec;

    // Another way 
    printf("number in decimal (alternative): %d\n", integerValue);
    printf("number in octal (alternative): %o\n", integerValue);
    printf("number in hexa (alternative): %x\n", integerValue);

    // Reset f
    cout << dec << noshowbase;

    cout << "Enter a real number: ";
    cin >> realValue;

    // Display the real number with and without scientific notation 
    cout << fixed << setprecision(3) << "Without scientific notation: " << realValue << endl;
    cout << scientific << "With scientific notation: " << realValue << endl;

    // Reset 
    cout.unsetf(ios::fixed | ios::scientific);
    cout.precision(6);

    // Input character
    cout << "Enter a character: ";
    cin >> characterValue;

    // Display the character and its ASCII value
    cout << "Character: " << characterValue << endl;
    cout << "Decimal value of character: " << static_cast<int>(characterValue) << endl;

    return 0;
}
