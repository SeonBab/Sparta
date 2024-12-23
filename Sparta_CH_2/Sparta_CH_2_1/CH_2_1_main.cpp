#include <iostream>

#include "CustomVector.h"
#include "CustomMath.h"

void InputNumber(CustomVector& NumberArr)
{
	int maxInput;

	std::cout << "�Է��Ϸ��� ������ ������ �Է����ּ���" << std::endl;
	std::cin >> maxInput;

	for (int i = 0; i < maxInput; ++i)
	{
		int inputValue = 0;

		std::cout << i << " ��° ������ ���� �Է����ּ���. : ";
		std::cin >> inputValue;

		NumberArr.push_back(inputValue);
	}

	std::cout << "������ �Է��� ���ƽ��ϴ�." << std::endl;
	std::cout << "=================================" << std::endl;

}

int main()
{
	CustomVector NumberArr{};

	InputNumber(NumberArr);

	int totalSum = CustomMath::accumulate(NumberArr.begin(), NumberArr.end());

	double average = CustomMath::calculateAverage(totalSum, NumberArr.size());

	std::cout << "���ڵ��� �����Դϴ�. : " << totalSum << std::endl;

	std::cout << "���ڵ��� ����Դϴ�. : " << average << std::endl;
}