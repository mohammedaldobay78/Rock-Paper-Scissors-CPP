#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enChoice {Paper = 1 , Stone = 2 , Scissor = 3};
enum enGameResult {Win = 1 , Loss = 2 , Drow = 3 };


int ReadPositiveNumber(string massage) {
    int Num;
    do
    {
        cout << massage << endl;
		cin >> Num;
    } while (Num < 1 || Num > 3);

    return Num;
}


int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}


int UserChoice() {
	return ReadPositiveNumber("[1] Paper  [2] Stone  [3] Scissor \nChoose a Number: ");
}


int ComputerChoice() {
	return RandomNumber(1, 3);
}


int NumberOfRounds() {
	int Num_Round;

	cout << "How Many Round Do You Want: ";
	cin >> Num_Round;

	return Num_Round;
}


enGameResult GetRoundOutCome(int User_Choice , int Computer_Choice) {
	if (User_Choice == Computer_Choice)
		return enGameResult::Drow;

	else if ((User_Choice == enChoice::Paper && Computer_Choice == enChoice::Stone) || (User_Choice == enChoice::Scissor && Computer_Choice == enChoice::Paper) || (User_Choice == enChoice::Stone && Computer_Choice == enChoice::Scissor))
		return enGameResult::Win;

	else
		return enGameResult::Loss;
}


string GetChoiceName(int Choice) {
	switch (Choice) {
		case enChoice::Paper :
			return "Paper";
			break;

		case enChoice::Scissor:
			return "Scissor";
			break;

		case enChoice::Stone:
			return "Stone";
			break;

		default:
			return "UNKNOUN!";
	}
}


void PrintRoundOutcome(enGameResult Round_Outcome , int User_Choice , int Computer_Choice) {
	cout << "\n Player Choose : " << GetChoiceName(User_Choice) << endl;
	cout << " Computer Choose : " << GetChoiceName(Computer_Choice) << endl;
	
	if (Round_Outcome == enGameResult::Win)
		cout << "Player WIN" << endl;
		
	else if (Round_Outcome == enGameResult::Loss) 
		cout << "Computer Win" << endl;

	else 
		cout << "Drow" << endl;
	
		
}


void CountOfGameOutcome(enGameResult Round_Outcome , int& User_Point , int& Computer_Point , int& Draw_Point) {
	if (Round_Outcome == enGameResult::Win)
		User_Point++;

	else if (Round_Outcome == enGameResult::Loss)
		Computer_Point++;

	else
		Draw_Point++;
}


void PlayRound(int& User_Point, int& Computer_Point, int& Draw_Point) {
	int User_Choice = UserChoice();
	int Computer_Choice = ComputerChoice();

	enGameResult GameResult = GetRoundOutCome(User_Choice, Computer_Choice);

	PrintRoundOutcome(GameResult,User_Choice,Computer_Choice);
	CountOfGameOutcome(GameResult, User_Point, Computer_Point, Draw_Point);
}


void Rounds(int Num_Round , int& User_Point , int& Computer_Point , int& Draw_Point) {

	for (int i = 1; i <= Num_Round; i++)
	{
		cout << "\n\t-----Round [" << i << "]-----\t" << endl;
		PlayRound(User_Point, Computer_Point, Draw_Point);
		cout << endl;

	}

}


void PrintGameResult(int Num_Round , int User_Point, int Computer_Point, int Draw_Point) {
	if (User_Point > Computer_Point)
	{
		cout << "\n\t--------------------------------------------------\n";
		cout << "\t\t + + + Y O U   W I N + + +\t\n";
		cout << "\n\t--------------------------------------------------\n";
		cout << "\n\t------------------[ Game Results ]----------------\n";
		cout << "\tGame Rounds : " << Num_Round << endl;
		cout << "\t" << "Player" << " : " << User_Point << endl;
		cout << "\tComputer : " << Computer_Point << endl;
		cout << "\tDraw : " << Draw_Point << endl;
		cout << "\n\t--------------------------------------------------\n" << endl;
	}
	else if (User_Point < Computer_Point)
	{
		cout << "\n\t--------------------------------------------------\n";
		cout << "\t\t + + + G a m e   O v e r + + +\t\n";
		cout << "\n\t--------------------------------------------------\n";
		cout << "\n\t------------------[ Game Results ]----------------\n";
		cout << "\tGame Rounds : " << Num_Round << endl;
		cout << "\t" << "Player" << " : " << User_Point << endl;
		cout << "\tComputer : " << Computer_Point << endl;
		cout << "\tDraw : " << Draw_Point << endl;
		cout << "\n\t--------------------------------------------------\n" << endl;
	}
	else if (User_Point == Computer_Point) {
		cout << "\n\t--------------------------------------------------\n";
		cout << "\t\t + + + D R A W + + +\t\n";
		cout << "\n\t--------------------------------------------------\n";
		cout << "\n\t------------------[ Game Results ]----------------\n";
		cout << "\tGame Rounds : " << Num_Round << endl;
		cout << "\t" << "Player" << " : " << User_Point << endl;
		cout << "\tComputer : " << Computer_Point << endl;
		cout << "\tDraw : " << Draw_Point << endl;
		cout << "\n\t--------------------------------------------------\n" << endl;
	}
}


void StartGame() {
	bool startGame = true;

	while (startGame) {
		int Num_Round = NumberOfRounds();

		int User_Point = 0, Computer_Point = 0, Draw_Point = 0;

		Rounds(Num_Round, User_Point , Computer_Point, Draw_Point);

		PrintGameResult(Num_Round, User_Point, Computer_Point, Draw_Point);
		

		char ReStart;
		cout << "\tDo you want play again? [y]/[n]: ";
		cin >> ReStart;

		if (ReStart == 'N' || ReStart == 'n')
			startGame = false;

		else if (ReStart == 'Y' || ReStart == 'y')
			system("cls");

		else
			cout << "Please Enter [y]/[n]: ";
	}

}


int main() {
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}