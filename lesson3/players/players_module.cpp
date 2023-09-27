#include <iostream>
#include "players_module.h"

using namespace std;


const char* getPositionName(Player::Position position) {
    switch (position) {
        case Player::Goalkeeper:
            return "Goalkeeper";
        case Player::Left_Back:
            return "Left Back";
        case Player::Center_Back:
            return "Center Back";
        case Player::Right_Back:
            return "Right Back";
        case Player::Defensive_Midfield:
            return "Defensive Midfield";
        case Player::Central_Midfield:
            return "Central Midfield";
        case Player::Attacking_Midfield:
            return "Attacking Midfield";
        case Player::Right_Forward:
            return "Right Forward";
        case Player::Left_Forward:
            return "Left Forward";
        case Player::Striker:
            return "Striker";
        default:
            return "Unknown";
    }
}

int numberOfItemsInLL(LL head) {
    int counter = 0;
    LL cur = head->next;
    while (cur) { // going through LL and count how many players here
        counter++;
        cur = cur->next;
    }
    return counter;
}

void addListOfPlayersToLL(LL head, int& id) {
    LL cur = head; // getting last item of LL to 'push' new player after it
    while (cur->next) {
        cur = cur->next;
    }
    bool flag = true;
    while (flag) {
        cout << "Do you want to add new player?\n1 - Yes\n2 - No\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                // creation of new player
                Player newPlayer;
                newPlayer.id = id;
                id++;
                cout << "Last name: ";
                char* lastname = new char[36];
                cin >> lastname;
                newPlayer.lastName = lastname;
                cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 0: 
                        newPlayer.position = Player::Position::Goalkeeper; 
                        break;
                    case 1: 
                        newPlayer.position = Player::Position::Left_Back; 
                        break;
                    case 2: 
                        newPlayer.position = Player::Position::Center_Back; 
                        break;
                    case 3: 
                        newPlayer.position = Player::Position::Right_Back; 
                        break;
                    case 4: 
                        newPlayer.position = Player::Position::Defensive_Midfield; 
                        break;
                    case 5: 
                        newPlayer.position = Player::Position::Central_Midfield; 
                        break;
                    case 6: 
                        newPlayer.position = Player::Position::Attacking_Midfield; 
                        break;
                    case 7: 
                        newPlayer.position = Player::Position::Right_Forward; 
                        break;
                    case 8: 
                        newPlayer.position = Player::Position::Left_Forward; 
                        break;
                    case 9: 
                        newPlayer.position = Player::Position::Striker; 
                        break;
                    default:
                        break;
                }

                cout << "Age: ";
                cin >> newPlayer.age;
                cout << "Number of games: ";
                cin >> newPlayer.games;
                cout << "Number of goals: ";
                cin >> newPlayer.goals;

                // adding player to LL
                LL new_ll_item = new LinkedList;
                new_ll_item->info = newPlayer;
                new_ll_item->next = nullptr;
                cur->next = new_ll_item;
                cur = new_ll_item;

                cout << "Player added." << endl;
                break;
            }
            case 2:
                flag = false;
                cout << "All players have been added successfully.";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}

void addPlayerToTheEnd(LL head, int& id) {
    LL cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    
    // creation of new player
    Player new_player;
    new_player.id = id;
    id++;
    cout << "Last name: ";
    char* lastname = new char[36];
    cin >> lastname;
    new_player.lastName = lastname;
    cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:
            new_player.position = Player::Position::Goalkeeper; 
            break;
        case 1:
            new_player.position = Player::Position::Left_Back; 
            break;
        case 2:
            new_player.position = Player::Position::Center_Back; 
            break;
        case 3:
            new_player.position = Player::Position::Right_Back; 
            break;
        case 4:
            new_player.position = Player::Position::Defensive_Midfield; 
            break;
        case 5:
            new_player.position = Player::Position::Central_Midfield; 
            break;
        case 6:
            new_player.position = Player::Position::Attacking_Midfield; 
            break;
        case 7:
            new_player.position = Player::Position::Right_Forward; 
            break;
        case 8:
            new_player.position = Player::Position::Left_Forward; 
            break;
        case 9:
            new_player.position = Player::Position::Striker; 
            break;
        default:
            break;
    }

    cout << "Age: ";
    cin >> new_player.age;
    cout << "Number of games: ";
    cin >> new_player.games;
    cout << "Number of goals: ";
    cin >> new_player.goals;

    // adding new player to LL 
    LL new_ll_item = new LinkedList;
    new_ll_item->info = new_player;
    new_ll_item->next = nullptr;
    cur->next = new_ll_item;

    cout << endl <<"Player added successfully" << endl << endl;
}

void addPlayerBeforeChosen(LL head, int& id, int number) {
    LL cur = head;
    while (number > 1) {
        cur = cur->next;
        number--;
    }

    // creation of new player
    Player new_player;
    new_player.id = id;
    id++;
    cout << "Last name: ";
    char* lastname = new char[36];
    cin >> lastname;
    new_player.lastName = lastname;
    cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:
            new_player.position = Player::Position::Goalkeeper; 
            break;
        case 1:
            new_player.position = Player::Position::Left_Back; 
            break;
        case 2:
            new_player.position = Player::Position::Center_Back; 
            break;
        case 3:
            new_player.position = Player::Position::Right_Back; 
            break;
        case 4:
            new_player.position = Player::Position::Defensive_Midfield; 
            break;
        case 5:
            new_player.position = Player::Position::Central_Midfield; 
            break;
        case 6:
            new_player.position = Player::Position::Attacking_Midfield; 
            break;
        case 7:
            new_player.position = Player::Position::Right_Forward; 
            break;
        case 8:
            new_player.position = Player::Position::Left_Forward; 
            break;
        case 9:
            new_player.position = Player::Position::Striker; 
            break;
        default:
            break;
    }

    cout << "Age: ";
    cin >> new_player.age;
    cout << "Number of games: ";
    cin >> new_player.games;
    cout << "Number of goals: ";
    cin >> new_player.goals;

    // adding player to LL
    LL new_ll_item = new LinkedList;
    new_ll_item->info = new_player;
    new_ll_item->next = cur->next;
    cur->next = new_ll_item;
}

