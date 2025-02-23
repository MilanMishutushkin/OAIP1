#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Functions.h"

int main()
{
	bool programFlag = true;
	while (programFlag)
	{
		bool flag = true;
		int choice;
		while (flag)
		{
			std::cout << "\n#########################################";
			std::cout << "\n\t Welcome!";
			std::cout << "\n 1.Enter contract information";
			std::cout << "\n 2:Show contract information";
			std::cout << "\n 3:Sort contract information by number";
			std::cout << "\n 4:Add contract information";
			std::cout << "\n 5:Change contract information";
			std::cout << "\n 6:Exit";
			std::cout << "\n#########################################\n";
			std::cout << "\nChoose an option:";
			std::cin >> choice;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n_________________________________\n";
				std::cout << "\nInvalid input.Try enter digits without space! \n";
				std::cout << "\n_________________________________\n";
				continue;
			}
			else
			flag = false;
		}
		switch (choice)
		{
		case 1: enterContractInformation();
			break;
		case 2: printContractInformation();
			break;
		case 3:
		{
			sortContractInformation();
			std::cout << "\n__________________________________________\n";
			std::cout << "\n Contracts have been successfully sorted\n";
			std::cout << "\n__________________________________________\n";
		}
		break;
		case 6:
		{
			std::cout << "\n__________________________________________\n";
			std::cout << "\n The program has been successfully closed\n";
			std::cout << "\n__________________________________________\n";
			programFlag = false;
		}
		break;
		default:
		{
			std::cout << "\n_________________________________\n";
			std::cout << "\n Invalid input.Try again!\n";
			std::cout << "\n_________________________________\n";
		}
		break;
		}
	}
}