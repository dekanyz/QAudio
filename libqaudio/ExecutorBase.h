/***********************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - Buffer.h
 * -------------------------
 *
 * This class is the base of the executors.
 *
 * The executors will pick walk trough the effects and call their exec() function, which is the
 * main executor function of their task. 
 *
 * An executor can be internal or external.
 *
 * The internal executor will simply walk trough the effect tree and call every exec() function.
 *
 * The external executor is much more complex. It's main task is to make the tree executed by 
 * slaves connected on TCP IP wires. It have to do the following tasks:
 *      - Handle connections 
 *      - Send the effect config xml 
 *      - Send the input buffer(s) of the effects
 *      - Receive the output buffer(s)
 **********************************************************************************************/

#ifndef __EXECUTOR_BASE
#define __EXECUTOR_BASE


class ExecutorBase
{
    public:

        /* Sets the executor to the received object.
         * There can be only one existing executor. 
         * If it stores one yet, it will destroy it before replacing. */
        static void setExecutor( ExecutorBase *  newExecutor )
        {
            if (executor) delete executor;
            executor = newExecutor;
        }

        /* Returns the stored  executor */
        static ExecutorBase * getExecutor()
        {
            return executor;
        }
        

        // Virtual functions
        /* Reimplement this function!
         * This will be the main executor function. */
        virtual void ExecuteAll() = 0;

    private:

        static ExecutorBase * executor;
}


static ExecutorBase * executor = 0;


#endif
