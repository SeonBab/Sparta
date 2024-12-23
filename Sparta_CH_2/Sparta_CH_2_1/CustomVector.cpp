#include "CustomVector.h"
#include <algorithm>

void CustomVector::Reallocate(size_t newCapacity)
{
	int* newData = new int[newCapacity];
	std::copy(startPointer, startPointer + size_, newData);
	delete[] startPointer;
	startPointer = newData;
	capacity_ = newCapacity;
}

void CustomVector::push_back(const int& value)
{
	if (size_ == capacity_)
	{
		size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
		Reallocate(newCapacity);
	}

	startPointer[size_++] = value;
}