void addPlayerAfterChosen(LL head, int& id, int number) {
    LL cur = head;
    while (number > 0) {
        cur = cur->next;
        number--;
    }
    // creation of new player
    Player new_player;
    new_player.id = id;
    id++;
    cout << "Last name: ";
    char* lastname = new char[36];
    cin >> lastname;
    new_player.lastName = lastname;
    cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:
            new_player.position = Player::Position::Goalkeeper; 
            break;
        case 1:
            new_player.position = Player::Position::Left_Back; 
            break;
        case 2:
            new_player.position = Player::Position::Center_Back; 
            break;
        case 3:
            new_player.position = Player::Position::Right_Back; 
            break;
        case 4:
            new_player.position = Player::Position::Defensive_Midfield; 
            break;
        case 5:
            new_player.position = Player::Position::Central_Midfield; 
            break;
        case 6:
            new_player.position = Player::Position::Attacking_Midfield; 
            break;
        case 7:
            new_player.position = Player::Position::Right_Forward; 
            break;
        case 8:
            new_player.position = Player::Position::Left_Forward; 
            break;
        case 9:
            new_player.position = Player::Position::Striker; 
            break;
        default:
            break;
    }

    cout << "Age: ";
    cin >> new_player.age;
    cout << "Number of games: ";
    cin >> new_player.games;
    cout << "Number of goals: ";
    cin >> new_player.goals;

    // adding player to LL
    LL new_ll_item = new LinkedList;
    new_ll_item->info = new_player;
    new_ll_item->next = cur->next;
    cur->next = new_ll_item;
}

void deletePlayerByID(LL head, int id) {
    LL cur = head->next;
    LL prev = head;
    while (cur) { // going through LL and trying to find player with requiered ID
        if (cur->info.id == id) { // is player successfully found - removing him
            prev->next = cur->next;
            cout << "Player deleted successfully!";
            delete cur;
            return ;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << endl << "There are no player with ID " << id << '!' << endl; // if there no player with such ID
}

void playerDataToConsole(Player player, int counter) { // printing all info about player to console 
    cout << "-------------------------" << endl;
    if (counter) { // numbering if we display everyone
        cout << "NUMBER OF PLAYER: " << counter << endl;
    }
    cout << "ID: " << player.id << endl;
    cout << "Last Name: " << player.lastName << endl;
    cout << "Position: " << getPositionName(player.position) << endl;
    cout << "Age: " << player.age << endl;
    cout << "Number of games: " << player.games << endl;
    cout << "Number of goals: " << player.goals << endl;
    cout << "-------------------------" << endl;
}

void allPlayersToConsole(LL head) { // going through LL and call PlayerDataToConsole to pring data about everyone
    LL cur = head->next;
    int counter = 1;
    cout << endl << endl << "Data about all players:" << endl;
    while (cur) { // going through LL and calling function to output for each player
        playerDataToConsole(cur->info, counter++);
        cur=cur->next;
    }
}

void lessThanFiveGames(LL head) {
    LL cur = head->next;
    int counter = 0;
    cout << endl << endl << "Data about players that played less than five games:" << endl;
    while (cur) { // going through LL and trying to find requiered players
        if (cur->info.games < 5) { // if less than five games - display it
            playerDataToConsole(cur->info);
            counter++;
        }
        cur = cur->next;
    }
    if (!counter) { // if there no players to display
        cout << "There are no players who played less than five games." << endl << endl;
    }
}

void bestForwardInfo(LL head) {
    LL cur = head->next;
    Player best_forward;
    best_forward.goals = -1;
    cout << endl << endl << "Data about best forward:" << endl;
    while (cur) { // going through LL and compare each forwards to find best one
        if (cur->info.position == Player::Position::Left_Forward || cur->info.position == Player::Position::Right_Forward) {
            if (cur->info.goals > best_forward.goals) {
                best_forward = cur->info;
            }
        }
        cur = cur->next;
    }
    if (best_forward.goals == -1) { // if there no forwards at all
        cout << "There are no forwards." << endl << endl;
    } else {
        playerDataToConsole(best_forward);
    }
}

bool PlayerDataToFile(Player player, FILE* file) { // writing data about chosen player in the file
    Player* player_to_file = &player;
    size_t is_written = fwrite(player_to_file, sizeof(Player), 1, file);

    if (is_written == 1) {
        return true;
    } else {
        return false;
    }
}

void DataToFile(LL head) {
    FILE* file = fopen("players.bin", "wb"); // trying to open file
    if (!file) { // if can not open file
        cerr << "Unable to open the file 'players.bin' for writing." << endl;
        return;
    }
    LL cur = head->next;
    while(cur) { // going through LL to write data in the file about everyone
        Player player = cur->info;
        if (!PlayerDataToFile(player, file)) {
            cout << endl << "Error writing player data to file" << endl << endl;
            return;
        }
        cur = cur->next;
    }
    fclose(file);
    cout << "Players data successfully written to file.";
}