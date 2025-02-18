#include <iostream>

#include "CustomVector.h"

// CH2 간단한 프로그래밍 구현 1번 도전 과제

// 입력을 받는 함수
void InputNumber(CustomVector& NumberArr, int& sortOrder)
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

	std::cout << "오름차순 1 내림차순 2" << std::endl;
	std::cout << "어떻게 정렬하시겠습니까?" << std::endl;
	std::cin >> sortOrder;
}

// 병함 정렬을 위해 배열을 합치고 정렬하는 함수
void merge(CustomVector& array, int left, int mid, int right, int sortOrder)
{
	// 임시 배열의 크기
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// 임시 배열 생성
	CustomVector L(n1), R(n2);
	for (int i = 0; i < n1; ++i)
	{
		L[i] = array[left + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		R[j] = array[mid + j + 1];
	}

	// 임시 배열의 값으로 정렬 후 원본 배열의 값 수정
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (sortOrder == 1)
		{
			(L[i] <= R[j]) ? array[k++] = L[i++] : array[k++] = R[j++];
		}
		else
		{
			(L[i] >= R[j]) ? array[k++] = L[i++] : array[k++] = R[j++];
		}

	}

	// 임시 배열의 남은 값 대입
	while (i < n1)
	{
		array[k++] = L[i++];
	}
	while (j < n2)
	{
		array[k++] = R[j++];
	}
}

// 병합 정렬을 위해 배열을 분리하는 함수
void mergeSort(CustomVector& array, int left, int right, int sortOrder)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(array, left, mid, sortOrder);
		mergeSort(array, mid + 1, right, sortOrder);
		merge(array, left, mid, right, sortOrder);
	}
}

// 출력하는 함수
void PrintResult(CustomVector& NumberArr)
{
	for (int i = 0; i < NumberArr.size(); ++i)
	{
		std::cout << NumberArr[i];

		if (i + 1 != NumberArr.size())
		{
			std::cout << ", ";
		}
	}
}

int main()
{
	CustomVector NumberArr{};
	int sortOrder;

	InputNumber(NumberArr, sortOrder);

	mergeSort(NumberArr, 0, NumberArr.size() - 1, sortOrder);

	PrintResult(NumberArr);
}