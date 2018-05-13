#include "Iterator.cpp"

int main() {
    CircularBuffer buf(5);
    std::cout << "sizeQueue() - " << buf.sizeQueue() << std::endl;
    std::cout << "countQueue() - " << buf.countQueue() << std::endl;
    std::cout << "isEmpty() - " << buf.isEmpty() << std::endl;
    std::cin >> buf;

	std::cout << "Izvlekaem znachenie steka - " << buf.pop() << std::endl;

	int i = 9;
	std::cout << "Kladem v stek - " << i << std::endl;
    buf.push(i);

    std::cout << "Begin value - " << buf.getValue() << std::endl;

    std::cout << "CircularBuffer - " << buf << std::endl;

    Iterator iterator(&buf);
	std::cout << "Iterator =";
	for (iterator.start(); !iterator.finish(); iterator.next())
		std::cout << " " << iterator.getValue();
    //std::cout << "\nIterator - " << iterator << std::endl;

    std::cin.get();
    std::cin.get();
    return 0;
}