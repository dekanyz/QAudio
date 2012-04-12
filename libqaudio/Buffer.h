/***********************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - Buffer.h
 * -------------------------
 *
 * This is the base buffer class wich contains the buffer itself + some useful variables.
 *
 * On Linux, it is a jack_default_audio_sample_t kind of buffer.
 *
 * On Amiga, I'll see... ;)
***********************************************************************************************/

#ifndef __BUFFER_H
#define __BUFFER_H


#include <jack/jack.h>

#include <string>


class Buffer
{
    public:

        /* Constructor/Destructor */    
        Buffer( std::string id )
        {
            IsEmpty = true; 
            IsNotUsed = true; 
            BufferPtr = 0; 
            ID = id;
        }

        ~Buffer()
        {
          delete BufferPtr;
        }


        /* Class Data. */
        jack_default_audio_sample_t * BufferPtr;    // The audio/midi/controll data buffer.
                                                    // TODO: Probably this will be void *...

        bool IsEmpty;       // The effect will be skipped by execution because there is no data in the buffer.
                            // This is a nice optimalisation possibility for the given execution cycle.
        bool IsNotUsed;     // Buffer not linked to any effect's input. That means, that the effect, which
                            // sends it's output to this buffer will never used... and can be removed.
        std::string ID;     // BufferID
};


#endif
