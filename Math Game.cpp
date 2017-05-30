#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath> 
#include <iomanip>
#include <ctime>

using namespace std;
void credits();
string validateName(string userName);
string checkUserAnswer(string userAnswer);
void retrieveStats(ifstream& inData, ofstream& outData, int& totalRight, int& totalWrong, double& totalWages, string& userName);
void saveStats(ofstream& outData, int& totalRight, int& totalWrong, double& totalWages,string& userName);
void generateAddition (int& totalRight, int& totalWrong, double& totalWages);
void generateSubtraction (int& totalRight, int& totalWrong, double& totalWages);
void generateMultiplication (int& totalRight, int& totalWrong, double& totalWages);
void generateDivision (int& totalRight, int& totalWrong, double& totalWages);
void displayStats(int totalRight, int totalWrong, double totalWages, string userName);

void credits()
{
        cout << "***********************"<< endl;
        cout << "***********************"<< endl;
        cout << "***********************"<< endl;
        cout << "******           ******"<< endl;
        cout << "******TheMathGame******"<< endl;
        cout << "******  ByMaria  ******"<< endl;
        cout << "******  Vargas   ******"<< endl;
        cout << "******           ******"<< endl;
        cout << "***********************"<< endl;
        cout << "***********************"<< endl;
        cout << "***********************"<< endl;
}

string validateName(string userName)//validate for the user's name
{
    int userNameLength;
    int counter = 0;
    userNameLength = userName.length();
    
    while(userNameLength==0)
        {
            cout << "\nThat is a blank.\nTry again.\n";
            getline(cin,userName);
            userNameLength = userName.length();
        }
    while(counter < userNameLength)
    {
        if (!isalpha(userName[counter])) 
        {
            cout << "That is not a name.\nTry again.\n ";               
            getline(cin,userName);
            userNameLength = userName.length();
            counter = 0;
        } 
        else 
        counter++;
			
        while (userNameLength == 0) 
        {
            cout << "\nThat is a blank.\nTry again.\n";
            getline(cin,userName);
            userNameLength = userName.length();
        }        
    }
     
  return userName; 
}

string checkUserAnswer(string userAnswer)// validate for user's 
{
    int userAnswerLength;
    int counter = 0;
    userAnswerLength = userAnswer.length();
    
    while(userAnswerLength == 0)
        {
            cout << "\nThat is a blank.\nTry again.\n";
            getline(cin,userAnswer);
            userAnswerLength = userAnswer.length();
        }
    while(counter < userAnswerLength)
    {
        if (!isdigit(userAnswer[counter])) 
        {
            cout << "That is not a number.\nTry again.\n ";               
            getline(cin,userAnswer);
            userAnswerLength = userAnswer.length();
            counter = 0;
        } 
        else 
        counter++;
			
        while (userAnswerLength == 0) 
        {
            cout << "\nThat is a blank.\nTry again.\n";
            getline(cin,userAnswer);
            userAnswerLength = userAnswer.length();
        }        
    }
      
    return userAnswer;
}

void retrieveStats(ifstream& inData, ofstream& outData, int& totalRight, int& totalWrong, double& totalWages,
        string& userName)
{
        
        inData.open(userName + ".txt");
	
        if (inData)
        {
            inData >> userName;
            inData >> totalRight;
            inData >> totalWrong;
            inData >>totalWages;
            cout << "Welcome Returning player!" << endl;
        }
        else
        {
            outData.open(userName + ".txt"); 
            outData << userName << endl;
            outData << totalRight << endl;
            outData << totalWrong << endl;
            outData << totalWages << endl;
            cout << "Welcome New Player!" << endl;
        }
    
}

void saveStats(ofstream& outData, int& totalRight, int& totalWrong, double& totalWages,
        string& userName)
{
        outData << userName  << endl;
	outData << totalRight << endl;
	outData << totalWrong << endl;
        outData << totalWages << endl;
        outData.close();
        

}

void generateAddition (int& totalRight, int& totalWrong, double& totalWages)
        
{      
        srand(time(NULL));    
        int number1 = rand() % 10 + 1;
	int number2 = rand() % 10 + 1;
	int theAnswer = number1 + number2;
	int userInputInteger;
        string userInput;

	cout << "******ADDITION******" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        cout << "***** " << number1 << " + " << number2 << " =?" << " *****" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        
        
        cin >> userInput;
	checkUserAnswer(userInput);
        userInputInteger = stoi(userInput);

	if(userInputInteger == theAnswer)
	{
            cout << "CORRECT " << endl;
            totalRight += 1;
            totalWages += 0.05;
	}
	else
	{
            cout << "INCORRECT " << endl;
            totalWrong += 1;
            totalWages -= 0.03;
	}
   
}

void generateSubtraction(int& totalRight, int& totalWrong, double& totalWages)
       
{
     srand(time(NULL));    
        int number1 = rand() % 10 + 1;
	int number2 = rand() % 10 + 1;
	int theAnswer = number1 - number2;
	int userInputInteger;
        string userInput;

	cout << "******ADDITION******" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        cout << "***** " << number1 << " - " << number2 << " =?" << " *****" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        
        
        cin >> userInput;
	checkUserAnswer(userInput);
        userInputInteger = stoi(userInput);

	if(userInputInteger == theAnswer)
	{
            cout << "CORRECT " << endl;
            totalRight += 1;
            totalWages += 0.05;
	}
	else
	{
            cout << "INCORRECT " << endl;
            totalWrong += 1;
            totalWages -= 0.03;
	}
    
}

