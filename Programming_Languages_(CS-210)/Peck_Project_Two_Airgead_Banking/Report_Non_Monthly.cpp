/*
 * Name: 			Michael Peck
 * Date:			04/05/2025
 * App:				Project Two - Airgead Banking
 * School:			Southern New Hampshire University
 * Class:			CS 210 - Programming Languages
 */

#include "Report_Non_Monthly.h"

double Report_Non_Monthly::GetInitialInvestment()
{
	return m_initialInvestment;
}

void Report_Non_Monthly::SetInitialInvestment(double t_investment)
{
	m_initialInvestment = t_investment;
}

double Report_Non_Monthly::GetAnnualRate()
{
	return m_annualRate;
}

void Report_Non_Monthly::SetAnnualRate(double t_rate)
{
	m_annualRate = t_rate;
}

double Report_Non_Monthly::GetOpeningAmount()
{
	return m_openingAmount;
}

void Report_Non_Monthly::SetOpeningAmount(double t_opening)
{
	m_openingAmount = t_opening;
}

double Report_Non_Monthly::GetTotalAmount()
{
	return m_totalAmount;
}

void Report_Non_Monthly::SetTotalAmount(double t_total)
{
	m_totalAmount = t_total;
}

int Report_Non_Monthly::GetMonthCount()
{
	return m_months;
}

void Report_Non_Monthly::SetMonthCount()
{
	//Increase by one
	m_months++;
}

double Report_Non_Monthly::GetTotalMonthCount()
{
	return m_totalMonths;
}

void Report_Non_Monthly::SetYearCount()
{
	//Total count of months
	m_totalMonths = m_years * 12;
}

double Report_Non_Monthly::GetInterestEarned()
{
	return m_interestEarned;
}

void Report_Non_Monthly::SetInterestEarned(double t_interest)
{
	//Interest earned per month. Opening amount + monthly deposit * annual rate by months in a year
	m_interestEarned = ((GetOpeningAmount() * (GetAnnualRate() / 100) / 12));

	//Increase total interest earned
	SetTotalInterestEarned(m_interestEarned);
}

double Report_Non_Monthly::GetTotalInterestEarned()
{
	return m_totalInterestEarned;
}

void Report_Non_Monthly::SetTotalInterestEarned(double t_interest)
{
	m_totalInterestEarned += t_interest;
}

void Report_Non_Monthly::ResetTotalInterestEarned()
{
	m_totalInterestEarned = 0;
}

double Report_Non_Monthly::GetClosingBalance()
{
	return m_closingBalance;
}

void Report_Non_Monthly::SetClosingBalance(double t_closing)
{
	m_closingBalance = t_closing;
}

void Report_Non_Monthly::IncreaseMonth()
{
	//Handle main loop
	//Increase month
	SetMonthCount();

	//Get previous closing balance
	SetOpeningAmount(GetClosingBalance());

	//Generate new total with opening + deposit
	SetTotalAmount(GetOpeningAmount());

	//Generate new interest earned on total amount
	SetInterestEarned(GetTotalAmount());

	//Set new closing balance
	SetClosingBalance(GetTotalAmount() + GetInterestEarned());
}

void Report_Non_Monthly::StartAccount()
{
	//Set up monthcount
	SetYearCount();

	//Set initial opening balance
	SetOpeningAmount(GetInitialInvestment());

	//Prefill Closing balance for first month
	SetClosingBalance(GetOpeningAmount());
}
