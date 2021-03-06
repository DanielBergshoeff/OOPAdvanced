// Producer-Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <string>

int c = 0;
bool done = false;
std::queue<int> goods;
std::condition_variable flag;
std::mutex consumer_mutex;
std::mutex stream_mutex;

void information(std::string s, std::thread::id id) {
	std::lock_guard<std::mutex> lock(stream_mutex);
	std::cout << s << " from thread " << id << std::endl;
}

void producer() {
	std::thread::id this_id = std::this_thread::get_id();

	for (int i = 0; i < 1000; ++i) {
		
		std::lock_guard<std::mutex> lock(consumer_mutex);
		goods.push(i);
		c++;
		information("Added nr. " + std::to_string(i), this_id);
		flag.notify_all();
	}
}

void consumer() {
	std::thread::id this_id = std::this_thread::get_id();
	while (!done) {
		std::lock_guard<std::mutex> lock(consumer_mutex);
		while (!goods.empty()) {
			int i = goods.front();
			goods.pop();
			c--;
			information("Removed nr. " + std::to_string(i), this_id);
		}
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread producerThread2(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	producerThread2.join();

	done = true;

	consumerThread.join();
	std::cout << "Net: " << c << std::endl;

	char c;
	std::cin >> c;
}
