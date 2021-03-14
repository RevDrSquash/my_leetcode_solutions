// https://leetcode.com/problems/fizz-buzz-multithreaded/

class FizzBuzz
{
private:
    const int n;
    std::atomic<int> a;
    
    std::atomic<short> counter;
    std::mutex mutex;
    std::condition_variable next;
    
    void waitForReady()
    {
        if (++counter == 4)
        {
            counter.store(0);
            ++a;
            next.notify_all();
        }
        else
        {
            std::unique_lock<std::mutex> lk(mutex);
            next.wait(lk);
        }
    }
    
public:
    FizzBuzz(int n) : n(n), a(std::atomic(1)), counter(std::atomic(0))
    {
        
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while(a<=n)
        {
            if(a % 3 == 0 && a % 5 != 0)
            {
                printFizz();
            }
            
            waitForReady();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while(a<=n)
        {
            if(a % 5 == 0 && a % 3 != 0)
            {
                printBuzz();
            }
            
            waitForReady();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz)
    {
        while(a<=n)
        {
            if(a % 3 == 0 && a % 5 == 0)
            {
                printFizzBuzz();
            }
            
            waitForReady();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while(a<=n)
        {
            if(a % 3 != 0 && a % 5 != 0)
            {
                printNumber(a);
            }
            
            waitForReady();
        }
    }
};
