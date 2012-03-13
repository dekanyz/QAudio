/*****************************************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - BufferPool.c
 * -------------------------
 *
 * Implementation of BufferPool's functions
 ****************************************************************************************************************/

#include "BufferPool.h"
#include "Jack.h"


BufferPool::BufferPool()  
{
    // TODO: Get the buffer size from jack engine!
    BufferSize = BuffersCount = 0; 
    MemPtr = 0;

    return;
}


BufferPool::~BufferPool() 
{ 
    delete MemPtr; 

    return;
}


void BufferPool::createBuffer( std::string id )
{
    queue.push_back( Buffer( id ) );
    ++BuffersCount;

    return;
}


const Buffer & BufferPool::getBuffer( std::string id ) const
{
    for (std::vector<Buffer>::const_iterator it = queue.begin();
         it != queue.end();
         ++it)
    {
        if (it->ID == id) 
          return *it;
    }

    // TODO: This case is an internal error... Throw an exception...
    // TODO: ...or something!!
}


void BufferPool::clearBuffers() 
{ 
    std::fill( MemPtr, MemPtr + (BufferSize * BuffersCount), 0 );

    return;
}


void BufferPool::allocateBuffersMemory() 
{ 
    MemPtr = new (jack_default_audio_sample_t)(BuffersCount * BufferSize); 
    jack_default_audio_sample_t * tmpPtr = MemPtr;
    std::vector<Buffer>::iterator it = queue.begin();

    for (int i=0; i<BuffersCount; ++i)
    {
        it->BufferPtr = tmpPtr;
        tmpPtr += BufferSize;
        ++it;
    }

    return;
}


void BufferPool::freeBuffersMemory() 
{ 
    delete MemPtr; 

    return;
}


void BufferPool::setBufferSize( int newSize ) 
{ 
    BufferSize = newSize; 

    return; 
}


int BufferPool::getBufferSize() 
{ 
    return BufferSize; 
}


void BufferPool::resizeBuffers( int newSize ) 
{ 
    freeBuffersMemory(); 
    setBufferSize( newSize ); 
    allocateBuffersMemory(); 
    
    return; 
}


void BufferPool::deleteAll()
{
    freeBuffersMemory();
    BuffersCount = 0;
    queue.erase( queue.begin(), queue.end() );

    return;
}


void BufferPool::setAllEmptyFlags()
{
    for (std::vector<Buffer>::iterator it = queue.begin();
         it != queue.end();
         ++it)
    {
        it->IsEmpty = true;
    }
    
}

