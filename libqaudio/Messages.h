#ifndef __MESSAGES_H
#define __MESSAGES_H


#define DEBUG()         debug( __FILE__, __LINE__, __FUNCTION__, "", "" )
#define DEBUG1(A)        debug( __FILE__, __LINE__, __FUNCTION__, (A), "" )
#define DEBUG2(A,B)     debug( __FILE__, __LINE__, __FUNCTION__, (A), (B) )


#define ERROR()     error( __FILE__, __LINE__, __FUNCTION__, "", "" )
#define ERROR1(A)     error( __FILE__, __LINE__, __FUNCTION__, (A), "" )
#define ERROR2(A,B)     error( __FILE__, __LINE__, __FUNCTION__, (A), (B) )

#define WARNING()   warning( __FILE__, __LINE__, __FUNCTION__, "", "" )
#define WARNING1(A)   warning( __FILE__, __LINE__, __FUNCTION__, (A), "" )
#define WARNING2(A,B)   warning( __FILE__, __LINE__, __FUNCTION__, (A), (B) )

void debug( char *, int , const char *, char *, char * );
void warning( char *, int , const char *, char *, char * );
void error( char *, int , const char *, const char *, const char * );


#endif
