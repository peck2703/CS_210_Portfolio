#pragma once
/*
 * Name: 			Michael Peck
 * Date:			04/05/2025
 * App:				Project Two - Airgead Banking
 * School:			Southern New Hampshire University
 * Class:			CS 210 - Programming Languages
 */

#ifndef PECK_PROJECT_TWO_AIRGEAD_BANKING_H
#define PECK_PROJECT_TWO_AIRGEAD_BANKING_H

using namespace std;

void DisplayMenu();

void DisplayRows(string t_textToShow, int t_width, char t_align, bool t_endLine);

void DisplayCharRows(char t_fillChar, int t_width, char t_align, bool t_endLine);

void StartMainMenuInput();

double PromptForInput(string t_promptString);

void ProcessInput(double& t_initial, double& t_monthly, double& t_rate, int& t_years);

void CreateMonthlyReport(const std::unique_ptr<Report_Monthly>& monthlyReport);

void CreateNonMonthlyReport(const std::unique_ptr<Report_Non_Monthly>& nonMonthlyReport);

void CreateReportTitle(string t_reportTitle, int t_width);

#endif