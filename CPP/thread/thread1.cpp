#include <cstdlib>
#include <iostream>
#include <memory>
 
#include <pthread.h>

using namespace std;
 
class Thread
{
private:
    pthread_t thread;
 
    Thread(const Thread& copy);         // copy constructor denied
    static void *thread_func(void *d)   { ((Thread *)d)->run(); }
 
public:
    Thread()             {}
    virtual ~Thread()    {}
 
    virtual void run() = 0;
 
    int start()          { return pthread_create(&thread, NULL,
                           Thread::thread_func, (void*)this); }
    int wait ()          { return pthread_join  (thread, NULL); }
};
 
typedef auto_ptr<Thread> ThreadPtr;
 
int main() {
    class Thread_a:public Thread
    {
    public:
        void run()
        {
            for (int i=0; i<20; i++)
                cout << "a  " << endl;
        }
    };
 
    class Thread_b:public Thread
    {
    public:
        void run()
        {
            for(int i=0; i<20; i++)
                cout << "  b" << endl;
        }
    };
 
    ThreadPtr a( new Thread_a() );
    ThreadPtr b( new Thread_b() );
 
    if (a->start() != 0 || b->start() != 0)
        return EXIT_FAILURE;
 
    if (a->wait() != 0 || b->wait() != 0)
        return EXIT_FAILURE;
 
    return EXIT_SUCCESS;
}