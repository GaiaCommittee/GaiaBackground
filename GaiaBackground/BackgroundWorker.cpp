#include "BackgroundWorker.hpp"

namespace Gaia::Background
{
    /// Bind the lambda function to this background worker.
    BackgroundWorker::BackgroundWorker(std::function<void(const std::atomic_bool&)> function):
        ThreadFlag(false), ThreadFunction(std::move(function))
    {}

    /// Stop the background worker and destruct.
    BackgroundWorker::~BackgroundWorker()
    {
        ThreadFlag = false;
        if (ThreadToken.valid())
        {
            ThreadToken.get();
        }
    }

    /// Start the background task.
    void BackgroundWorker::Start()
    {
        if (IsRunning()) return;
        ThreadFlag = true;
        ThreadToken = std::async(std::launch::async,
                                 [function = this->ThreadFunction, flag = &this->ThreadFlag]{
            function(*flag);
            flag->store(false);
        });
    }

    /// Stop the background task.
    void BackgroundWorker::Stop()
    {
        if (!IsRunning()) return;
        ThreadFlag = false;
        if (ThreadToken.valid())
        {
            ThreadToken.get();
        }
    }

    /// Check whether the background working thread is running or not.
    bool BackgroundWorker::IsRunning()
    {
        return ThreadFlag;
    }
}