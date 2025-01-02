#include <iostream>

#include "CustomVector.h"

// CH2 간단한 프로그래밍 구현 1번 필수 과제

// 입력을 받는 함수
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

// 정수의 총합을 구하는 함수
int accumulate(int* first, int* last)
{
	int totalSum = 0;

	for (; first != last; ++first)
	{
		totalSum += *first;
	}

	return totalSum;
}

// 평균을 구하는 함수
double calculateAverage(int totalSum, int count)
{
	if (count == 0) return 0;

	return totalSum / static_cast<double>(count);
}

int main()
{
	CustomVector NumberArr{};

	InputNumber(NumberArr);

	int totalSum = accumulate(NumberArr.begin(), NumberArr.end());

	double average = calculateAverage(totalSum, NumberArr.size());

	std::cout << "숫자들의 총합입니다. : " << totalSum << std::endl;

	std::cout << "숫자들의 평균입니다. : " << average << std::endl;
}