/*****************************************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - Jack.c
 * -------------------------
 *
 * Implementation of Jack functions.
 ****************************************************************************************************************/

#include "Jack.h"

// These C functions will be used.
extern "C" {
    jack_client_t *jack_client_new( const char *client_name );
    int jack_set_process_callback(jack_client_t *client, JackProcessCallback process_callback, void *arg);
    int jack_set_sample_rate_callback(jack_client_t *client, JackSampleRateCallback srate_callback, void *arg);
    void jack_on_shutdown(jack_client_t *client, JackShutdownCallback function, void *arg);
    int jack_set_buffer_size_callback(jack_client_t *client, JackBufferSizeCallback bufsize_callback, void *arg);
    void jack_set_error_function(void (*func)(const char *));
    jack_port_t* jack_port_register(jack_client_t *client, const char *port_name, const char *port_type, unsigned long flags, unsigned long buffer_size);
    int jack_activate(jack_client_t *client);
    void* jack_port_get_buffer(jack_port_t *, jack_nframes_t);
    };

using namespace jack;

// Member functions
void Jack::registerCallbackProcess( int (*cb)(jack_nframes_t nframes, void *arg) )
{
}


void Jack::registerCallbackSampleRateChange( int (*cb)(jack_nframes_t nframes, void *arg) )
{
}


void Jack::registerCallbackBufferSizeChanged( int (*cb)(jack_nframes_t nframes, void *arg) )
{
}


void Jack::registerCallbackShutdown( void (*cb)(void *arg) )
{
}


void Jack::registerCallbackError( void (*cb)(const char *) )
{
}


void Jack::createAudioInPort ( std::string ID )
{
}


void Jack::createAudioOutPort( std::string ID )
{
}


void Jack::createMidiInPort  ( std::string ID )
{
}


void Jack::createMidiOutPort ( std::string ID )
{
}



void Jack::jackActivate()
{
    jack_activate( Client );
}



void Jack::getBuffers()
{
}


void registerCallbackFreewhel( void (*cb)(int starting, void *arg) )
{
    // TODO!
}


void registerCallbackClientRegistration( void (*cb)(const char* name, int register, void *arg) )
{
    // TODO!
}


void registerCallbackPortRegistration( void (*cb)(jack_port_id_t port, int register, void *arg) )
{
    // TODO!
}


void registerCallbackPortConnection( void (*cb)(jack_port_id_t a, jack_port_id_t b, int connect, void* arg) )
{
    // TODO!
}


void registerCallbackGraphOrder( int (*cb)(void *arg) )
{
    // TODO!
}


void registerCallbackXRun( int (*cb)(void *arg) )
{
    // TODO!
}


void registerCallbackLatency( void (*cb)(jack_latency_callback_mode_t mode, void *arg) )
{
    // TODO!
}


void registerCallbackThreadInit( void (*cb)(void *arg) )
{
    // TODO!
}

