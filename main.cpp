#include <iostream>
#include <vector>
#include <thread>
#include "Buffer.h"
#include "ProducerConsumer.h"

int main() {
    int bufferSize, numProducers, numConsumers, itemsPerProducer;
    std::cout << "Enter buffer size: ";
    std::cin >> bufferSize;
    std::cout << "Enter number of producers: ";
    std::cin >> numProducers;
    std::cout << "Enter number of consumers: ";
    std::cin >> numConsumers;
    std::cout << "Enter number of items each producer will produce: ";
    std::cin >> itemsPerProducer;

    Buffer<int> buffer(bufferSize);
    std::vector<std::thread> threads;

    for (int i = 1; i <= numProducers; ++i) {
        Producer p(i, buffer, itemsPerProducer);
        threads.push_back(std::thread(&Producer::produce, p));
    }

    int totalItems = numProducers * itemsPerProducer;
    int itemsPerConsumer = totalItems / numConsumers;
    for (int i = 1; i <= numConsumers; ++i) {
        Consumer c(i, buffer, itemsPerConsumer);
        threads.push_back(std::thread(&Consumer::consume, c));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All tasks completed. Exiting program." << std::endl;
    return 0;
}