void generateMultiplication(int& totalRight, int& totalWrong, double& totalWages)
       
{
     srand(time(NULL));    
        int number1 = rand() % 10 - 1;
	int number2 = rand() % 10 - 1;
	int theAnswer = number1 * number2;
	int userInputInteger;
        string userInput;

	cout << "******ADDITION******" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        cout << "***** " << number1 << " * " << number2 << " =?" << " *****" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        
        
        cin >> userInput;
	checkUserAnswer(userInput);
        userInputInteger = stoi(userInput);

	if(userInputInteger == theAnswer)
	{
            cout << "CORRECT " << endl;
            totalRight += 1;
            totalWages += 0.05;
	}
	else
	{
            cout << "INCORRECT " << endl;
            totalWrong += 1;
            totalWages -= 0.03;
	}
    
}

void generateDivision(int& totalRight, int& totalWrong, double& totalWages)
        
{
     srand(time(NULL));    
        int number1 = rand() % 10 + 1;
	int number2 = rand() % 10 + 1;
	int theAnswer = number1 / number2;
	int userInputInteger;
        string userInput;

	cout << "******ADDITION******" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        cout << "***** " << number1 << " / " << number2 << " =?" << " *****" << endl;
        cout << "********************" << endl;
        cout << "********************" << endl;
        
        
        cin >> userInput;
	checkUserAnswer(userInput);
        userInputInteger = stoi(userInput);

	if(userInputInteger == theAnswer)
	{
            cout << "CORRECT " << endl;
            totalRight += 1;
            totalWages += 0.05;
	}
	else
	{
            cout << "INCORRECT " << endl;
            totalWrong += 1;
            totalWages -= 0.03;
	}
    
}

void displayStats(int totalRight, int totalWrong, double totalWages,
        string userName)
{
        cout << userName << endl;
        cout << "Your score is:" << endl;
        cout << "Total Earnings " << totalWages << endl;
        cout << "Total Right " << totalRight << endl;
        cout << "Total Wrong " << totalWrong << endl;
}

void menu(ofstream& outData, int& totalRight, int& totalWrong, double& totalWages,
        string& userName )
{
    
    bool boolean = true; 
    
    do
    {
        cout << "******CHOOSE A PROBLEM******" << endl;
        cout << "****************************" << endl;
        cout << "****************************" << endl;
        cout << "******                ******" << endl;
        cout << "****** 1. ADD         ******" << endl;
        cout << "****** 2. SUBTRACT    ******" << endl;
        cout << "****** 3. MULTIPLY    ******" << endl;
        cout << "****** 4. DIVIDE      ******" << endl;
        cout << "****** 5. STATS       ******" << endl;
        cout << "****** n/N to QUIT    ******" << endl;
        cout << "******                ******" << endl;
        cout << "****************************" << endl;
        cout << "****************************" << endl;
        cout << "****************************" << endl;
        
        
         string userInput;
         char quit;
         char number;
         
         cin >> number;

         switch (number)
        {
            case '1': generateAddition(totalRight, totalWrong,  totalWages);
            break;
            case '2': generateSubtraction(totalRight,  totalWrong,  totalWages);
            break;
            case '3':generateMultiplication(totalRight, totalWrong,  totalWages);
            break;
            case '4':generateDivision(totalRight, totalWrong,  totalWages);
            break;
            case '5':displayStats(totalRight, totalWrong,  totalWages, userName);
            break;
            case 'n':displayStats(totalRight, totalWrong,  totalWages, userName);
            cout << "Goodbye";
            saveStats(outData, totalRight, totalWrong,  totalWages, userName); 
            exit(0);
            break;
            case 'N': displayStats( totalRight,  totalWrong,  totalWages, userName);
            cout << "Goodbye";
            saveStats(outData, totalRight, totalWrong, totalWages, userName);
            exit(0);
            default:
            cout << "That is not a valid entry.\nPlease try again." << endl;
        }
    }
    while (boolean == true);
}

int main() {
    
        int totalRight;
        int totalWrong;
        double totalWages;
        string userName;
        ofstream outData;
        ifstream inData;
     
        //UpdateStats myUserStats; 
           
        char proceed = 'y';
        string userInput; 
        
        credits();
        cout << "\ny/Y to continue, any other char to exit" << endl;
        getline(cin,userInput);
        
        if(userInput.length() == 0)
        {
            cout << "Goodbye" << endl;
            exit(0);
        }
        
        proceed = userInput[0];
        
        if (!(proceed == 'y' || proceed == 'Y'))
        {
            cout << "Goodbye" << endl;
            exit(0);
        }
        
        cout << "\n Enter your name: ";
        getline(cin, userName);
        validateName(userName);
        retrieveStats(inData, outData, totalRight, totalWrong, totalWages,userName);
        menu(outData, totalRight, totalWrong, totalWages, userName);
            
    return 0;
}
