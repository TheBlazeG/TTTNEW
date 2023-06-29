   // TTTNEW.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include<cstdlib>
#include <string>
#include<algorithm>
using namespace std;
const int NUM_SQUARES= 9;
const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';
const char TIE = 'T';
void instructions(vector<char>board);
char humanSymbol();
char opponent(char player);
char winner(const vector<char>& board);
void displayboard(const vector<char>& board);
int askNumber(string question, int high, int low);
int playermove(const vector<char>& board);
bool validspace(const vector<char>& board, int number);
char randomSel(char hope);
inline bool isLegal(int move, const vector<char>& board);
int humanMove(const vector<char>& board);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char human, char computer);
int main()
{


int move;
vector<char> board (NUM_SQUARES, EMPTY);
instructions(board);
char player = humanSymbol();
char computer = opponent(player);
char turn = X;



while (winner(board)==NO_ONE)
{
	if (turn == player)
{
	move = playermove(board);
	board[move] = player;
	displayboard(board);

}
	else
	{
		move = computerMove(board, computer);
		displayboard(board);
	}
}
announceWinner(winner(board), player, computer);
}

void instructions(vector<char>board)
{
	cout << "Bienvenido Mago del Mango, elige una posicion entre 0 y 8 para vencer al antima(n)go" << endl;
	cout << "|0|1|2|\n|3|4|5|\n|6|7|8|";
}
char AskYesNo(string question)
{
    char answer;
    do
    {
        cout << "\n" << question << "(y/n)" << endl;
        cin >> answer;
    } while (answer != 'y' && answer != 'n');
	return answer;
}
char humanSymbol()
{
	char goFirst = AskYesNo("Quieres comenzar?");
	goFirst=randomSel(goFirst);
	if (goFirst=='y')
	{
		cout << "vas X" << endl;
		return X;
		
	}
	else
	{
		cout << "vas O" << endl;
		return O;
		
	}
}
char opponent(char player)
{
	if (player==X)
	{
		return O;
	}
	else 
	{
		return X;
	}
}

char winner(const vector<char> &board)
{
	const int WINNING_POS[8][3] = { {0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{2,4,6}, 
		{0,4,8}};
	const int TOTAL_ROWS = 8;

	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_POS[row][0]]!= EMPTY) &&
			(board[WINNING_POS[row][0]]==board[WINNING_POS[row][1]]) &&
			(board[WINNING_POS[row][1]]==board[WINNING_POS[row][2]]))
		{
			return board[WINNING_POS[row][0]];
		}
	}
	if (count(board.begin(),board.end(),EMPTY)==0)
	{
		return TIE;
	}

	return NO_ONE;
}
void displayboard(const vector<char>& board)
{
	cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << "\n|" << board[3] << "|" << board[4] << "|" << board[5] << "|\n" << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|";
}
int playermove(const vector<char>& board)
{
	bool valid;
	int number;
	do
	{
		number = askNumber("Elige un espacio", 8, 0);
		valid = validspace(board, number);
		
	} while (!valid);
	cout << "yay\n";
	return number;
}
int askNumber(string question, int high, int low)
{
	string input;
	bool isValid = false;
	bool isRangeValid = false;
	int number = 0;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	do {
		cout << question << "entre " << low << " y " << high << endl;

		getline(cin, input);

		for (char c : input)
		{
			if (!isdigit(c))
			{
				isValid = false;
				break;
			}
			else
			{
				isValid = true;
				break;
			}
		}

		if (!isValid)
		{
			cout << "\nEntrada inválida, por favor elige solo números.\n";
		}
		else
		{
			number = stoi(input);
			isRangeValid = number <= high && number >= low;
		}

		if (!isRangeValid && isValid)
		{
			cout << "\nEntrada inválida, elige un número dentro del rango establecido.\n";
		}

	} while (!isValid || input.empty() || !isRangeValid);

	return number;
}
bool validspace(const vector<char>& board,int number)
{
	if (board[number]==EMPTY)
	{
		return true;
	}
	else
	{
		cout << "Espacio utilizado\n";
		return false;
		
	}
}
char randomSel(char hope)
{
	srand(time(NULL));
	int randomguess = rand();
	int randomresult = (randomguess % 6);
	cout << "Escoge par o impar para decidir si te hago caso..."<<endl;
	char guess=AskYesNo("Quieres par?");
	cout << "El dado fue: " << randomresult << endl;
	if (randomresult%2==0 && guess=='y')
	{
		cout << "Tendre que hacerte caso >:(" << endl;
		if (hope=='y')
		{
			return 'y';
		} 
		else
		{
			return 'n';
		}
	}
	if (randomresult % 2 != 0 && guess == 'n')
	{
		cout << "Tendre que hacerte caso >:(" << endl;
		if (hope == 'y')
		{
			return 'y';
		}
		else
		{
			return 'n';
		}
	}
	else
	{
		cout << "Mala suerte porque yo escogo al revés!" << endl;
		if (hope == 'y')
		{
			return 'n';
		}
		else
		{
			return 'y';
		}
	}
}
inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board)
{
	int move = askNumber("Elige una posicion del tablero", (board.size() - 1),0);
	while (!isLegal(move,board))
	{
		cout << "\nEsa posicion ya está ocupada humano tonto. \n";
		move = askNumber("elige una posicion del tablero", (board.size() - 1), 0);
	}

}
int computerMove(vector<char> board, char computer)
{
	int move = 0;
	bool foundSpace = false;

	while (!foundSpace && move < board.size()) {

		if (isLegal(move,board))
		{
			board[move] = computer;
			foundSpace = winner(board) == computer;
		}

		if (!foundSpace)
		{
			move++;
		}
	}

	if (!foundSpace)
	{
		move = 0;
		char human = opponent(computer);
		while (!foundSpace && move < board.size())
		{
			if (isLegal(move,board))
			{
				board[move] = human;
				foundSpace = winner(board) == human;
			}
			if (!foundSpace)
			{
				move++;
			}
		}
	}

	//find best move start on center
	if (!foundSpace)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVE[] = { 4,0,2,6,8,1,3,5,7 };
		while (!foundSpace && i<board.size())
		{
			move = BEST_MOVE[i];
			if (isLegal(move,board))
			{
				foundSpace = true;
			}
			++i;
		}
	}
	cout << "Usare la posicion " << move << endl;
	return move;
}
void announceWinner(char winner, char human, char computer) {
	if (winner == computer) {
		cout << "\nEl ganador es: " << winner << endl;
		cout << "\n Soy el ganador!! Probando una vez más que las computadoras somos mejores que ustedes en todo sentido.\n";
	}
	else if (winner == human) {
		cout << "\nEl ganador es: " << winner << endl;
		cout << "\nNo es posible!! Hiciste trampa humano!!";
	}
	else {
		cout << "\n ES UN EMPATE\n";
		cout << "\nQue suerte tienes, celébralo es lo mejor que lograrás.\n";
	}
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
