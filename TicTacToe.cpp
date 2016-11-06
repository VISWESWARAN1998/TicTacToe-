/*					SWAMI KARUPPASWAMI THUNNAI
				PROPER IMPLEMENTATION OF TIC TAC TOE IN C++14 (IN OBJECT ORIENTED STYLE)
*/


#include<iostream>
#include<string>
#include<map>
using namespace std;

class Players // Used to store the detais of the players
{
protected:
	string player1, player2; // Names of the players are stored here
	char choice1, choice2;  // either X or O
	map<int, char> Board; // the board itself
};
class TicTacToe:protected Players
{
private:
	int player_choices[9]; //arbitary value assumption see assin definition for more details
	bool winp1 = false;
	bool winp2 = false;
public:
	bool set_players(string name1, string name2,char Choice1,char Choice2); // Used to assign player details
	void board(); // display board
	void assign(); // set values
	bool check(int no,char name); // validating the input
	void update(); // used to update the board
};

bool TicTacToe::set_players(string name1, string name2, char Choice1, char Choice2)
{
	player1 = name1;
	player2 = name2;
	choice1 = Choice1;
	choice2 = Choice2;
	if (isalpha(choice1) && isalpha(choice2))
	{
		if(isupper(choice1)&&isupper(choice2))return true;
		else cout << "Upper case characters please for convineance!" << endl;
	}
	else
	{
		return false;
	}
}
// Used to display the board in the console/terminal
void TicTacToe::board()
{
	cout << "Make yourself familiar with the structure of the board" << endl;
	cout << endl;
	cout << "*-----*-----*-----*" << endl;
	cout << "|  0  |  1  |  2  |" << endl;
	cout << "*-----*-----*-----*" << endl;
	cout << "|  3  |  4  |  5  |" << endl;
	cout << "*-----*-----*-----*" << endl;
	cout << "|  6  |  7  |  8  |" << endl;
	cout << "*-----*-----*-----*" << endl;
}

