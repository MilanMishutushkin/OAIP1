#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

struct Contract {
	int contractNumber;
	char productName[50];
	int quantity;
	int pricePerUnit;
	int totalPrice;
	int customFee;

	void printContract(std::ofstream& file) {
		file << contractNumber << "\t"
			<< productName << "\t"
			<< quantity << "\t"
			<< pricePerUnit << "\t"
			<< totalPrice << "\t"
			<< customFee << std::endl;
	}

	void readContract(std::ifstream& file) {
		file >> contractNumber
			>> productName
			>> quantity
			>> pricePerUnit
			>> totalPrice
			>> customFee;
	}
};
static Contract contract[20];

int numberOfContracts;

void saveContractsToFile(const char* filename) {
	std::ofstream file(filename);
	file << numberOfContracts << std::endl;
	for (int i = 0; i < numberOfContracts; ++i) {
		contract[i].printContract(file);
	}
	file.close();
}
void loadContractsFromFile(const char* filename)
{
	std::ifstream file(filename);
	file >> numberOfContracts;
	for (int i = 0; i < numberOfContracts; ++i) {
		contract[i].readContract(file);
	}
	file.close();
}
void enterContractInformation()
{

	bool flag = true;

	while (flag)
	{
		std::cout << "\nEnter quantity of contracts: ";
		std::cin >> numberOfContracts;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n_________________________________\n";
			std::cout << "\n Invalid input.Try enter digits! \n";
			std::cout << "\n_________________________________\n";
			continue;
		}
		else
			flag = false;
	}
	for (int i = 0; i < numberOfContracts; i++)
	{
		bool flag = true;
		while (flag)
		{
			std::cout << "\nEnter number of " << i + 1 << " contract: ";
			std::cin >> contract[i].contractNumber;
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
		std::cout << "\nEnter name of " << i + 1 << " product: ";;
		std::cin >> contract[i].productName;
		flag = true;
		while (flag)
		{
			std::cout << "\nEnter quantity of " << i + 1 << " product: ";
			std::cin >> contract[i].quantity;
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
		flag = true;
		while (flag)
		{
			std::cout << "\nEnter price per unit for " << i + 1 << " product: ";;
			std::cin >> contract[i].pricePerUnit;
			if (std::cin.fail())
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
		flag = true;
		while (flag)
		{
			std::cout << "\nEnter custom fee for  " << i + 1 << " product: ";;
			std::cin >> contract[i].customFee;
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
		contract[i].totalPrice = contract[i].quantity * contract[i].pricePerUnit;
		saveContractsToFile("contracts.txt");
	}
}
void printContractInformation()
{
	int i;
	printf("\n");
	printf("#\t%-20s\t%-10s\t%-10s\t%-15s\t%-12s\n", "Name", "Quantity", "Price", "Total price", "Custom fee");
	printf("***********************************************************************************************\n");
	for (i = 0; i < numberOfContracts; i++) {
		printf("%d\t%-20s\t%-10d\t%-10d\t%-15d\t%-12d\n", contract[i].contractNumber, contract[i].productName,
			contract[i].quantity, contract[i].pricePerUnit, contract[i].totalPrice, contract[i].customFee);
	}
	printf("\n");
	saveContractsToFile("contracts.txt");
}
void sortContractInformationByNumber()
{
	Contract temp;
	for (int i = 0; i < numberOfContracts; i++)
	{
		for (int j = 0; j < numberOfContracts - i - 1; j++)
		{
			if (contract[j].contractNumber > contract[j + 1].contractNumber)
			{
				temp = contract[j];
				contract[j] = contract[j + 1];
				contract[j + 1] = temp;
			}
		}
	}
	saveContractsToFile("contracts.txt");
}
void sortContractInformationByName()
{
	Contract temp;
	for (int i = 0; i < numberOfContracts; i++)
	{
		for (int j = 0; j < numberOfContracts - i - 1; j++)
		{
			if (strcmp(contract[j].productName,contract[j+1].productName)>0)
			{
				temp = contract[j];
				contract[j] = contract[j + 1];
				contract[j + 1] = temp;
			}
		}
	}
	saveContractsToFile("contracts.txt");
}
void addContractInformation()
{
	bool flag = true;
	while (flag)
	{
		std::cout << "\nEnter number of " << numberOfContracts + 1 << " contract: ";
		std::cin >> contract[numberOfContracts].contractNumber;
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
	std::cout << "\nEnter name of " << numberOfContracts + 1 << " product: ";;
	std::cin >> contract[numberOfContracts].productName;
	flag = true;
	while (flag)
	{
		std::cout << "\nEnter quantity of " << numberOfContracts + 1 << " product: ";
		std::cin >> contract[numberOfContracts].quantity;
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
	flag = true;
	while (flag)
	{
		std::cout << "\nEnter price per unit for " << numberOfContracts + 1 << " product: ";;
		std::cin >> contract[numberOfContracts].pricePerUnit;
		if (std::cin.fail())
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
	flag = true;
	while (flag)
	{
		std::cout << "\nEnter custom fee for  " << numberOfContracts + 1 << " product: ";;
		std::cin >> contract[numberOfContracts].customFee;
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
	contract[numberOfContracts].totalPrice = contract[numberOfContracts].quantity * contract[numberOfContracts].pricePerUnit;
	numberOfContracts++;
	saveContractsToFile("contracts.txt");
}
void changeContractInformation()
{
	int numberOfContractToChange;
	bool flag = true;
	while (flag)
	{
		std::cout << "\nEnter number of contract: ";
		std::cin >> numberOfContractToChange;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n______________________________________________\n";
			std::cout << "\n Invalid input. Try entering digits without space! \n";
			std::cout << "\n______________________________________________\n";
			continue;
		}
		else
			flag = false;
	}

	int contractIndex = -1;
	for (int i = 0; i < numberOfContracts; i++)
	{
		if (numberOfContractToChange == contract[i].contractNumber)
		{
			contractIndex = i;

		}
	}

	if (contractIndex != -1)
	{
		std::cout << "\nWhat do you want to change?";
		std::cout << "\n1. Name";
		std::cout << "\n2. Quantity";
		std::cout << "\n3. Price";
		std::cout << "\n4. Custom fee";
		int choice;
		flag = true;
		while (flag)
		{
			std::cout << "\nYour choice: ";
			std::cin >> choice;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n__________________________________________________\n";
				std::cout << "\n Invalid input. Try entering digits without space! \n";
				std::cout << "\n__________________________________________________\n";
				continue;
			}
			else
				flag = false;
		}

		switch (choice)
		{
		case 1:
		{
			std::cout << "\nNew name of product is: ";
			std::cin >> contract[contractIndex].productName;
		}
		break;
		case 2:
		{

			flag = true;
			while (flag)
			{
				std::cout << "\nNew quantity of product is: ";
				std::cin >> contract[contractIndex].quantity;
				if (std::cin.fail())
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
		}
		break;
		case 3:
		{
			flag = true;
			while (flag)
			{
				std::cout << "\nNew price per unit of product is: ";
				std::cin >> contract[contractIndex].pricePerUnit;
				if (std::cin.fail())
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
		}
		break;
		case 4:
		{
			flag = true;
			while (flag)
			{
				std::cout << "\nNew custom fee of product is: ";
				std::cin >> contract[contractIndex].customFee;
				if (std::cin.fail())
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
		}
		break;
		default:
			std::cout << "\n_________________________________\n";
			std::cout << "\n Invalid input. Try again!\n";
			std::cout << "\n_________________________________\n";
			break;
		}
	}
	else
	{
		std::cout << "\n_____________________________________________________\n";
		std::cout << "\n Invalid input. There is no contract with such number\n";
		std::cout << "\n_____________________________________________________\n";
	}
	saveContractsToFile("contracts.txt");
}
