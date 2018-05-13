#include "CircularBuffer.cpp"

// итератор с использованием CircularBuffer
class Iterator {
	CircularBuffer *circularBuffer;

public:
	Iterator(CircularBuffer *circularBuffer) : circularBuffer(circularBuffer) {
		start();
	}

	// начать работу
	void start() {
		// CircularBuffer всегда готов к работе
	}

	// получить очередной элемент
	int getValue() {
		return circularBuffer->getValue();
	}

	// сдвинуть итератор на следующий елемент
	void next() {
		if (!finish()) {
			circularBuffer->pop();
		}
	}

	// проверка все ли проитерировано
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