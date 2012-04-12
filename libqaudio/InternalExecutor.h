#ifndef __INTERNAL_EXECUTOR
#define __INTERNAL_EXECUTOR

#include "ExecutorBase.h"


class InternalExecutor : public ExecutorBase
{
    InternalExecutor()
    {
        setExecutor( *this );
    }
}


#endif
