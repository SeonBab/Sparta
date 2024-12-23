#include <iostream>

#include "CustomVector.h"
#include "CustomMath.h"

void InputNumber(CustomVector& NumberArr)
{
	int maxInput;

	std::cout << "입력하려는 정수의 갯수를 입력해주세요" << std::endl;
	std::cin >> maxInput;

	for (int i = 0; i < maxInput; ++i)
	{
		int inputValue = 0;

		std::cout << i << " 번째 정수의 값을 입력해주세요. : ";
		std::cin >> inputValue;

		NumberArr.push_back(inputValue);
	}

	std::cout << "정수의 입력을 마쳤습니다." << std::endl;
	std::cout << "=================================" << std::endl;

}

int main()
{
	CustomVector NumberArr{};

	InputNumber(NumberArr);

	int totalSum = CustomMath::accumulate(NumberArr.begin(), NumberArr.end());

	double average = CustomMath::calculateAverage(totalSum, NumberArr.size());

	std::cout << "숫자들의 총합입니다. : " << totalSum << std::endl;

	std::cout << "숫자들의 평균입니다. : " << average << std::endl;
}