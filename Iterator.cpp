#include "CircularBuffer.cpp"

// �������� � �������������� CircularBuffer
class Iterator {
	CircularBuffer *circularBuffer;

public:
	Iterator(CircularBuffer *circularBuffer) : circularBuffer(circularBuffer) {
		start();
	}

	// ������ ������
	void start() {
		// CircularBuffer ������ ����� � ������
	}

	// �������� ��������� �������
	int getValue() {
		return circularBuffer->getValue();
	}

	// �������� �������� �� ��������� �������
	void next() {
		if (!finish()) {
			circularBuffer->pop();
		}
	}

	// �������� ��� �� ��������������
	bool finish() {
		return circularBuffer->isEmpty();
	};

	friend ostream &operator<<(ostream &os, Iterator &iterator) {
		os << "elements";
		for (; !iterator.finish(); iterator.next())
			os << ", " << iterator.getValue();
		return os;
	}

};