// Author: Sekacorn

#include <iostream>
#include "NinjaCharacter.h"
#include "OracleDatabaseConnection.h"

int main() {
    // Naruto object
    NinjaCharacter naruto;
    naruto.SetName("Naruto Uzumaki");
    naruto.SetClan("Uzumaki Average Clan");
    naruto.SetVillage("Leaf Village");
    naruto.AddPhilosophy("Love, Friendship, Ramen");
    naruto.AddPhilosophy("I never throw in the towel, mate");
    naruto.AddPhilosophy("Come back to the Village, mate");
    naruto.AddPhilosophy("Sassukkeeee!");
    naruto.AddNinjaTechnique("Rasengan");
    naruto.AddNinjaTechnique("Multi Shadow Clone Jutsu! And another one! Multi Shadow Clone Jutsu!");
    naruto.AddNinjaTechnique("Talk Jutsu!! Try to recover from that, mate.");

    // Sasuke object
    NinjaCharacter sasuke;
    sasuke.SetName("Sasuke Uchiha");
    sasuke.SetClan("Uchiha Swag Clan");
    sasuke.SetVillage("Leaf Village");
    sasuke.AddPhilosophy("Revenge and only revenge. That's the way to live.");
    sasuke.AddPhilosophy("Nah Nah, mate. I have to take care of unfinished emotions with Big Bro.");
    sasuke.AddPhilosophy("Naruutooo!");
    sasuke.AddNinjaTechnique("Chidori!!!!!");
    sasuke.AddNinjaTechnique("Amaterasu!! Hot enough for ya, mate.");

    // Showing off information about both Naruto and Sasuke objects
    naruto.DisplayInformation();
    std::cout << "\n";
    sasuke.DisplayInformation();

    // Establishing the database connection in case more power is needed for both objects to dance
    OracleDatabaseConnection dbConnection;
    dbConnection.ConnectToDatabase();

    return 0;
}
