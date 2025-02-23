#include <iostream>
#include <stdio.h>
#include <string.h>

struct Contract
{
	int contractNumber;
	char goodsName[50];
	int quantity;
	int pricePerUnit;
	int totalPrice;
	int customFee;
};

static Contract contract[5];

int numberOfContracts;

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
		std::cin >> contract[i].goodsName;
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
			if (std::cin.fail()|| std::cin.peek() != '\n')
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
	}
}
void printContractInformation()
{
	int i;
	printf("\n");
	printf("#\t%-20s\t%-10s\t%-10s\t%-15s\t%-12s\n", "Name", "Quantity", "Price", "Total price", "Custom fee");
	printf("***********************************************************************************************\n");
	for (i = 0; i < numberOfContracts; i++) {
		printf("%d\t%-20s\t%-10d\t%-10d\t%-15d\t%-12d\n", contract[i].contractNumber, contract[i].goodsName,
			contract[i].quantity, contract[i].pricePerUnit, contract[i].totalPrice, contract[i].customFee);
	}
	printf("\n");
}
void sortContractInformation()
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

}
