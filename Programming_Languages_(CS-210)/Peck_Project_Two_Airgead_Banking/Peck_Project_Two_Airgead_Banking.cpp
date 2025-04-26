/*
 * Name: 			Michael Peck
 * Date:			04/05/2025
 * App:				Project Two - Airgead Banking
 * School:			Southern New Hampshire University
 * Class:			CS 210 - Programming Languages
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <memory>
#include "Report_Monthly.h"
#include "Report_Non_Monthly.h"
#include "Peck_Project_Two_Airgead_Banking.h"


using namespace std;

int main()
{
	//Handles user input for loop
	char userChoice = 'Y';

	while (std::toupper(userChoice) == 'Y') {
		//First show menu for user to select
		DisplayMenu();
		//Start sequence
		StartMainMenuInput();

		//Prompt user to continue loop
		cout << "Would you like to try again?";

		cin >> userChoice;
		system("cls");
	}
	
	cout << "Thank you for using this program. Goodbye!";
	return 0;
}

void DisplayMenu()
{
	DisplayCharRows('*', 80, 'l', true);
	DisplayCharRows('*', 32, 'l', false);
	DisplayRows("Data Input", 16, 'c', false);
	DisplayCharRows('*', 32, 'l', true);
}

void DisplayRows(string t_textToShow, int t_width, char t_align, bool t_endLine)
{
	int m_adjustedWidth = 0;

	//Switch alignment based on char parameter
	switch (t_align)
	{
		//Left
		case 'l':
			cout << setfill(' ') << left << setw(t_width) << t_textToShow;
			break;
		//Center - Need to do a little calculation to center text
		case 'c':
			m_adjustedWidth = (t_width - t_textToShow.length()) / 2;
			cout << setfill(' ') << setw(m_adjustedWidth) << " " << setw(t_textToShow.length()) << t_textToShow << setfill(' ') << setw(m_adjustedWidth) << " ";
			break;
		//Right
		case 'r':
			cout << setfill(' ') << right << setw(t_width) << t_textToShow;
			break;
		default:
			break;
	}
	//If bool for endLine exists, then add new line
	if (t_endLine) {
		cout << endl;
	}
}

void DisplayCharRows(char t_fillChar, int t_width, char t_align, bool t_endLine)
{
	//Switch alignment based on char parameter
	switch (t_align) {
		//Left
		case 'l':
			cout << setfill(t_fillChar) << left << setw(t_width) << "";
			break;
		//Center - Ever used?
		case 'c':
			break;
		//Right
		case 'r':
			cout << setfill(t_fillChar) << right << setw(t_width) << "";
			break;
		default:
			break;
	}
	//If bool for endLine exists, then add new line
	if (t_endLine) {
		cout << endl;
	}
}

void StartMainMenuInput()
{
	//Prompt for all inputs and store them for use later
	double m_initialAmount = PromptForInput("Initial Investment Amount: ");
	double m_monthlyDeposit = PromptForInput("Monthly Deposit: ");
	double m_annualInterest = PromptForInput("Annual Interest(%): ");
	int m_numberOfYears = PromptForInput("Number of Years: ");

	system("pause");

	//Process all above inputs once all the amounts made
	ProcessInput(m_initialAmount, m_monthlyDeposit, m_annualInterest, m_numberOfYears);
}


double PromptForInput(string t_promptString)
{
	//Create a temporary int to store choice
	double m_userChoice = 0;

	//Prompt the user and store in temporary int variable
	cout << setfill(' ') << setw(30) << t_promptString;

	cin >> m_userChoice;
	while (!cin) {
		try {
			//Check to see if cin is number
			if (!(std::cin >> m_userChoice)) {
				throw std::runtime_error("Invalid input. Please enter an number.");
			}
		}
		catch (const std::runtime_error& error) {
			std::cerr << "Error: " << error.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << setfill(' ') << setw(30) << t_promptString;
		cin >> m_userChoice;		
	}
	//cin >> m_userChoice;

	//Return the choice
	return m_userChoice;
}

void ProcessInput(double& t_initial, double& t_monthly, double& t_rate, int& t_years)
{
	//Create unique pointers to both report classes. These pointers will be destroyed when out of scope
	unique_ptr<Report_Monthly> monthlyReport = std::make_unique<Report_Monthly>(t_initial, t_monthly, t_rate, t_years);
	unique_ptr<Report_Non_Monthly> nonMonthlyReport = std::make_unique<Report_Non_Monthly>(t_initial, t_rate, t_years);

	//Clear the board
	system("cls");

	//Generate the reports
	CreateMonthlyReport(monthlyReport);
	CreateNonMonthlyReport(nonMonthlyReport);

	//Wait for any input
	system("pause");
}

void CreateMonthlyReport(const std::unique_ptr<Report_Monthly>& monthlyReport)
{
	//Create width for screen
	int m_width = 110;

	//Set initial values
	monthlyReport->StartAccount();

	//Generate Window report
	CreateReportTitle("Balance and Interest With Additional Monthly Deposits", m_width);
	for (int i = 0; i < monthlyReport->GetTotalMonthCount(); i++) {
		
		//Perform interest caluclations, but do not print until year end
		monthlyReport->IncreaseMonth();

		//Year end. Print results
		if (i % 12 == 11) {
			
			/*Overly complicated system to convert dollar signand balances into a single string
			* But it appears this is the only way that I can find that aligns the dollar sign
			* symbol up appropriately under the appropriate subheading
			*/

			//Closing balance
			//Convert closing balance to string with preset precision
			double m_closing = monthlyReport->GetClosingBalance();
			std::stringstream m_closeStream;

			//Set precision
			m_closeStream << std::fixed << std::setprecision(2) << m_closing;

			//Convert to string
			std::string m_closingStr = m_closeStream.str();

			//Interest
			//Convert total intest to string with preset precision
			double m_totalInterest = monthlyReport->GetTotalInterestEarned();
			std::stringstream m_interestStream;

			//Set precision
			m_interestStream << std::fixed << std::setprecision(2) << m_totalInterest;

			//Convert to string
			std::string m_interestStr = m_interestStream.str();

			
			//New year every 12 months end of year balance, then print
			cout << setfill(' ') << setw(m_width / 5) << right << ((i / 12)+1);
			cout << setw(m_width * (2.0 / 5.0)) << fixed << setprecision(2) << "$" + m_closingStr;
			cout << setw(m_width * (2.0 / 5.0)) << fixed << setprecision(2) << "$" + m_interestStr;
			cout << endl << endl;
			
			//Reset the interest earned to 0 to only show interest earned each year.
			monthlyReport->ResetTotalInterestEarned();
		}
	}
}

