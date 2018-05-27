#include "CircularBuffer.cpp"

// итератор с использованием CircularBuffer
class Iterator {

	CircularBuffer *circularBuffer;
	// количество заполненных элементов
	int count;
	// номер текущего элемента
	int curr;

public:
	Iterator(CircularBuffer *circularBuffer) : circularBuffer(circularBuffer) {
		start();
	}

	// начать работу
	void start() {
		count = circularBuffer->countQueue();
		curr = 0;
	}

	// получить очередной элемент
	int getValue() {
		return circularBuffer->get(curr);
	}

	// сдвинуть итератор на следующий элемент
	void next() {
		if (!finish()) {
			curr++;
		}
	}

	// проверка все ли проитерировано
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