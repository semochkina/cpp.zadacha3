#include <iostream>

using namespace std;

// ��������� ����� (������� �� ���� �������)
class CircularBuffer {
private:
	// ��������� �� ������������ ������ ����� �����
	int *mas;
	// ������ �������
	int size = 0;
	// ����� ������� �������� (0 .. size-1)
	int elementBegin = 0;
	// ���������� ����������� ��������� (0 .. size)
	int count = 0;

	// �������� ����� �������� ��������
	int elementCurr(const int currNumber) {
		int number = currNumber + elementBegin;
		return number >= size ? number - size : number;
	}

public:
	CircularBuffer(int size) : size(size) {
		mas = new int[size];
	}

	~CircularBuffer() {
		delete mas;
	}

	// �������� ������� �� ������
	int get(const int currNumber) {
		return mas[elementCurr(currNumber)];
	}

	// �������� ������� � ����� ������� (��� ������������ - ����������)
	void push(int value) {
		if (count >= size) throw 101;
		int curr = elementCurr(count);
		mas[curr] = value;
		count++;
	}

	// ����� ������� � ������ ������� (��� ���������� - ����������)
	int pop() {
		if (count == 0) throw 102;
		int value = mas[elementBegin];
		elementBegin = elementCurr(1);
		count--;
		return value;
	}

	// �������� ������� � ������ ������� (��� ��� �������)
	int getValue() {
		return mas[elementBegin];
	}

	// ������ �������
	int sizeQueue() {
		return size;
	};

	// ������� ������� ������
	void clear() {
		elementBegin = count = 0;
	};

	// ��������� � �������
	int countQueue() {
		return count;
	};

	// �������� ������� �� �������
	bool isEmpty() {
		return count == 0;
	};

	friend ostream &operator<<(ostream &os, CircularBuffer &element) {
		os << " size: " << element.size << " count: " << element.count << "   elements";
		for (int i = 0; i < element.count; i++)
			os << ", " << element.mas[element.elementCurr(i)];
		return os;
	}

    friend std::istream &operator>>(std::istream &is, CircularBuffer &element) {
        std::cout << "set " << element.size << " values:\n";
        for (int i = 0; i < element.size; i++) {
            std::cout << "mas[" << i << "] > ";
            int m;
            is >> m;
            element.push(m);
        }
        return is;
    }
};
