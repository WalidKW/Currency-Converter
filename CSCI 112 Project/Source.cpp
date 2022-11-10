
#include <iostream>
#include <string>
#include <climits>
using namespace std;


void choose(double currency)//function to print a message after user enters which currency he would like to convert from or to.
{
	if (currency == 1)
		cout << "You have choosen AED." << endl;
	else if (currency == 2)
		cout << "you have choosen INR." << endl;
	else if (currency == 3)
		cout << "you have choosen USD." << endl;
	else if (currency == 4)
		cout << "you have choosen GBP." << endl;
	else if (currency == 5)
		cout << "you have choosen EUR." << endl;
	else if (currency == 6)
		cout << "you have choosen AUD." << endl;
	else if (currency == 7)
		cout << "you have choosen JOD." << endl;
	else if (currency == 8)
		cout << "you have choosen TRY." << endl;
	else if (currency == 9)
		cout << "you have choosen PHP." << endl;
	else if (currency == 10)
		cout << "you have choosen KWD." << endl;
	else
		cout << "error!! value must be a number between 1-10" << endl; //error massage if user enter invalid input.
}


double convert_to_usd(int currency,double money)//convert the amount of money the user enters to USD.
{
	switch (currency)
	{
	case 1: return money * 0.27; break; //AED TO USD
	case 2: return money * 0.013; break; //INR TO USD
	case 3: return money * 1; break; //USD TO USD
	case 4: return money * 1.30; break; //GBP TO USD
	case 5: return money * 1.08; break; //EUR TO USD
	case 6: return money * 0.74; break; //AUD TO USD
	case 7: return money * 1.41; break; //JOD TO USD
	case 8: return money * 0.068; break; //TRY TO USD
	case 9: return money * 0.019; break; //PHP TO USD
	case 10: return money * 3.27; break; //KWD TO USD
	default: return 1; break;
	}
}


double convert_from_usd(int currency, double money)//convert the amount of money the user enters from USD to the currency he has chosen.
{
	switch (currency)
	{
	case 1: return money / 0.27; break; //AED TO USD
	case 2: return money / 0.013; break; //INR TO USD
	case 3: return money / 1; break; //USD TO USD
	case 4: return money / 1.30; break; //GBP TO USD
	case 5: return money / 1.08; break; //EUR TO USD
	case 6: return money / 0.74; break; //AUD TO USD
	case 7: return money / 1.41; break; //JOD TO USD
	case 8: return money / 0.068; break; //TRY TO USD
	case 9: return money / 0.019; break; //PHP TO USD
	case 10: return money / 3.27; break; //KWD TO USD
	default: return 1; break;
	}
}


int main()
{
	string Restart; //To repeat the program.
	do
	{
		//declaration.
		int convert_from, convert_to;
		double money;

		//program header.
		cout << "********************************************************************************************************" << endl;
		cout << "						Convert Currency											 " << endl;
		cout << "********************************************************************************************************" << endl;

		//currency list.
		cout << "1. AED: Emeriti Dirham\n2. INR: Indian Rupee.\n3. USD : US Dollar.\n4. GBP : Britch Pound.\n5. EUR : Euro" << endl;
		cout << "6. AUD : Australian Dollar.\n7. JOD : Jordanian Dinar\n8. TRY : Turkish Lira\n9. PHP : Philippine Peso.\n10. KWD : Kuwaiti Dinar " << endl;
		
		do { //Do-while to repeat the code until the user enter a valid input.
			cout << "\nWhat currency would you like to convert from? ";
			cin >> convert_from;
			while (cin.fail())//to stop the user from entering a character or a string.
			{
				cin.clear();//clears the value entered so that its not consistant.
				cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
				cout << "error!! value must be a number between 1-10" << endl;
				cin >> convert_from;
			}
			choose(convert_from);//function call.
		} while (convert_from < 1 || convert_from > 10);

		cin.clear();//clears the previous value to avoid errors.
		cin.ignore(INT_MAX, '\n');
		
		do { //Do-while to repeat the code until the user enter a valid input.
			cout << "\nWhat currency would you like to convert to? ";
			cin >> convert_to;
			while (cin.fail())//to stop the user from entering a character or a string
			{
				cin.clear();//clears the value entered so that its not consistant.
				cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
				cout << "\nerror!! value must be a number between 1-10 !" << endl;
				cin >> convert_to;
			}
			choose(convert_to);//function call.
		} while (convert_to < 1 || convert_to > 10);

		cin.clear();//clears the previous value to avoid errors.
		cin.ignore(INT_MAX, '\n');

		cout << "\nHow much money do you want to convert? ";
		cin >> money;
		while (cin.fail())//to stop the user from entering a character or a string
		{
			cin.clear();//clears the value entered so that its not consistant.
			cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
			cout << "\nerror!! value must be a number !" << endl;
			cin >> money;
		}

		double usd = convert_to_usd(convert_from, money); //Converted to USD then save it in (usd).

		cout << "\nAmount of money after convert = " << convert_from_usd(convert_to, usd);//Converted from USD to the curreny user has chosen.
		cout << endl;

		cout << "\nPress (R) if you want to Restart or Press any key if you want to Quit: ";//Restart.
		cin >> Restart;

	} while (Restart == "R"); //The program will restart until the user enter Q which is Quit.
	
	system("pause");
	return 0;
}
