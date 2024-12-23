#include "CustomMath.h"

int CustomMath::accumulate(int* first, int* last)
{
	int totalSum = 0;

	for (; first != last; ++first)
	{
		totalSum += *first;
	}

	return totalSum;
}

double CustomMath::calculateAverage(int totalSum, int count)
{
	if (count == 0) return 0;

	return totalSum / static_cast<double>(count);
}
