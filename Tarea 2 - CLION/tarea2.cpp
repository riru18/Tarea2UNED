//
// Tarea 2 Ricardo Ruiz
// 00831 - Introducción a la programación

#include <iostream>
#include <clocale>
#include <limits>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

//Clases

struct Player {
    int id;
    string name;
    int wins;
    char symbol;
};

class Board {
public:
    Board(int rows, int columns) : grid(rows, vector<char>(columns, '-')) {}

    vector<vector<char>> grid;
};

//Prototipo de funciones
int menu ();
void registerPlayer();
void playGame(Board& board, Player& player1, Player& player2);
void playAgainstComputer();
Player* findPlayerById(int id);
void makeMove(Board &board, Player* player, char symbol);
void makeMoveComputer(Board &board, char symbol);
void printBoard(Board &board);
bool checkWinner(Board &board, char symbol);
bool isBoardFull(Board &board);

//Variables globales
Player players[10];
//vector<Player> players;
int playerCount = 0;

//Función principal
int main (){
    setlocale(LC_ALL, "Spanish"); // Permite imprimir caracteres especiales

    while(true){
        int opcion = menu();
        switch(opcion)
        {
            case 1: // Inscribir jugador
            registerPlayer();
            break;

            case 2: // Jugar partida
                playGame();
                break;

            case 3: // Jugar partida contra PC
                playAgainstComputer();
            break;

            case 4: // Resultados
                for (int i = 0; i < playerCount; ++i) {
                    cout << players[i].name << ": " << players[i].wins << endl;
                }
                break;

            case 5: // Salir del programa

                return 0;

        }
    }

}

//Funciones

void registerPlayer() {
    if (playerCount >= 10) {
        wcout << L"Se ha alcanzado el límite de jugadores. No se pueden registrar más jugadores." << endl;
        return;
    }

    Player newPlayer;

    int id;
    wcout << L"Ingrese el # de cédula del jugador (máximo 9 dígitos):  ";
    cin >> id;

    while (cin.fail() || id < 0 || id > 999999999) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        wcout << L"La cédula debe ser un número entero positivo con máximo 9 dígitos. Intente de nuevo: ";
        cin >> id;
    }

    for (int i = 0; i < playerCount; ++i) {
        if (players[i].id == id) {
            wcout << L"Este número de cédula ya está en uso, intente nuevamente" << "\n" << endl;
            return;
        }
    }

    string name;
    cout << "Ingrese el nombre del jugador: ";
    cin >> name;

    newPlayer.id = id;
    newPlayer.name = name;
    newPlayer.wins = 0;

    players[playerCount] = newPlayer;
    ++playerCount;

    cout << "Jugador valido, Bienvenido al juego " << name << "\n" << endl;
}

Player* findPlayerById(int id) {
    for (int i = 0; i < playerCount; ++i) {
        if (players[i].id == id) {
            return &players[i];
        }
    }
    return nullptr;
}

void playGame(Board& board, Player& player1, Player& player2) {
    Player* currentPlayer = &player1;
    Player* otherPlayer = &player2;

    // Agrega contadores para el número de victorias
    int winsPlayer1 = 0;
    int winsPlayer2 = 0;

    while (true) {
        printBoard(board);
        makeMove(board, *currentPlayer);

        if (checkWinner(board, currentPlayer->symbol)) {
            cout << "Jugador " << currentPlayer->symbol << " gana esta ronda!\n";
            if (currentPlayer->symbol == 'C') {
                winsPlayer1++;
            } else if (currentPlayer->symbol == 'T') {
                winsPlayer2++;
            }
        }

        // Revisa si el tablero está lleno
        bool boardFull = true;
        for (const auto& row : board.grid) {
            if (any_of(row.begin(), row.end(), [](char c) { return c == '-'; })) {
                boardFull = false;
                break;
            }
        }

        if (boardFull) {
            break;
        }

        // Intercambia jugadores
        swap(currentPlayer, otherPlayer);
    }

    cout << "El juego ha terminado.\n";
    cout << "Jugador C ha ganado " << winsPlayer1 << " veces.\n";
    cout << "Jugador T ha ganado " << winsPlayer2 << " veces.\n";
}



