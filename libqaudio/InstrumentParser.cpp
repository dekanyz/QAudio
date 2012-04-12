#include "InstrumentParser.h"

void XMLCALL InstrumentParser::handleTagOpen( void *data, const char *el, const char **attr )
{
    int tag = parseTag( el );

    switch (tag) {
        case TAG_INVALID:   
            WARNING2( "INSTRUMENT PARSER:", "Invalid tag received." );
            return;
        case TAG_QAUDIO:
        case TAG_PRE:
        case TAG_INSTRUMENT:
        case TAG_POST:
        case TAG_DSP:
            break; // There is nothing to do here for these
        case TAG_BUFFER: 
            if (attr[2])
                WARNING2( "INSTRUMENT PARSER:", "Too many parameters" );
            if ("name" == attr[0])
                BufferPoolInst.createBuffer( attr[1] );
            break;
        default:
            createObject( tag );
    }
}


void XMLCALL InstrumentParser::handleTagClose( void *data, const char *el )
{
}


int InstrumentParser::parseTag( char * str )
{
    if ("QAUDIO" == *str)
        return TAG_QAUDIO;

    if ("PRE" == *str)
        return TAG_PRE;

    if ("POST" == *str)
        return TAG_POST;

    if ("INSTRUMENT" == *str)
        return TAG_INSTRUMENT;

    if ("DSP" == *str)
        return TAG_DSP;

    if ("PORT" == *str)
        return TAG_PORT;

    if ("BUFFER" == *str)
        return TAG_BUFFER;

    if ("SWITCH" == *str)
        return TAG_SWITCH;

    if ("WIRE" == *str)
        return TAG_WIRE;

    if ("VCO" == *str)
        return TAG_VCO;

    if ("LFO" == *str)
        return TAG_LFO;

    if ("VCA" == *str)
        return TAG_VCA;

    if ("VCF" == *str)
        return TAG_VCF;

    if ("ADSR" == *str)
        return TAG_ADSR;

    if ("ENVELOPE" == *str)
        return TAG_ENVELOPE;

    if ("POINT" == *str)
        return TAG_POINT;

    if ("SH" == *str)
        return TAG_SH;

    if ("MODIFIER" == *str)
        return TAG_MODIFIER;

    if ("IMPORT" == *str)
        return TAG_IMPORT;

    if ("DELAY" == *str)
        return TAG_DELAY;

    if ("CHORUS" == *str)
        return TAG_CHORUS;

    if ("CROSSOVER" == *str)
        return TAG_CROSSOVER;

    if ("FLANGER" == *str)
        return TAG_FLANGER;

    if ("COMPRESSOR" == *str)
        return TAG_COMPRESSOR;

    if ("MIX" == *str)
        return TAG_MIX;

    if ("WAV" == *str)
        return TAG_WAV;
    /*
       if ("" == *str)
       return TAG_;
       */

    return TAG_INVALID;
}


EffectBase * InstrumentParser::createObject( int tag )
{
    Effect = 0;

    switch (tag)
    {
        case TAG_PORT:
            break;
        case TAG_SWITCH:
            break;
        case TAG_WIRE:
            break;
        case TAG_VCO:
            break;
        case TAG_LFO:
            break;
        case TAG_VCA:
            break;
        case TAG_VCF:
            break;
        case TAG_ADSR:
            break;
        case TAG_ENVELOPE:
            break;
        case TAG_POINT:                        
            break;
        case TAG_SH:                           
            break;
        case TAG_MODIFIER:
            break;
        case TAG_IMPORT:                       
            break;
        case TAG_DELAY:                        
            break;
        case TAG_CHORUS:                       
            break;
        case TAG_CROSSOVER:                    
            break;
        case TAG_FLANGER:                      
            break;
        case TAG_COMPRESSOR:                   
            break;
        case TAG_MIX:
            break;
        case TAG_WAV:
            break;
        default:    // Error case 
    }
}


