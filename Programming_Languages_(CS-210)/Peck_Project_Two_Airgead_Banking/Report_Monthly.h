#pragma once
/*
 * Name: 			Michael Peck
 * Date:			04/05/2025
 * App:				Project Two - Airgead Banking
 * School:			Southern New Hampshire University
 * Class:			CS 210 - Programming Languages
 */

#ifndef REPORT_MONTHLY_H
#define REPORT_MONTHLY_H

#include <memory>

using namespace std;

class Report_Monthly {
	private:
		
		double m_initialInvestment;
		double m_monthlyDeposit;
		double m_annualRate;
		int m_years;

		double m_openingAmount = 0;
		double m_totalAmount = 0;
		int m_months = 0;			//Make sure to increase index by one when printing
		int m_totalMonths = 0;
		double m_interestEarned = 0;
		double m_totalInterestEarned = 0;
		double m_closingBalance = 0;
	
	public:

		//Constructor with variables
		Report_Monthly(int t_initial, int t_monthly, int t_rate, int t_years) : m_initialInvestment(t_initial), m_monthlyDeposit(t_monthly), m_annualRate(t_rate), m_years(t_years) {}

		//Getter/Setter for Initial Investment
		double GetInitialInvestment();
		void SetInitialInvestment(double t_investment);

		//Getter/setter for monthly deposits
		double GetMonthlyDeposit();
		void SetMonthlyDeposit(double t_monthly);

		//Getter/setter for annual rate
		double GetAnnualRate();
		void SetAnnualRate(double t_rate);

		//Getter/setter for opening balance
		double GetOpeningAmount();
		void SetOpeningAmount(double t_opening);

		//Getter/setter for opening balance + monthly deposit before interest
		double GetTotalAmount();
		void SetTotalAmount(double t_total);

		//Get current month
		int GetMonthCount();
		//Increase by one
		void SetMonthCount();

		double GetTotalMonthCount();
		//Total amount of months for a loop
		void SetYearCount();

		//Calculate interest gained on current balance
		double GetInterestEarned();
		void SetInterestEarned(double t_interest);

		//Calculate interest earned all together
		double GetTotalInterestEarned();
		void SetTotalInterestEarned(double t_interest);
		
		//Reset interest earned at the end of the year
		void ResetTotalInterestEarned();

		//Getter/setter for end closing balance after calculations
		double GetClosingBalance();
		void SetClosingBalance(double t_closing);

		//Calculates new balances for compounded interest, loop calls this function
		void IncreaseMonth();

		////Only call function once (at start)
		void StartAccount();
};

#endif