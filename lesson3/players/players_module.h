#include<fstream>
#ifndef PLAYERS_MODULE_H
#define PLAYERS_MODULE_H


// struct of player
struct Player {
    enum Position {
        Goalkeeper,
        Left_Back,
        Center_Back,
        Right_Back,
        Defensive_Midfield,
        Central_Midfield,
        Attacking_Midfield,
        Right_Forward,
        Left_Forward,
        Striker,
    };

    int id;
    const char* lastName;
    Position position;
    int age;
    int games;
    int goals;
};

// struct of or LL (Linked List)
struct LinkedList {
    Player info;
    LinkedList* next;
};

typedef LinkedList* LL; // creating typedef for easier coding

const char* getPositionName(Player::Position position); // function to correct displaying position
int numberOfItemsInLL(LL head); // function to get number of players
void addListOfPlayersToLL(LL head, int& id); // function to add a list of players in one function call
void addPlayerToTheEnd(LL head, int& id); // function to add one player to the end of the LL
void addPlayerBeforeChosen(LL head, int& id, int number); // function to add one player before chosen
void addPlayerAfterChosen(LL head, int& id, int number); // function to add one player after chosen
void deletePlayerByID(LL head, int id); // function to delete player by ID
void playerDataToConsole(Player player, int counter = 0); // function to print data about one player
void allPlayersToConsole(LL head); // function to print all data about players
void lessThanFiveGames(LL head); // function to print data about players, who played less than five games
void bestForwardInfo(LL head); // function to print data about best forward
bool PlayerDataToFile(Player player, FILE* file); // function to write to the opened file data about one player
void DataToFile(LL head); // function to write all players data in file, which opened here

#endif 