#pragma once

#include <iostream>

class CustomVector
{
private:
	// 동적 배열의 시작 포인터
	int* startPointer;
	// 현재 요소 개수
	size_t size_;
	// 현재 할당된 용량의 크기
	size_t capacity_;

	void Reallocate(size_t newCapacity);

public:
	// 생성자
	CustomVector() : startPointer(nullptr), size_(0), capacity_(0) {}

	CustomVector(int size)
	{
		int* newData = new int[size];
		startPointer = newData;

		size_ = size;
		capacity_ = size;
	}

	// 소멸자
	~CustomVector() { delete[] startPointer; }

	// 현재 요소 개수 반환
	size_t size() const { return size_; }

	// 현재 할당된 용량의 크기 반환
	size_t capacity() const { return capacity_; }

	// 첫 번째 요소 반환
	int* begin() const { return startPointer; }

	// 마지막 요소 뒤를 반환
	int* end() const { return startPointer + size_; }

	void push_back(const int& value);

	int& operator[](size_t index)
	{
		if (index >= size_)
		{
			throw std::out_of_range("인덱스가 범위를 벗어났습니다.");
		}

		return startPointer[index];
	}
};

