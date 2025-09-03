#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class Buffer {
private:
    std::queue<T> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    int max_size;
public:
    Buffer(int size) : max_size(size) {}

    void addItem(T item) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return buffer.size() < max_size; });
        buffer.push(item);
        cv.notify_all();
    }

    T removeItem() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return !buffer.empty(); });
        T item = buffer.front();
        buffer.pop();
        cv.notify_all();
        return item;
    }

    int size() {
        std::lock_guard<std::mutex> lock(mtx);
        return buffer.size();
    }
};
