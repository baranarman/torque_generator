/** @file
 *  @brief Header file for error handler 
 */

#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_

/** @brief when there is an error in the system, not only led but also log of this error shall be created,
 *  @param[in] error_text is to set the diagnostic text, to detect the location of the error! 
 */
void error(char* error_text);

#endif