void CreateNonMonthlyReport(const std::unique_ptr<Report_Non_Monthly>& nonMonthlyReport)
{
	//Create width for screen
	int m_width = 110;

	//Set initial values
	nonMonthlyReport->StartAccount();

	//Generate Window report
	CreateReportTitle("Balance and Interest Without Additional Monthly Deposits", m_width);

	for (int i = 0; i < nonMonthlyReport->GetTotalMonthCount() + 12; i++) {

		//Perform interest caluclations, but do not print until year end
		nonMonthlyReport->IncreaseMonth();

		//Year end. Print results
		if (i % 12 == 0) {

			/*Overly complicated system to convert dollar signand balances into a single string
			* But it appears this is the only way that I can find that aligns the dollar sign
			* symbol up appropriately under the appropriate subheading
			*/

			//Closing balance
			//Convert closing balance to string with preset precision
			double m_closing = nonMonthlyReport->GetClosingBalance();
			std::stringstream m_closeStream;

			//Set precision
			m_closeStream << std::fixed << std::setprecision(2) << m_closing;

			//Convert to string
			std::string m_closingStr = m_closeStream.str();

			//Interest
			//Convert total intest to string with preset precision
			double m_totalInterest = nonMonthlyReport->GetTotalInterestEarned();
			std::stringstream m_interestStream;

			//Set precision
			m_interestStream << std::fixed << std::setprecision(2) << m_totalInterest;

			//Convert to string
			std::string m_interestStr = m_interestStream.str();

			if (i / 12 != 0) {
				//New year every 12 months end of year balance, then print
				cout << setfill(' ') << setw(m_width / 5) << right << (i / 12);
				cout << setw(m_width * (2.0 / 5.0)) << fixed << setprecision(2) << "$" + m_closingStr;
				cout << setw(m_width * (2.0 / 5.0)) << fixed << setprecision(2) << "$" + m_interestStr;
				cout << endl << endl;
			}

			//Reset the interest earned to 0 to only show interest earned each year.
			nonMonthlyReport->ResetTotalInterestEarned();
		}
	}
}

void CreateReportTitle(string t_reportTitle, int t_width)
{
	//Calculate the space on either side for centering text
	int splitDifference = ((t_width - t_reportTitle.length()) / 2);

	//Clear the board for report
	//system("cls");
	cout << setfill('-') << setw(t_width) << "" << endl;
	cout << setfill(' ')  << setw(splitDifference) << "" << setw(t_reportTitle.length()) << t_reportTitle << setw(splitDifference) << "" << endl;
	cout << setfill('=') << setw(t_width) << "" << endl;

	//Create subheadings (works best when t_width is multiple of 5)
	cout << setfill(' ') << setw(t_width / 5) << right << "Year";
	cout << setw(t_width * (2.0 / 5.0)) << right << "Year End Balance";
	cout << setw(t_width * (2.0 / 5.0)) << right << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(t_width) << "" << endl;
}