/*void playGame() {
    // Solicitar las cédulas de los jugadores
    wcout << L"Ingrese la cédula del jugador 1: ";
    int id1;
    cin >> id1;

    wcout << L"Ingrese la cédula del jugador 2: ";
    int id2;
    cin >> id2;

    // Encontrar los jugadores
    Player* player1 = findPlayerById(id1);
    Player* player2 = findPlayerById(id2);

    // Comprobar si los jugadores están registrados
    if (player1 == nullptr) {
        wcout << L"El jugador 1 no está registrado." << endl;
        return;
    }

    if (player2 == nullptr) {
        wcout << L"El jugador 2 no está registrado." << endl;
        return;
    }

    // Crear un nuevo tablero
    Board board(8, 8);

    // Asignar los símbolos a los jugadores
    char symbol1 = 'C';
    char symbol2 = 'T';

    while (true) {
        // Turno del jugador 1
        makeMove(board, player1, symbol1);
        if (checkWinner(board, symbol1)) {
            cout << "Felicidades " << player1->name << ", has ganado la partida." << endl;
            player1->wins++;
            break;
        } else if (isBoardFull(board)) {
            cout << "La partida ha terminado en empate." << endl;
            break;
        }

        // Turno del jugador 2
        makeMove(board, player2, symbol2);
        if (checkWinner(board, symbol2)) {
            cout << "Felicidades " << player2->name << ", has ganado la partida." << endl;
            player2->wins++;
            break;
        } else if (isBoardFull(board)) {
            cout << "La partida ha terminado en empate." << endl;
            break;
        }
    }
}*/

void makeMove(Board &board, Player* player, char symbol) {
    // Imprimir el tablero
    printBoard(board);

    int row, column;

    // Solicitar y validar la fila
    while (true) {
        cout << "Jugador " << player->name << ", ingrese la fila: ";
        cin >> row;
        row--;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor inválido. Inténtelo de nuevo.\n";
        } else if (row < 0 || row >= board.grid.size()) {
            cout << "Fila fuera de rango. Inténtelo de nuevo.\n";
        } else {
            break;
        }
    }

    // Solicitar y validar la columna
    while (true) {
        cout << "Ingrese la columna: ";
        cin >> column;
        column--;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor inválido. Inténtelo de nuevo.\n";
        } else if (column < 0 || column >= board.grid[0].size()) {
            cout << "Columna fuera de rango. Inténtelo de nuevo.\n";
        } else if (board.grid[row][column] != '-') {
            cout << "La posición ya está ocupada. Inténtelo de nuevo.\n";
        } else {
            break;
        }
    }

    // Colocar la ficha en la posición
    board.grid[row][column] = symbol;
}

void printBoard(Board &board) {
    for (int row = 0; row < board.grid.size(); row++) {
        for (int column = 0; column < board.grid[row].size(); column++) {
            cout << board.grid[row][column] << " ";
        }
        cout << endl;
    }
}

