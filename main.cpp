//COMSC 210 | Lab 21 | Alexander Sierra
#include <iostream>
using namespace std;

const int SIZE = 15;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[SIZE]={"Daisy", "Clover", "Pepper",
    "Luna", "Rocky", "Maple", "Willow", "Rusty",
    "Jasper", "Olive", "Scout", "Ginger", "Thor",
    "Bella", "Milo"};
    string colors[SIZE]={"White", "Black", "Brown",
    "Gray", "Cream", "Tan", "Golden", "Chocolate",
    "Silver", "Spotted", "Speckled", "Black and White",
    "Brown and White", "Red", "Sandy"};
public:
    Goat() {

    }

};

int main() {
    srand(time(0));
    
    return 0;
}