#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Functions.h"

int main()
{
	const char* filename = "contracts.txt";
	loadContractsFromFile(filename);
	bool programFlag = true;
	while (programFlag)
	{
		bool flag = true;
		int choice;
		while (flag)
		{
			std::cout << "\n#########################################";
			std::cout << "\n\t Welcome!";
			std::cout << "\n 1.Enter new contract information";
			std::cout << "\n 2.Show contract information";
			std::cout << "\n 3.Sort contract information by number";
			std::cout << "\n 4.Add contract information";
			std::cout << "\n 5.Change contract information";
			std::cout << "\n 6.Exit";
			std::cout << "\n#########################################\n";
			std::cout << "\nChoose an option:";
			std::cin >> choice;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n______________________________________________\n";
				std::cout << "\nInvalid input.Try enter digits without space! \n";
				std::cout << "\n______________________________________________\n";
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
			int choose;
			std::cout << "Sort by what?\n1.Number\n2.Name\n";
			std::cout << "Your choice: ";
			
			bool flag = true;
			while (flag)
			{
				std::cin >> choose;
				if (std::cin.fail() || std::cin.peek() != '\n')
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n______________________________________________\n";
					std::cout << "\nInvalid input.Try enter digits without space! \n";
					std::cout << "\n______________________________________________\n";

					continue;
				}
				else
					flag = false;

			}
			if (choose == 1)
			{
				sortContractInformationByNumber();

			}
			else
			{
				sortContractInformationByName();
			}
			std::cout << "\n__________________________________________\n";
			std::cout << "\n Contracts have been successfully sorted\n";
			std::cout << "\n__________________________________________\n";
		}
		break;
		case 4:
		{
			addContractInformation();
			std::cout << "\n__________________________________________\n";
			std::cout << "\n Contract have been successfully added\n";
			std::cout << "\n__________________________________________\n";
		}
			break;
		case 5:
		{
			changeContractInformation();
			std::cout << "\n__________________________________________\n";
			std::cout << "\n Contracts have been successfully changed\n";
			std::cout << "\n__________________________________________\n";
		}
			break;
		case 6:
		{
			std::cout << "\n__________________________________________\n";
			std::cout << "\n The program has been successfully closed\n";
			std::cout << "\n__________________________________________\n";
			saveContractsToFile(filename);
			programFlag = false;
		}
			break;
		default:
		{
			std::cout << "\n_________________________________\n";
			std::cout << "\n	Invalid input.Try again!\n";
			std::cout << "\n_________________________________\n";
		}
			break;
		}
	}
}