bool checkWinner(Board &board, char symbol) {
    // Comprobar si hay 4 fichas en horizontal
    for (int row = 0; row < board.grid.size(); row++) {
        for (int column = 0; column < board.grid[row].size() - 3; column++) {
            if (board.grid[row][column] == symbol &&
                board.grid[row][column + 1] == symbol &&
                board.grid[row][column + 2] == symbol &&
                board.grid[row][column + 3] == symbol) {
                return true;
            }
        }
    }

    // Comprobar si hay 4 fichas en vertical
    for (int row = 0; row < board.grid.size() - 3; row++) {
        for (int column = 0; column < board.grid[row].size(); column++) {
            if (board.grid[row][column] == symbol &&
                board.grid[row + 1][column] == symbol &&
                board.grid[row + 2][column] == symbol &&
                board.grid[row + 3][column] == symbol) {
                return true;
            }
        }
    }

    // Comprobar si hay 4 fichas en diagonal
    for (int row = 0; row < board.grid.size() - 3; row++) {
        for (int column = 0; column < board.grid[row].size() - 3; column++) {
            if (board.grid[row][column] == symbol &&
                board.grid[row + 1][column + 1] == symbol &&
                board.grid[row + 2][column + 2] == symbol &&
                board.grid[row + 3][column + 3] == symbol) {
                return true;
            }
        }
    }

    // Comprobar si hay 4 fichas en diagonal inversa
    for (int row = 0; row < board.grid.size() - 3; row++) {
        for (int column = 3; column < board.grid[row].size(); column++) {
            if (board.grid[row][column] == symbol &&
                board.grid[row + 1][column - 1] == symbol &&
                board.grid[row + 2][column - 2] == symbol &&
                board.grid[row + 3][column - 3] == symbol) {
                return true;
            }
        }
    }

    return false;


}

void playAgainstComputer() {
    // Solicitar la cédula del jugador
    wcout << L"Ingrese la cédula del jugador: ";
    int id;
    cin >> id;

    // Encontrar al jugador
    Player* player = findPlayerById(id);

    // Comprobar si el jugador está registrado
    if (player == nullptr) {
        wcout << L"El jugador no está registrado." << endl;
        return;
    }

    // Crear un nuevo tablero
    Board board(8, 8);

    // Asignar los símbolos a los jugadores
    char playerSymbol = 'C';
    char computerSymbol = 'T';

    while (true) {
        // Turno del jugador
        makeMove(board, player, playerSymbol);
        if (checkWinner(board, playerSymbol)) {
            cout << "Felicidades " << player->name << ", has ganado la partida." << endl;
            player->wins++;
            break;
        } else if (isBoardFull(board)) {
            cout << "La partida ha terminado en empate." << endl;
            break;
        }

        // Turno del ordenador
        makeMoveComputer(board, computerSymbol);  // Asumo que tienes esta función
        if (checkWinner(board, computerSymbol)) {
            cout << "El ordenador ha ganado la partida." << endl;
            break;
        } else if (isBoardFull(board)) {
            cout << "La partida ha terminado en empate." << endl;
            break;
        }
    }
}

bool isBoardFull(Board &board) {
    for (int column = 0; column < board.grid[0].size(); column++) {
        if (board.grid[0][column] == '-') {
            return false;
        }
    }
    return true;
}

void makeMoveComputer(Board &board, char symbol) {
    // Imprimir el tablero
    printBoard(board);

    // Generar un número aleatorio para la columna
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, board.grid[0].size() - 1);

    int column;
    do {
        column = distr(gen);
    } while (board.grid[0][column] != '-');

    // Colocar la ficha en la columna
    for (int row = board.grid.size() - 1; row >= 0; row--) {
        if (board.grid[row][column] == '-') {
            board.grid[row][column] = symbol;
            break;
        }
    }
}

int menu() {
    int opcion = 0;

    cout << "Juego Conecta 4\n\n";
    cout << "1. Inscribir jugador\n";
    cout << "2. Jugar partida\n";
    cout << "3. Jugar partida contra PC\n";
    cout << "4. Resultados\n";
    cout << "5. Salir del programa\n\n";

    while(true) { // Bucle que se repite hasta que el usuario ingrese un número válido
        wcout << L"Ingrese una opción: ";
        cin >> opcion;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"No ha ingresado un número válido. Ingrese una opción numérica: ";
        } else if (opcion < 1 || opcion > 5) { // Si el número ingresado no está entre 1 y 5, pide al usuario que ingrese un número válido
            wcout << L"Número fuera de rango. Ingrese un número entre 1 y 5: ";
        } else {
            break; // Si el número ingresado es válido, se sale del bucle
        }
    }
    return opcion; // Retorna la opción ingresada por el usuario
}