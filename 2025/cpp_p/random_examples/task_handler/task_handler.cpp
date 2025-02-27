#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class JobScheduler {
public:
    JobScheduler() : running_(true) {
        worker_thread_ = std::thread(&JobScheduler::worker, this);
    }

    ~JobScheduler() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            running_ = false;
        }
        condition_.notify_one();
        worker_thread_.join();
    }

    void enqueueJob(std::function<void()> job) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            job_queue_.push(job);
        }
        condition_.notify_one();
    }

private:
    void worker() {
        while (true) {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                condition_.wait(lock, [this] { return !job_queue_.empty() || !running_; });

                if (!running_ && job_queue_.empty()) {
                    return;
                }

                if (!job_queue_.empty()) {
                    job = job_queue_.front();
                    job_queue_.pop();
                } else {
                    continue; //Spurious wakeup, but running_ is true, so loop again.
                }

            }
            if (job) {
                job();
            }
        }
    }

    std::queue<std::function<void()>> job_queue_;
    std::mutex queue_mutex_;
    std::condition_variable condition_;
    std::thread worker_thread_;
    bool running_;
};

// Example usage:
void job1() {
    std::cout << "Job 1 executed." << std::endl;
}

void job2(int value) {
    std::cout << "Job 2 executed with value: " << value << std::endl;
}

int main() {
    JobScheduler scheduler;

    scheduler.enqueueJob(job1);
    scheduler.enqueueJob(std::bind(job2, 42));
    scheduler.enqueueJob([]() { std::cout << "Lambda job executed." << std::endl; });

    // Simulate some work being done in the main thread
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // The JobScheduler destructor will join the worker thread,
    // ensuring all jobs are completed before the program exits.
    return 0;
}