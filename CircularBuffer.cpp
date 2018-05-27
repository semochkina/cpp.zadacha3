#include <iostream>

using namespace std;

// кольцевой буфер (очередь на базе массива)
class CircularBuffer {
private:
	// указатель на динамический массив целых чисел
	int *mas;
	// размер массива
	int size = 0;
	// номер первого элемента (0 .. size-1)
	int elementBegin = 0;
	// количество заполненных элементов (0 .. size)
	int count = 0;

	// получить номер текущего элемента
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

	// получить элемент по номеру
	int get(const int currNumber) {
		return mas[elementCurr(currNumber)];
	}

	// добавить элемент в конец очереди (при переполнении - исключение)
	void push(int value) {
		if (count >= size) throw 101;
		int curr = elementCurr(count);
		mas[curr] = value;
		count++;
	}

	// вз€ть элемент в начале очереди (при отсутствии - исключение)
	int pop() {
		if (count == 0) throw 102;
		int value = mas[elementBegin];
		elementBegin = elementCurr(1);
		count--;
		return value;
	}

	// получить элемент в начале очереди (без его изъ€ти€)
	int getValue() {
		return mas[elementBegin];
	}

	// размер очереди
	int sizeQueue() {
		return size;
	};

	// сделать очередь пустой
	void clear() {
		elementBegin = count = 0;
	};

	// элементов в очереди
	int countQueue() {
		return count;
	};

	// проверка очереди на пустоту
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
