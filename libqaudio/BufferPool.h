/***********************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - BufferPool.h
 * -------------------------
 *
 * BufferPool class contains all the needed functions for buffer handling:
 * - Create a new Buffer
 * - Get a Buffer
 * - Allocate memory for audio data
 * - Deallocate memory for audio data
 * - Clearing audio data
 **********************************************************************************************/

#ifndef __BUFFER_POOL_H
#define __BUFFER_POOL_H


#include "Buffer.h"

#include <vector>
#include <cstdlib>
#include <string>


class BufferPool
{
    public:   // TODO: Make this class Singleton

        /* Constructor - Destructor */
        BufferPool();
        ~BufferPool();


        /* Create a new buffer data.
         * id     - Buffer ID. */
        void createBuffer( std::string id );

        /* Get the pointer to a buffer data.
         * Other thing is, that the IsNotUsed flag will be set to false.
         * This method is called, when the effect doesn't have any valid pointer
         * to any mamory area and needs one. This also means, that the buffer will be used.
         * id   - Buffer ID
         * ret  - Pointer to created buffer */
        const Buffer & getBuffer( std::string id ) const;

        /* Clear all buffer's memory area.
         * (Fill up with zeros) */
        void clearBuffers(); 

        /* Allocate memory for buffers.
         * The createBuffer() function doesn't allocate 
         * any memory for the buffers, just the 'Buffer' 
         * data structure is created. The memory allocation 
         * is the last step, when the count/size of the
         * buffers is known. */
        void allocateBuffersMemory();

        /* Deallocating memory for buffers. 
         * Free up the allocated buffer area.
         * (Example: Jack buffer size has changed) */
        void freeBuffersMemory();

        /* Sets the buffer's size. 
         * size - Buffer size in bytes */
        void setBufferSize( int newSize );

        /* Gets the buffer's size.
         * ret - The buffer size */
        int getBufferSize();

        /* Resize all the buffers.
         * newSize - This will be the new buffer size */
        void resizeBuffers( int newSize );

        /* Set the empty flag to every buffer. */
        void setAllEmptyFlags();

        /* Delete all the buffers structure */
        void deleteAll();

        /* Get back the object pointer.
         * Because, I don't want to pass the pointer to every class,
         * this will be a static function.
         * TODO: Is this solution fine??? */
        static BufferPool * getInstance();

    private:

        int BufferSize;
        int BuffersCount;
        jack_default_audio_sample_t * MemPtr;
        std::vector<Buffer> queue;
};

#endif 
