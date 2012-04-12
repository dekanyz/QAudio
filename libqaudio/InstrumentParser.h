#ifndef __INSTRUMENT_PARSER_H
#define __INSTRUMENT_PARSER_H


#include "XMLParserBase.h"

// TODO: Extend this list with newer tags.
enum TAGS
{
    TAG_QAUDIO,
    TAG_PRE,
    TAG_INSTRUMENT,
    TAG_POST,
    TAG_DSP,
    TAG_PORT,
    TAG_BUFFER,
    TAG_SWITCH,
    TAG_WIRE,
    TAG_VCO,
    TAG_LFO,
    TAG_VCA,
    TAG_VCF,
    TAG_ADSR,
    TAG_ENVELOPE,
    TAG_POINT,
    TAG_SH,
    TAG_MODIFIER,   // TODO: Isn't it better to have a separate adder and multiplier?
    TAG_IMPORT,
    TAG_DELAY,
    TAG_CHORUS,
    TAG_CROSSOVER,
    TAG_FLANGER,
    TAG_COMPRESSOR,
    TAG_MIX,        // TODO: Is this really needed? Maybe the output could be automatically mixed to the given buffer! ;)
    TAG_WAV,

    TAG_INVALID = -1
};

class InstrumentParser : public XMLParserBase
{
    public:

        /* Callback for the opening tag. */
        void XMLCALL handleTagOpen(  );

        /* Callback for the closing tag. */
        void XMLCALL handleTagClose( void *data, const char *el );

    private:

        int parseTag( char * str );

        EffectBase * createObject( int tag );

        // Private variables
        EffectBase     *Effect;
        BufferPool      BufferPoolInst;
}

#endif
