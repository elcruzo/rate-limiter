#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

class RateLimiter {
public:
    RateLimiter(double rate, int burst) : rate(rate), burst(burst), tokens(burst) {
        lastRefill = high_resolution_clock::now();
        refillThread = thread(&RateLimiter::refillTokens, this);
    }

    ~RateLimiter() {
        refillThread.join();
    }

    bool allow() {
        refillTokens();
        unique_lock<mutex> lock(mutex);
        if (tokens >= 1) {
            tokens--;
            return true;
        }
        return false;
    }

private:
    double rate; 
    int burst; 
    int tokens; 
    high_resolution_clock::time_point lastRefill;
    mutex mutex;
    thread refillThread;

    void refillTokens() {
        while (true) {
            this_thread::sleep_for(chrono::milliseconds(100)); // Refill interval
            unique_lock<mutex> lock(mutex);
            auto now = high_resolution_clock::now();
            auto elapsed = now - lastRefill;
            int tokensToAdd = static_cast<int>(duration_cast<chrono::milliseconds>(elapsed).count() * rate / 1000);
            tokens = min(tokens + tokensToAdd, burst);
            lastRefill = now;
        }
    }
};

int main() {
    RateLimiter limiter(2, 5);

    for (int i = 0; i < 10; i++) {
        if (limiter.allow()) {
            cout << "Request " << i << " is allowed." << endl;
        } else {
            cout << "Request " << i << " is rate limited." << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}
