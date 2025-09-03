#pragma once
#include "Buffer.h"
#include <thread>
#include <iostream>
#include <chrono>

class Producer {
private:
    int id;
    Buffer<int>& buffer;
    int itemsToProduce;
public:
    Producer(int _id, Buffer<int>& _buffer, int _items) 
        : id(_id), buffer(_buffer), itemsToProduce(_items) {}

    void produce() {
        for (int i = 1; i <= itemsToProduce; ++i) {
            buffer.addItem(i);
            std::cout << "[Producer " << id << "] produced item: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

class Consumer {
private:
    int id;
    Buffer<int>& buffer;
    int itemsToConsume;
public:
    Consumer(int _id, Buffer<int>& _buffer, int _items)
        : id(_id), buffer(_buffer), itemsToConsume(_items) {}

    void consume() {
        for (int i = 0; i < itemsToConsume; ++i) {
            int item = buffer.removeItem();
            std::cout << "[Consumer " << id << "] consumed item: " << item << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    }
};
