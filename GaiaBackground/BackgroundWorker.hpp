#pragma once

#include <functional>
#include <future>
#include <atomic>

namespace Gaia::Background
{
    /**
     * @brief Background worker represents a working thread of a lambda function in the background.
     */
    class BackgroundWorker
    {
    protected:
        /// Token for the background thread.
        std::future<void> ThreadToken;
        /// Life flag for the background thread.
        std::atomic_bool ThreadFlag;
        /// Working lambda function for the background thread.
        std::function<void(const std::atomic_bool&)> ThreadFunction;

    public:
        /**
         * @brief Bind the lambda function to this background worker.
         * @param function The working function for the background worker to invoke.
         * @details
         *  The parameter of the working function is the life flag for the background thread,
         *  Stop() function will directly set false to this life flag,
         *  so the working function is expected to exit when it find the life flag is false.
         */
        explicit BackgroundWorker(std::function<void(const std::atomic_bool&)> function);

        /// Stop the background worker and destruct.
        virtual ~BackgroundWorker();

        /**
         * @brief Start the background task.
         */
        virtual void Start();
        /**
         * @brief Stop the background task.
         * @attention Whether the background task can be stopped or not,
         *            depends on the implementation of the worker lambda function.
         * @details
         *  Usually the background task can not terminate immediately,
         *  and this function will block the invoker until background thread exits.
         */
        virtual void Stop();
        /**
         * @brief Check whether the background working thread is running or not.
         * @return The value of ThreadFlag.
         */
        bool IsRunning();
    };
}