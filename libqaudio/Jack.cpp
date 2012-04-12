/*****************************************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - Jack.c
 * -------------------------
 *
 * Implementation of Jack functions.
 ****************************************************************************************************************/

#include "Jack.h"
#include "Messages.h"


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
    int jack_port_unregister( jack_client_t *, jack_port_t * );
};

using namespace jack;


// Constructors
Jack::Jack()
{ 
//    Jack( string( "Unnamed C++ project" ) );
}


Jack::Jack( std::string name )
{
    // TODO: This is the deprecated interface.
    // TODO: Replace it with jack_client_open()!!
    
    if ((Client = jack_client_new( name.c_str() )) == 0)
       ERROR2( "JACK:", "Jack opening error." );
}


// Member functions
// The callbacks handling first
void Jack::registerCallbackProcess( int (*cb)(jack_nframes_t nframes, void *arg) )
{
    if (0 != jack_set_process_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'Process\' callback" );
}


void Jack::registerCallbackSampleRateChange( int (*cb)(jack_nframes_t nframes, void *arg) )
{
    if (0 != jack_set_sample_rate_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'Sample Rate\' callback" );
}


void Jack::registerCallbackBufferSizeChanged( int (*cb)(jack_nframes_t nframes, void *arg) )
{
    if (0 != jack_set_buffer_size_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'SAmple Rate\' callback" );
}


void Jack::registerCallbackShutdown( void (*cb)(void *arg) )
{
    jack_on_shutdown( Client, cb, 0 );
}


void Jack::registerCallbackError( void (*cb)(const char *) )
{
    jack_set_error_function( cb ); 
}


void Jack::registerCallbackFreewhel( void (*cb)(int starting, void *arg) )
{
    if (0 != jack_set_freewheel_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'Freewheel\' callback" );
}


void Jack::registerCallbackClientRegistration( void (*cb)(const char* name, int register, void *arg) )
{
   if (0 != jack_set_client_registration_callback( Client, cb, 0 ))
       ERROR2( "JACK:", "Unable to set the \'Client Registration\' callback" );
}


void Jack::registerCallbackPortRegistration( void (*cb)(jack_port_id_t port, int register, void *arg) )
{
    if (0 != jack_set_port_registration_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'Port Registration\' callback" );
}


void Jack::registerCallbackPortConnection( void (*cb)(jack_port_id_t a, jack_port_id_t b, int connect, void* arg) )
{
    if (0 != jack_set_port_connect_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set the \'Port Connection\' callback" );
}


void Jack::registerCallbackGraphOrder( int (*cb)(void *arg) )
{
    if (0 != jack_set_graph_order_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set \'Graph Order\' callback" );
}


void Jack::registerCallbackXRun( int (*cb)(void *arg) )
{
    if (0 != jack_set_xrun_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set \'Xrun\' callback" );
}


void Jack::registerCallbackLatency( void (*cb)(jack_latency_callback_mode_t mode, void *arg) )
{
    if (0 != jack_set_latency_callback( Client, cb, 0 ))
        ERROR2( "JACK", "Unable to set \'Latency\' callback" );
}


void Jack::registerCallbackThreadInit( void (*cb)(void *arg) )
{
    if (0 != jack_set_thread_init_callback( Client, cb, 0 ))
        ERROR2( "JACK:", "Unable to set \'Thread Init\' callback" );
}


// JACK handling
void Jack::createAudioInPort( std::string ID )
{
    jack_port_t * port = jack_port_register( Client, ID.c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0 );
    if (!port)
        ERROR2( "JACK:", "Audio port creation error." );

    Ports.push_back( JackData( ID, port, JACK_AUDIO ) );
}


void Jack::createAudioOutPort( std::string ID )
{
    jack_port_t * port = jack_port_register( Client, ID.c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );
    if (!port)
        ERROR2( "JACK:", "Audio port creation error." );

    Ports.push_back( JackData( ID, port, JACK_AUDIO ) );
}


void Jack::createMidiInPort( std::string ID )
{
    jack_port_t * port = jack_port_register( Client, ID.c_str(), JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0 );
    if (!port)
        ERROR2( "JACK:", "Audio port creation error." );

    Ports.push_back( JackData( ID, port, JACK_MIDI ) );
}


void Jack::createMidiOutPort( std::string ID )
{
    jack_port_t * port = jack_port_register( Client, ID.c_str(), JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0 );
    if (!port)
        ERROR2( "JACK:", "Audio port creation error." );

    Ports.push_back( JackData( ID, port, JACK_MIDI ) );
}


void Jack::deletePort( std::string ID )
{
    std::vector<JackData>::iterator it = Ports.begin();
    while (Ports.end() != it)
    {
        if (ID == it->ID)
        {
            jack_port_unregister( Client, it->Port );
            Ports.erase( it );

            break;
        }
    }
}


void Jack::jackActivate()
{
    jack_activate( Client );
}



void Jack::getBuffers()
{
}


void Jack::connectPorts( std::string, std::string )
{
}

