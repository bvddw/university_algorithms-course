#include <iostream>
#include "players_module.h"
#include "players_module.cpp"

using namespace std;

int main () {
    LL head = new LinkedList;
    head->next = nullptr;
    int number_of_players = 0;
    int id = 1;
    bool flag = true;

    while (flag) { // menu for user
        number_of_players = numberOfItemsInLL(head);
        cout << endl;
        cout << "MENU:" << endl;
        cout << "1. Add a list of players" << endl;
        cout << "2. Add one player" << endl;
        if (number_of_players) {
            cout << "3. Add one player, before chosen player in list" << endl;
            cout << "4. Add one player, after chosen player in list" << endl;
            cout << "5. Delete player by ID" << endl;
            cout << "6. Info about all players" << endl;
            cout << "7. Info about players with less than 5 games" << endl;
            cout << "8. Info about best forward" << endl;
            cout << "9. Write players to file" << endl;
        } else {
            cout << "3." << endl;
            cout << "4." << endl;
            cout << "5." << endl;
            cout << "6." << endl;
            cout << "7" << endl;
            cout << "8." << endl;
            cout << "9." << endl;
        }
        cout << "0. Exit" << endl;
        int choice;
        cin >> choice;
        if (!number_of_players) { // validation choices (not only display, functoinal also)
            if (choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9) {
                choice = -1;
            }
        }
        switch (choice)
        {
        case 0:
            cout << endl << "Thank you for using our program!" << endl;
            flag = false;
            break;
        case 1:
            addListOfPlayersToLL(head, id);
            break;
        case 2:
            addPlayerToTheEnd(head, id);
            break;
        case 3:
            cout << "Enter number of player in list, before whose will be added new player: " << endl;
            int add_before_id;
            cin >> add_before_id;
            if (add_before_id > number_of_players || add_before_id < 1) {
                cout << endl << "Invalid number" << endl;
            } else {
                addPlayerBeforeChosen(head, id, add_before_id);
            }
            break;
        case 4:
        cout << "Enter number of player in list, after whose will be added new player: " << endl;
            int add_after_id;
            cin >> add_after_id;
            if (add_after_id > number_of_players || add_after_id < 1) {
                cout << endl << "Invalid number" << endl;
            } else {
                addPlayerAfterChosen(head, id, add_after_id);
            }
            break;
        case 5:
            cout << "Enter an player`s ID to delete him / her: ";
            int id_to_delete;
            cin >> id_to_delete;
            if (id_to_delete < 1) {
                cout << endl << "There are no player with ID " << id_to_delete << '!' << endl;
            } else {
                deletePlayerByID(head, id_to_delete);
            }
            break;
        case 6:
            allPlayersToConsole(head);
            break;
        case 7:
            lessThanFiveGames(head);
            break;
        case 8:
            bestForwardInfo(head);
            break;
        case 9:
            DataToFile(head);
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    }

    while(head) {
        LL temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}