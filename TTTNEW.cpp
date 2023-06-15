// TTTNEW.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
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

int main()
{

char turn=X;
vector<char> board (NUM_SQUARES, EMPTY);
instructions(board);
char player = humanSymbol();
char computer = opponent(player);
while (winner(board)==NO_ONE)
{

}
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
	if (goFirst=='y')
	{
		return X;
	}
	else
	{
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


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