bool TicTacToe::check(int no,char name) // Member Function will check whether the element is taken or not return type = boolean (bool)
{
	if ((no>=0)&&(no<=8)) {
		map<int, char>::iterator check_if_element_exists;
		check_if_element_exists = Board.find(no);
		if (check_if_element_exists != Board.end())
		{
			cout << "The value is already taken by " << check_if_element_exists->second;
			return false;
		}
		else
		{
			Board[no] = name;
			update();
			return true;
		}
	}
	else
	{
		// you may add some conditional statements for clarity
		cout << "Check the board the number is greater or lesser!" << endl;
	}
}
// This function is used to assign the values
/*
Arbitary value usage:
since I have used maps it would need an iterator to access those X and O characters
which would make code lengthy so I have came with a mathematical approach for solving this TicTacToe
by assuming an arbitary values to the players
Player1 = 20
Player2 = 10
*/
void TicTacToe::assign()
{
	for (int i = 0; i < 9; i++)
	{
		int tempVariable;
		bool surity1 = false; // This will make sure non-duplicated entry is enterd!
		bool surity2 = false;
		while (surity1 != true) {
			cout << "Player 1: Enter your no" << endl;
			cin >> tempVariable;
			bool add = check(tempVariable, choice1);
			if (add == true)
			{
				player_choices[tempVariable] = 20; // arbitary value
				surity1 = true;
			}
		}
		cout << endl << endl << "Player 2\'s Choice" << endl;
		while (surity2 != true) {
			cout << "Player 2: Enter your no" << endl;
			cin >> tempVariable;
			bool add = check(tempVariable, choice2);
			if (add == true) {
				player_choices[tempVariable] = 10; // arbitary value
				surity2 = true;
			}
		}
		//For each entry there may be winning or loosing and it must be announted!
		if ((player_choices[0] == 20) && (player_choices[1] == 20) && (player_choices[2] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else if ((player_choices[3] == 20) && (player_choices[4] == 20) && (player_choices[5] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else if ((player_choices[6] == 20) && (player_choices[7] == 20) && (player_choices[8] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		//Linear lines - Vertical
		else if ((player_choices[0] == 20) && (player_choices[3] == 20) && (player_choices[6] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else if ((player_choices[1] == 20) && (player_choices[4] == 20) && (player_choices[7] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else if ((player_choices[2] == 20) && (player_choices[7] == 20) && (player_choices[8] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		// Diagonal
		else if ((player_choices[0] == 20) && (player_choices[4] == 20) && (player_choices[8] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else if ((player_choices[2] == 20) && (player_choices[4] == 20) && (player_choices[6] == 20))
		{
			cout << "Player 1 is the Winner";
			winp1 = true;
			break;
		}
		else
		{
			cout << endl;
		}
		/*
		============================For Player 2======================================
		*/
		if ((player_choices[0] == 10) && (player_choices[1] == 10) && (player_choices[2] == 10))
		{
			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else if ((player_choices[3] == 10) && (player_choices[4] == 10) && (player_choices[5] == 10))
		{
			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else if ((player_choices[6] == 10) && (player_choices[7] == 10) && (player_choices[8] == 10))
		{
			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		//Linear lines - Vertical
		else if ((player_choices[0] == 10) && (player_choices[3] == 10) && (player_choices[6] == 10))
		{
			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else if ((player_choices[1] == 10) && (player_choices[4] == 10) && (player_choices[7] == 10))
		{
			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else if ((player_choices[2] == 10) && (player_choices[5] == 10) && (player_choices[8] == 10))
		{

			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		// Diagonal
		else if ((player_choices[0] == 10) && (player_choices[4] == 10) && (player_choices[8] == 10))
		{

			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else if ((player_choices[2] == 10) && (player_choices[4] == 10) && (player_choices[6] == 10))
		{

			cout << "Player 2 is the Winner";
			winp2 = true;
			break;
		}
		else
		{
			cout << endl;
		}
		if (i == 8) {
			if ((winp1 == false) && (winp2 == false))
			{
				cout << "Draw match!" << endl;
			}
		}
	}
}

void TicTacToe::update()
{
	// Have an eye with those manipulators any change will shakle the structure
	cout << endl;
	cout << "*-----*-----*-----*"<<endl;
	// Not interested in thinking(merely wasting time) in thinking for creating
	// a new for loop where three loop can be shotened like this for{for{}} may be if
	// you are free then you can try it :)
	for (int i = 0; i <=2; i++)// For displaying first row
	{
		map<int, char>::iterator itr;
		itr = Board.find(i);
		if (itr != Board.end())cout << "  " << itr->second << "  ";
		else cout << "     ";
	}
	cout << "\n*-----*-----*-----*" << endl;
	for (int i = 3; i <=5; i++)// For displaying first row
	{
		map<int, char>::iterator itr;
		itr = Board.find(i);
		if (itr != Board.end())cout << "  " << itr->second << "  ";
		else cout << "     ";
	}
	cout << "\n*-----*-----*-----*" << endl;
	for (int i = 6; i <=8; i++)// For displaying first row
	{
		map<int, char>::iterator itr;
		itr = Board.find(i);
		if (itr != Board.end())cout << "  " << itr->second << "  ";
		else cout << "     ";
	}
}

int main()
{
	string p1, p2;
	char c1, c2;
	TicTacToe game;
	cout << "Enter the name of the player1 :" << endl;
	getline(cin, p1);
	cout << "Enter the name of the player2 :" << endl;
	getline(cin, p2);
	cout << "Enter the choice of the player1 :" << endl;
	cin >> c1;
	cout << "Enter the choice of the player2 :" << endl;
	cin >> c2;
	bool assign_player_details;
	assign_player_details = game.set_players(p1, p2, c1, c2);
	if (assign_player_details == true)cout << endl << "All details have been assigned successfully!" << endl;
	else
	{
		cout << "\nSometing went wrong" << endl;
		return -1;
	}
	game.board();
	cout << endl << "Alright let\'s begin" << endl;
	game.assign();
	int stay; cin >> stay;
	return 0;
}