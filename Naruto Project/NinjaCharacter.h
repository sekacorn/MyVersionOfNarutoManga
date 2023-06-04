// Authour: Sekacorn

#ifndef NINJACHARACTER_H
#define NINJACHARACTER_H

#include <iostream>
#include <vector>
#include "NinjaInterface.h"

// Naruto class inheriting from Ninja
class Naruto : public Ninja {
public:
    void DisplayInformation() override {
        std::cout << "Naruto Uzumaki\n";
        std::cout << "Clan: " << GetClan() << "\n";
        std::cout << "Village: " << GetVillage() << "\n";

        std::cout << "Philosophies:\n";
        for (const auto& philosophy : GetPhilosophies()) {
            std::cout << "- " << philosophy << "\n";
        }

        std::cout << "Ninja Techniques:\n";
        for (const auto& technique : GetNinjaTechniques()) {
            std::cout << "- " << technique << "\n";
        }
    }
};

// Sasuke class inheriting from Ninja
class Sasuke : public Ninja {
public:
    void DisplayInformation() override {
        std::cout << "Sasuke Uchiha\n";
        std::cout << "Clan: " << GetClan() << "\n";
        std::cout << "Village: " << GetVillage() << "\n";

        std::cout << "Philosophies:\n";
        for (const auto& philosophy : GetPhilosophies()) {
            std::cout << "- " << philosophy << "\n";
        }

        std::cout << "Ninja Techniques:\n";
        for (const auto& technique : GetNinjaTechniques()) {
            std::cout << "- " << technique << "\n";
        }
    }
};

#endif // NINJACHARACTER_H
