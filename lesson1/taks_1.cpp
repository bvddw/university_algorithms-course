#include <iostream>
#include <string>

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

int InitListOfPlayers(Player* &players, int size);
const char* getPositionName(Player::Position position);
int AddNewPlayer(Player* &players, int size, int& id);
int DeleteNewPlayer(Player* &players, int size, int id);
void PlayerDataToConsole(Player player);
void BestForward(Player* players, int size);
void LessThanFiveGames(Player* players, int size);


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


int InitListOfPlayers(Player* &players, int size, int& id) {
    while (true) {
        // меню для ініціалізація одразу декількох гравців
        std::cout << "Do you want to add another player? (1 - Yes, 2 - No): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // створення гравця
                Player newPlayer;
                newPlayer.id = id;
                id++;
                std::cout << "Last name: ";
                char* lastname = new char[36];
                std::cin >> lastname;
                newPlayer.lastName = lastname;
                std::cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
                int choice;
                std::cin >> choice;
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

                std::cout << "Age: ";
                std::cin >> newPlayer.age;
                std::cout << "Number of games: ";
                std::cin >> newPlayer.games;
                std::cout << "Number of goals: ";
                std::cin >> newPlayer.goals;

                // тут ми виділяємо пам'ять для нового гравця, при цьому копіюємо старих гравців
                Player* temp = new Player[size + 1];
                for (int i = 0; i < size; ++i) {
                    temp[i] = players[i];
                }
                temp[size] = newPlayer;

                // тут ми відчищаємо з пам'яті старий масив гравців й перезаписуємо в нього новий
                delete[] players;
                players = temp;

                std::cout << "Player added." << std::endl;
                size++;
                break;
            }
            case 2:
                return size;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
}

void BestForward(Player* players, int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        if (players[i].position == Player::Right_Forward or players[i].position == Player::Left_Forward) {
            Player& best_player = players[i];
            break;
        }
    }
    Player& best_player = players[0];
    for (int i = 0; i < size; i++) {
        if (players[i].position == Player::Right_Forward or players[i].position == Player::Left_Forward) {
            Player& current_player = players[i];
            if (best_player.goals < current_player.goals) {
                best_player = current_player;
            } 
        }
    }
    std::cout << std::endl << "Best Forward: " << std::endl;
    PlayerDataToConsole(best_player);
}

void LessThanFiveGames(Player* players, int size) {
    std::cout << std::endl << "Players with less than 5 games:" << std::endl;
    for (int i = 0; i < size; i++) {
        Player& player = players[i];
        if (player.games < 5) {
            PlayerDataToConsole(player);
        }
    }
}

int AddNewPlayer(Player* &players, int size, int& id) {
    Player newPlayer;
    newPlayer.id = id;
    id++;
    std::cout << "Last name: ";
    char* lastname = new char[36];
    std::cin >> lastname;
    newPlayer.lastName = lastname;
    std::cout << "Position (0 - Goalkeeper, 1 - Left_Back, 2 - Center_Back, 3 - Right_Back, 4 - Defensive_Midfield, 5 - Central_Midfield, 6 - Attacking_Midfield, 7 - Right_Forward, 8 - Left_forward, 9 - Striker): ";
    int position;
    std::cin >> position;
    switch (position) {
        case 0: 
            newPlayer.position = Player::Goalkeeper; 
            break;
        case 1: 
            newPlayer.position = Player::Left_Back; 
            break;
        case 2: 
            newPlayer.position = Player::Center_Back; 
            break;
        case 3: 
            newPlayer.position = Player::Right_Back; 
            break;
        case 4: 
            newPlayer.position = Player::Defensive_Midfield; 
            break;
        case 5: 
            newPlayer.position = Player::Central_Midfield; 
            break;
        case 6: 
            newPlayer.position = Player::Attacking_Midfield; 
            break;
        case 7: 
            newPlayer.position = Player::Right_Forward; 
            break;
        case 8: 
            newPlayer.position = Player::Left_Forward; 
            break;
        case 9: 
            newPlayer.position = Player::Striker; 
            break;
        default:
            break;
    }
    std::cout << "Age: ";
    std::cin >> newPlayer.age;
    std::cout << "Number of games: ";
    std::cin >> newPlayer.games;
    std::cout << "Number of goals: ";
    std::cin >> newPlayer.goals;

    // тут ми виділяємо пам'ять для нового гравця, при цьому копіюємо старих гравців
    Player* temp = new Player[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = players[i];
    }
    temp[size] = newPlayer;

    // тут ми відчищаємо з пам'яті старий масив гравців й перезаписуємо в нього новий
    delete[] players;
    players = temp;

    std::cout << "Player added." << std::endl;
    return size + 1;
}

int DeleteNewPlayer(Player* &players, int size, int id) {
    int index_to_delete = -1;
    for (int i = 0; i < size; i++) {
        if (players[i].id == id) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete == -1) {
        std::cout << "Invalide choice";
        return size;
    }

    Player* temp = new Player[size - 1];
    for (int i = 0; i < index_to_delete; ++i) {
        temp[i] = players[i];
    }
    for (int i = index_to_delete + 1; i < size; ++i) {
        temp[i - 1] = players[i];
    }

    // тут ми відчищаємо з пам'яті старий масив гравців й перезаписуємо в нього новий
    delete[] players;
    players = temp;

    std::cout << "Player deleted." << std::endl;
    return size - 1;
}

void PlayerDataToConsole(Player player) {
    std::cout << "-------------------------" << std::endl;
    std::cout << "ID: " << player.id << std::endl;
    std::cout << "Last Name: " << player.lastName << std::endl;
    std::cout << "Position: " << getPositionName(player.position) << std::endl;
    std::cout << "Age: " << player.age << std::endl;
    std::cout << "Number of games: " << player.games << std::endl;
    std::cout << "Number of goals: " << player.goals << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main() {
    Player* players = nullptr;
    int numPlayers = 0, id = 1;
    bool flag = true;
    
    while(flag) {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Add a list of players" << std::endl;
        std::cout << "2. Add one player" << std::endl;
        std::cout << "3. Delete player by ID" << std::endl;
        std::cout << "4. Info about all players" << std::endl;
        std::cout << "5. Info about players with less than 5 games" << std::endl;
        std::cout << "6. Info about best forward" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                numPlayers = InitListOfPlayers(players, numPlayers, id);
                break;
            case 2:
                numPlayers = AddNewPlayer(players, numPlayers, id);
                break;
            case 3:
                std::cout << "Enter ID:" << std::endl;
                int id;
                std::cin >> id;
                numPlayers = DeleteNewPlayer(players, numPlayers, id);
                break;
            case 4:
                for (int i = 0; i < numPlayers; i++) {
                    const Player& player = players[i];
                    PlayerDataToConsole(player);
                }
                break;
            case 5:
                LessThanFiveGames(players, numPlayers);
                break;
            case 6:
                BestForward(players, numPlayers);
                break;
            case 7:
                std::cout << std::endl << "Thank you for using our program!";
                flag = false;
                break;
            default:
                std::cout << "Invalide choice.";
                break;
        }
    }


    delete[] players;

    return 0;
}