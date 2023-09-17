#include <iostream>
#include<fstream>

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
    Player* info;
    LinkedList* next;
};

typedef LinkedList* LL; // creating typedef for easier coding
using namespace std;

const char* getPositionName(Player::Position position); // function to correct displaying position
void InitListOfPlayers(LL head, int& id); // function to add a list of player in one action
void AddNewPlayer(LL head, int& id); // function to add only one player in one action
void DeletePlayer(LL head, int id); // function to delete player by ID
void PlayerDataToConsole(Player* player); // function to display one player`s data in console
void AllPlayersToConsole(LL head); // function to display all player`s data in console
void BestForward(LL head); // function to display best forward data
void LessThanFiveGames(LL head); // function to display data about all players, that played less than five games
bool PlayerDataToFile(Player* player, FILE* file); // function to save data about player in file
void DataToFile(LL head); // function to save all player`s data to file


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


void InitListOfPlayers(LL head, int& id) {
    LL cur = head; // getting last item of LL to 'push' new player after it
    while (cur->next) {
        cur = cur->next;
    }
    while (true) {
        // menu for initialization creation new player
        cout << "Do you want to add another player? (1 - Yes, 2 - No): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // creation new player
                Player* newPlayer = new Player;
                newPlayer->id = id;
                id++;
                cout << "Last name: ";
                char* lastname = new char[36];
                cin >> lastname;
                newPlayer->lastName = lastname;
                cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 0: 
                        newPlayer->position = Player::Position::Goalkeeper; 
                        break;
                    case 1: 
                        newPlayer->position = Player::Position::Left_Back; 
                        break;
                    case 2: 
                        newPlayer->position = Player::Position::Center_Back; 
                        break;
                    case 3: 
                        newPlayer->position = Player::Position::Right_Back; 
                        break;
                    case 4: 
                        newPlayer->position = Player::Position::Defensive_Midfield; 
                        break;
                    case 5: 
                        newPlayer->position = Player::Position::Central_Midfield; 
                        break;
                    case 6: 
                        newPlayer->position = Player::Position::Attacking_Midfield; 
                        break;
                    case 7: 
                        newPlayer->position = Player::Position::Right_Forward; 
                        break;
                    case 8: 
                        newPlayer->position = Player::Position::Left_Forward; 
                        break;
                    case 9: 
                        newPlayer->position = Player::Position::Striker; 
                        break;
                    default:
                        break;
                }

                cout << "Age: ";
                cin >> newPlayer->age;
                cout << "Number of games: ";
                cin >> newPlayer->games;
                cout << "Number of goals: ";
                cin >> newPlayer->goals;

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
                cout << "All players added successfully!";
                return;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

void AddNewPlayer(LL head, int& id) {
    // creation new player
    Player* new_player = new Player;
    new_player->id = id;
    id++;
    cout << "Last name: ";
    char* lastname = new char[36];
    cin >> lastname;
    new_player->lastName = lastname;
    cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
    int position;
    cin >> position;
    switch (position) {
        case 0: 
            new_player->position = Player::Goalkeeper; 
            break;
        case 1: 
            new_player->position = Player::Left_Back; 
            break;
        case 2: 
            new_player->position = Player::Center_Back; 
            break;
        case 3: 
            new_player->position = Player::Right_Back; 
            break;
        case 4: 
            new_player->position = Player::Defensive_Midfield; 
            break;
        case 5: 
            new_player->position = Player::Central_Midfield; 
            break;
        case 6: 
            new_player->position = Player::Attacking_Midfield; 
            break;
        case 7: 
            new_player->position = Player::Right_Forward; 
            break;
        case 8: 
            new_player->position = Player::Left_Forward; 
            break;
        case 9: 
            new_player->position = Player::Striker; 
            break;
        default:
            break;
    }
    cout << "Age: ";
    cin >> new_player->age;
    cout << "Number of games: ";
    cin >> new_player->games;
    cout << "Number of goals: ";
    cin >> new_player->goals;

    LL cur = head;
    while (cur->next) { // getting last item of LL to 'push' new player after it
        cur = cur->next;
    }
    // pushing new player to the end of LL
    LL new_ll_item = new LinkedList;
    new_ll_item->info = new_player;
    new_ll_item->next = nullptr;
    cur->next = new_ll_item;
}

void DeletePlayer(LL head, int id) {
    LL cur = head->next;
    LL prev = head;
    while (cur) {
        if (cur->info->id == id) { // checking if this player needs to be removed
            prev->next = cur->next;
            delete cur->info;
            delete cur;
            return;
        }
        // going through the LL
        prev = cur;
        cur = cur->next;
    }
    // if there no player with asked id
    cout << endl << "There are no player with id " << id <<"!" << endl;
}

void PlayerDataToConsole(Player* player) { // printing all info about player to console 
    cout << "-------------------------" << endl;
    cout << "ID: " << player->id << endl;
    cout << "Last Name: " << player->lastName << endl;
    cout << "Position: " << getPositionName(player->position) << endl;
    cout << "Age: " << player->age << endl;
    cout << "Number of games: " << player->games << endl;
    cout << "Number of goals: " << player->goals << endl;
    cout << "-------------------------" << endl;
}

void AllPlayersToConsole(LL head) { // going through LL and call PlayerDataToConsole to pring data about everyone
    LL cur = head->next;
    cout << endl << endl << "Data about all players:" << endl;
    while (cur) {
        PlayerDataToConsole(cur->info);
        cur=cur->next;
    }
} 

bool PlayerDataToFile(Player* player, FILE* file) { // writing data about chosen player in the file
    size_t isWritten = fwrite(player, sizeof(Player), 1, file);

    if (isWritten == 1) {
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
        Player* player = cur->info;
        if (!PlayerDataToFile(player, file)) {
            return;
        }
        cur = cur->next;
    }
    fclose(file);
    cout << "Players data successfully written to file.";
}

void BestForward(LL head) {
    LL cur = head->next;
    int max_goals = 0;
    Player* best_forward = new Player;
    best_forward = nullptr;
    while (cur) { // going through LL and compare forwards to choose the best
        if (cur->info->position == Player::Position::Left_Forward || cur->info->position == Player::Position::Right_Forward) {
            if (cur->info->goals > max_goals) {
                best_forward = cur->info;
                max_goals = best_forward->goals;
            }
        }
        cur = cur->next;
    }
    if (best_forward) { // if we have at least one forward
        cout << endl << endl << "Data about best forward:" << endl; 
        PlayerDataToConsole(best_forward);
    } else { // if no forwards in LL
        cout << endl << endl << "There are no forwards." << endl;
    }
}

void LessThanFiveGames(LL head) {
    LL cur = head->next;
    cout << endl << endl << "Data about players with less than 5 games:" << endl;
    while (cur) { // going through LL and printing data about players that played less than five games
        if (cur->info->games < 5) {
            PlayerDataToConsole(cur->info); 
        }
        cur = cur->next;
    }
}

int main() {
    LL head = new LinkedList;
    head->info = nullptr;
    head->next = nullptr;
    int id = 1;
    bool flag = true;
    
    // menu for user
    while(flag) {
        cout << endl;
        cout << "MENU:" << endl;
        cout << "1. Add a list of players" << endl;
        cout << "2. Add one player" << endl;
        cout << "3. Delete player by ID" << endl;
        cout << "4. Info about all players" << endl;
        cout << "5. Info about players with less than 5 games" << endl;
        cout << "6. Info about best forward" << endl;
        cout << "7. Write players to file" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                InitListOfPlayers(head, id);
                break;
            case 2:
                AddNewPlayer(head, id);
                break;
            case 3:
                cout << "Enter ID:" << endl;
                int id_to_delete;
                cin >> id_to_delete;
                DeletePlayer(head, id_to_delete);
                break;
            case 4:
                AllPlayersToConsole(head);
                break;
            case 5:
                LessThanFiveGames(head);
                break;
            case 6:
                BestForward(head);
                break;
            case 7:
                DataToFile(head);
                break;
            case 8:
                cout << endl << "Thank you for using our program!";
                flag = false;
                break;
            default:
                cout << "Invalide choice.";
                break;
        }
    }


    while (head) {
        LL temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}