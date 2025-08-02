#include <iostream>
#include <random>

int main() {
    std::random_device rd;  // Seed generator
    std::mt19937 gen(rd()); // Mersenne Twister random number engine
    std::uniform_int_distribution<> distrib(10, 20); // Range: [10, 20]

    int randomNumber = distrib(gen);
    std::cout << "Random number: " << randomNumber << std::endl;

    return 0;
}
