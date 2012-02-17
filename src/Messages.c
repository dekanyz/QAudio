#include <iostream>
#include <string>

#include "Configure.h"

void debug( char * file, int line, const char *function, char *message1, char *message2 )
{
#ifdef SHOW_DEBUG_MESSAGES
    bool doPrint( false );


#ifdef DEBUG_XML_PARSER_CALLBACKS
    if ( "xml_parser_callbacks.c" == file )
    {
        doPrint = true;
    }
#endif

/* #ifdef DBG_ */
/*   if (strcmp( "", file ) == 0) */
/*     { */
/*       doPrint = 1; */
/*     } */
/* #endif */


    if (doPrint)
    {
        std::cout << "DEBUG:   " 
            << file << ": "
            << line << ": "
            << function << ":" << std::endl << "         "
            << message1 << " "
            << message2 << std::endl;
    }

#endif

    return;
}

void warning( char * file, int line, const char *function, char *message1, char *message2 )
{
#ifdef SHOW_WARNING_MESSAGES
    std::cout << "WARNING:  "
#ifdef SHOW_DEBUG_MESSAGES
        << file << ": "
        << line << ": "
        << function << ":" << std::endl << "          "
#endif
        << message1 << " "
        << message2 << std::endl;

    return;
#endif
}

void error( char * file, int line, const char *function, const char *message1, const char *message2 )
{
    std::cout << "ERROR:    "
#ifdef SHOW_DEBUG_MESSAGES
        << file << ": "
        << line << ": "
        << function << ":" << std::endl << "          "
#endif
        << message1 << " "
        << message2 << std::endl;
    //  exit (EXIT_FAILURE);
}
