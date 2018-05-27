#include "CircularBuffer.cpp"

// �������� � �������������� CircularBuffer
class Iterator {

	CircularBuffer *circularBuffer;
	// ���������� ����������� ���������
	int count;
	// ����� �������� ��������
	int curr;

public:
	Iterator(CircularBuffer *circularBuffer) : circularBuffer(circularBuffer) {
		start();
	}

	// ������ ������
	void start() {
		count = circularBuffer->countQueue();
		curr = 0;
	}

	// �������� ��������� �������
	int getValue() {
		return circularBuffer->get(curr);
	}

	// �������� �������� �� ��������� �������
	void next() {
		if (!finish()) {
			curr++;
		}
	}

	// �������� ��� �� ��������������
	bool finish() {
		return curr >= count;
	};

	friend ostream &operator<<(ostream &os, Iterator &iterator) {
		os << "elements";
		for (iterator.start(); !iterator.finish(); iterator.next())
			os << ", " << iterator.getValue();
		return os;
	}

};