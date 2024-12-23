#pragma once

class CustomVector;

class CustomMath
{
public:
	// 누적 합을 구하는 함수
	static int accumulate(int* first, int* last);

	static double calculateAverage(int totalSum, int count);
};

