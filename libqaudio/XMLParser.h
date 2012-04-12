#ifndef __XML_PARSER_BASE_H
#define __XML_PARSER_BASE_H

#include <string>
#include <expat.h>

enum Mode
{
    READ_ONCE,
    POLLING
};


class XmlParserBase
{

    public:

        XmlParserBase( std::string file, enum Mode mode = READ_ONCE );

        /* Setting the *.xml file to precess
         * file - The name with path to open
         * returns true on successful opening */
        void setXmlFilename( std::string file );

        /* Setting the mode of file handling:
         * mode - READ_ONCE: It loads the *.xml file to the memory,
         *                   parses it and exits.
         *        POLLING:   Starts a polling thread to continuously
         *                   check the file change. It also parses 
         *                   the *.xml file. 
         * interval - Sets the polling interval.*/
        void setMode( enum Mode newMode, int newInterval = 0 );

        /* Start parsing */
        void parseFile();


        // Virtual functons

        /* Reimplement this function to handle the opening tags.
         * This will call th:e Constructor of an effect base*/
        virtual void XMLCALL handleTagOpen(  ) = 0;

        /* Reimplement this function to handle the closing tags.
         * This will call the effects setAttribute() function to the
         * given object. */
        virtual void XMLCALL handleTagClose( void *data, const char *el ) = 0;


    private:

        std::string     fileName;
        XML_Parser      parser;
        int             interval;
        enum Mode       mode;

};

#endif
