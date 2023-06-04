// Authour: Sekacorn

#ifndef NINJAINTERFACE_H
#define NINJAINTERFACE_H

#include <iostream>
#include <string>
#include <unordered_set>

// Ninja interface (base class/Blueprint)
class Ninja {
protected:
    std::string Name;
    std::string Clan;
    std::string Village;
    std::unordered_set<std::string> Philosophy;
    std::unordered_set<std::string> NinjaTechniques;

public:
    // Pure virtual function to be implemented by derived classes
    virtual void DisplayInformation() = 0;

    // Setter methods for the private members
    void SetName(const std::string& name) {
        Name = name;
    }

    void SetClan(const std::string& clan) {
        Clan = clan;
    }

    void SetVillage(const std::string& village) {
        Village = village;
    }

    // Getter methods for the private members
    std::string GetName() const {
        return Name;
    }

    std::string GetClan() const {
        return Clan;
    }

    std::string GetVillage() const {
        return Village;
    }

    // Methods to add philosophy and ninja techniques
    void AddPhilosophy(const std::string& philosophy) {
        Philosophy.insert(philosophy);
    }

    void AddNinjaTechnique(const std::string& technique) {
        NinjaTechniques.insert(technique);
    }
};

#endif // NINJAINTERFACE_H
