
    parser = 0;
    fileName = "";
    interval = 0;
    mode = READ_ONCE;

    setXmlFilename( file );
    setMode( mode );
}
void XmlParserBase::setXmlFilename( std::string file )
{
    fileName = file;
}


void XmlParserBase::setMode( enum Mode newMode, int newInterval = 0 )
{
    mode = newMode;
    interval = newInterval;
}


void XmlParserBase::parseFile()
{
    if (parser)
    {
        XMLarserFree( *parser );
        delete parser;
    }

    // TODO: Kill the file changing checker thread

    parser = XML_ParserCreate( NULL );
    XML_SetElementHandler( parser, handleTagOpen, handleTagClose );

    FILE * file = fopen( fileName.c_str(), "r" );
    if (!file)
    {
        // TODO: Call the error handler function
        printf( "File opening error...\n" );
        return 1;
    }

    // Parser cycle
    for (;;) {
        int done;
        int len;

        len = ( int )fread( Buff, 1, BUFFSIZE, file );
        if (ferror( file )) {
            // TODO: Call the error handler function
            fprintf( stderr, "Read error\n" );
            exit( -1 );
        }         
        done = feof( file );

        if (XML_Parse( p, Buff, len, done ) == XML_STATUS_ERROR) {
            // TODO: Call the error handler function
            fprintf( stderr, "Parse error at line %" XML_FMT_INT_MOD "u:\n%s\n",
                    XML_GetCurrentLineNumber( p ),
                    XML_ErrorString( XML_GetErrorCode( p ) ));
            exit( -1 );
        }

        if (done)
            break;
    }
  
   fclose( file );
   XML_ParserFree( p );

   // TODO: Start the file changing checker thread
}

