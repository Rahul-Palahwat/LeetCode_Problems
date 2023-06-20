template<int COUNT_MAX>
class counting_semaphore
{
    std::atomic<int> val_ {};
  public:
    
    counting_semaphore(int val = 0): val_(val)
    {
        if (val_ < 0) val_ = 0;
        else if (val_ > COUNT_MAX) val_ = COUNT_MAX;
    }
    
    void acquire()
    {
        while (val_ == 0) std::this_thread::yield();
        --val_;    
    }
    
    void release()
    {
        if (val_ < COUNT_MAX)
            ++val_;
    }
};

class DiningPhilosophers {
    
    std::array<std::mutex, 5> forks;
    counting_semaphore<4> sem {4};
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
	    int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        sem.acquire();
        std::lock_guard<std::mutex> l(forks[left]);
        std::lock_guard<std::mutex> r(forks[right]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        sem.release();
    }
};