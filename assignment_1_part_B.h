/**
 * Assignment 1 part B header file
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma once

/**
* This function is responsible for computing
* the checksum of a string of ’0’ and ’1’ given a key string of ’0’ and ’1’.
* The checksum is returned as a string of ’0’ and ’1’.
*
* @param char* data_string - The null terminated data string of ’0’ and ’1’
*
* @param char* key_string  - The null terminated key string of ’0’ and ’1’
* @param char** checksum_string - The new null terminated checksum string 
*                                 of ’0’ and ’1’ computed by this function
* @return A negative number if an error occurs (failed malloc for example)
* otherwise return 0
*/
int checksum(char* data_string, char* key_string, char** checksum_string);


/**
* This function is responsible for computing the checksum
* of all bits 1 to 7 of an image, and embedding the
* checksum as a null terminated string of ’0’ and ’1’
* in the image file.
*
* @param char* file_name - The name of the image file to be processed
* @return int - the numeric value 0 on success,
*             -1 if an error occurs (file does not exists for example)
*/
int embed_checksum(char* file_name);


/**
* This function is responsible for verifying whether
* the message string embedded in
* the image matches the checksum of all bits 1 to 7
* of this image
*
* @param char* file_name
- The name of the image file to be verified
*
* @return int - the numeric value 0 on success,
*             -1 if an error occurs
*                (check fails, or file does not exists for example)
*/
int verify_checksum(char* file_name);


