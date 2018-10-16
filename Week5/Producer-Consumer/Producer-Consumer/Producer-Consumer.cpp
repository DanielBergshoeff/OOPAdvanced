// Producer-Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int c = 0;
bool done = false;
std::queue<int> goods;
std::condition_variable flag;
std::mutex consumer_mutex;

void producer() {
	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		c++;
		flag.notify_one();
	}

	done = true;
}

void consumer() {
	std::unique_lock<std::mutex> lock(consumer_mutex);
	while (!done) {
		flag.wait(lock);
		while (!goods.empty()) {
			goods.pop();
			c--;
		}
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();
	std::cout << "Net: " << c << std::endl;

	char c;
	std::cin >> c;
}
