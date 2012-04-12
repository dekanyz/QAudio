#ifndef __EFFECT_BASE_H
#define __EFFECT_BASE_H

#include <string>


class EffectBase
{
  public:

    /* Reimplement this function to call the effect's main executor function. */
    virtual void exec();

    /* Reimplement this function to process the received attributes. */
    virtual bool setAttribute( char * tag, char * value );

    /* Reimplement this function to be sure, that all mandatory attributes
     * were set. */
    virtual bool attributeSettingFinished();

  private:

    /* Here comes the decleration of the private stuff.
     * There should be some bool variables to be sure,
     * that all mandatory attributes were set. */
}

#endif
