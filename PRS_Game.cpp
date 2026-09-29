#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enChoice {Paper = 1 , Stone = 2 , Scissor = 3};

string GetUserName() {
	string User_Name;
	cout << "Enter A Username: ";
	cin >> User_Name;

	return User_Name;
}

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

void PlayRound(int &User_Point , int &PC_Point , int &Draw_Point , string UserName) {
	int User_Choice = ReadPositiveNumber("Your Choice : [1]Paper , [2]Stone , [3]Scissor : ");
	int PC_Choice = RandomNumber(1,3);

	if (User_Choice == enChoice::Paper && PC_Choice == enChoice::Paper)
	{
		system("color 80");
		cout << UserName << ": " <<"Paper" << "\t | \t" << "Computer: " << "Paper" << endl;
		cout << "The Result: " << "Draw" << endl;
		Draw_Point++;
	}
	else if (User_Choice == enChoice::Paper && PC_Choice == enChoice::Stone)
	{
		cout << UserName << ": " << "Paper" << "\t | \t" << "Computer: " << "Stone" << endl;
		cout << "The Result: " << "You Win" << endl;
		User_Point++;
	}
	else if (User_Choice == enChoice::Paper && PC_Choice == enChoice::Scissor)
	{
		cout << UserName << ": " << "Paper" << "\t | \t" << "Computer: " << "Scissor" << endl;
		cout << "The Result: " << "You Lose" << endl;
		PC_Point++;
	}
	else if (User_Choice == enChoice::Scissor && PC_Choice == enChoice::Paper)
	{
		cout << UserName << ": " << "Scissor" << "\t | \t" << "Computer: " << "Paper" << endl;
		cout << "The Result: " << "You Win" << endl;
		User_Point++;
	}
	else if (User_Choice == enChoice::Scissor && PC_Choice == enChoice::Scissor)
	{
		cout << UserName << ": " << "Scissor" << "\t | \t" << "Computer: " << "Scissor" << endl;
		cout << "The Result: " << "Draw" << endl;
		Draw_Point++;
	}
	else if (User_Choice == enChoice::Scissor && PC_Choice == enChoice::Stone)
	{
		cout << UserName << ": " << "Scissor" << "\t | \t" << "Computer: " << "Stone" << endl;
		cout << "The Result: " << "You Lose" << endl;
		PC_Point++;
	}
	else if (User_Choice == enChoice::Stone && PC_Choice == enChoice::Paper)
	{
		cout << UserName << ": " << "Stone" << "\t | \t" << "Computer: " <<"Paper" << endl;
		cout << "The Result: " << "You Lose" << endl;
		PC_Point++;
	}
	else if (User_Choice == enChoice::Stone && PC_Choice == enChoice::Scissor)
	{
		cout << UserName << ": " << "Stone" << "\t | \t" << "Computer: " << "Scissor" << endl;
		cout << "The Result: " << "You Win" << endl;
		User_Point++;
	}else if (User_Choice == enChoice::Stone && PC_Choice == enChoice::Stone)
	{
		cout << UserName << ": " << "Stone" << "\t | \t" << "Computer: " << "Stone" << endl;
		cout << "The Result: " << "Draw" << endl;
		Draw_Point++;
	}else {
		cout << "UNKNOUN ERORR!" << endl;
	}
}

int NumOfRounds() {
	int Num_Round;

	cout << "How Many Round Do You Want 1 - 10: ";
	cin >> Num_Round;

	return Num_Round;
}

void Rounds(int &User_Point , int &PC_Point , int &Draw_Point , string username , int Num_Round) {

	for (int i = 1; i <= Num_Round; i++)
	{
		cout << "\n\t---Round [" << i << "]---\t" << endl;
		PlayRound(User_Point, PC_Point, Draw_Point , username);
		cout << endl;
	}

}

void StartGame() {
	string username = GetUserName();
	char playAgain;
	bool startGame = true;

	while (startGame) {
		int Num_Round = NumOfRounds();
		int User_Point = 0, PC_Point = 0, Draw_Point = 0;
		Rounds(User_Point, PC_Point, Draw_Point , username , Num_Round);

		if (User_Point > PC_Point)
		{
			cout << "\n\t--------------------------------------------------\n";
			cout << "\t\t + + + Y O U   W I N + + +\t\n";
			cout << "\n\t--------------------------------------------------\n";
			cout << "\n\t------------------[ Game Results ]----------------\n";
			cout << "\tGame Rounds : " << Num_Round << endl;
			cout << "\t" << username << " : " << User_Point << endl;
			cout << "\tComputer : " << PC_Point << endl;
			cout << "\tDraw : " << Draw_Point << endl;
			cout << "\n\t--------------------------------------------------\n" << endl;
		}
		else if (User_Point < PC_Point)
		{
			cout << "\n\t--------------------------------------------------\n";
			cout << "\t\t + + + G a m e   O v e r + + +\t\n";
			cout << "\n\t--------------------------------------------------\n";
			cout << "\n\t------------------[ Game Results ]----------------\n";
			cout << "\tGame Rounds : " << Num_Round << endl;
			cout << "\t" << username << " : " << User_Point << endl;
			cout << "\tComputer : " << PC_Point << endl;
			cout << "\tDraw : " << Draw_Point << endl;
			cout << "\n\t--------------------------------------------------\n" << endl;
		}
		else if (User_Point == PC_Point){
			cout << "\n\t--------------------------------------------------\n";
			cout << "\t\t + + + D R A W + + +\t\n";
			cout << "\n\t--------------------------------------------------\n";
			cout << "\n\t------------------[ Game Results ]----------------\n";
			cout << "\tGame Rounds : " << Num_Round << endl;
			cout << "\t" << username << " : " << User_Point << endl;
			cout << "\tComputer : " << PC_Point << endl;
			cout << "\tDraw : " << Draw_Point << endl;
			cout << "\n\t--------------------------------------------------\n" << endl;
		}
		
		cout << "\tDo you want play again? [y]/[n]: ";
		cin >> playAgain;

		if (playAgain == 'N' || playAgain == 'n')
		{
			startGame = false;
		}
		else {
			system("cls");
			system("color 00");
		}
	}

}





int main() {
	srand((unsigned)time(NULL));

	StartGame();



	return 0;
}