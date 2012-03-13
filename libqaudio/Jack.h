/*****************************************************************************************************************
 * Copyright (C) 2011 Zoltán Dékány (dekaaa71@gmail.com)
 *
 * QAudio - Jack.h
 * -------------------------
 *
 * This is the Jack handling class:
 * - Creating Jack ports
 * - Connecting to other ports (are you sure???)
 * - Registring callbacks
 ****************************************************************************************************************/

#ifndef __JACK_BASE_H
#define __JACK_BASE_H


#include <jack/jack.h>
#include <jack/midiport.h>

#include <string>
#include <vector>


namespace jack 
{


enum PortTypes
{
    JACK_AUDIO,
    JACK_MIDI
};


union BufferType
{
    jack_default_audio_sample_t * AudioPtr;
    jack_midi_data_t            * MidiPtr;
};


class JackData
{
    public:

        JackData( std::string id, jack_port_t * port, PortTypes pt ) 
        {
            ID          = id;
            Port        = port;
            PortType    = pt;
            Buffer      = 0;
        }

        std::string    ID;
        jack_port_t  * Port;
        BufferType   * Buffer;
        PortTypes      PortType;
};


class Jack  // TODO: Make this class Singleton
{
    public:

        Jack( std::string name );
        Jack();

        /* You can register your callback functions here */
        void registerCallbackProcess            ( int  (*cb)(jack_nframes_t nframes, void *arg) );
        void registerCallbackSampleRateChange   ( int  (*cb)(jack_nframes_t nframes, void *arg) );
        void registerCallbackBufferSizeChanged  ( int  (*cb)(jack_nframes_t nframes, void *arg) );
        void registerCallbackShutdown           ( void (*cb)(void *arg) );
        void registerCallbackError              ( void (*cb)(const char *) );

        void registerCallbackFreewhel           ( void (*cb)(int starting, void *arg) );
        void registerCallbackClientRegistration ( void (*cb)(const char* name, int register, void *arg) );
        void registerCallbackPortRegistration   ( void (*cb)(jack_port_id_t port, int register, void *arg) );
        void registerCallbackPortConnection     ( void (*cb)(jack_port_id_t a, jack_port_id_t b, int connect, void* arg) );
        void registerCallbackGraphOrder         ( int  (*cb)(void *arg) );
        void registerCallbackXRun               ( int  (*cb)(void *arg) );
        void registerCallbackLatency            ( void (*cb)(jack_latency_callback_mode_t mode, void *arg) );
        void registerCallbackThreadInit         ( void (*cb)(void *arg) );
        

        /* Jack port creation functions.
         * It receives an ID string for a port.
         * The created port will be registered to JackData structure. */
        // TODO: Do I need to delete the ports on shutdown?
        void createAudioInPort ( std::string ID );
        void createAudioOutPort( std::string ID );
        void createMidiInPort  ( std::string ID );
        void createMidiOutPort ( std::string ID );
    
        /* Jack activation */
        void jackActivate();

        /* Get Jack buffers
         * This will get the pointers to the Jack buffers.
         * The received pointers will be stored in JackBuffers structure. */
        void getBuffers();

        /* Connect Jack ports */
        void connectPorts( std::string, std::string );

        /* Unregister a port */
        void deletePort( std::string );


    private:

        std::vector<JackData>   Ports;
        jack_client_t *         Client;

}; // End of Jack class


}; // End of jack namespace


#endif
