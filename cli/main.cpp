int main()
{
  /* Check the received CLI commands */

  /* Read application config.
   * This is an xml parser. The main config parameters are received here. */

  /* Start instrument config file checker thread. 
   * This is an XML parser too. The instruments are built here in three steps:
   * 1. Read the instruments and create the needed objects, buffers.
   *    Store the buffer ID for every buffer. The pointers are invalid yet here.
   * 2. Allocate the needed memory for buffers.
   * 3. Receive the pointers of the buffers.
   */

  // Start thread pool's threads

  // Start connection server thread

  // Start GUI
}
