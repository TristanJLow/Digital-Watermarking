#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "assignment_1.h"

int main(int argc, char *argv[]) {
	//char *file_name = "test.pgm";
	//char *image_buffer, *encoded;
	//int data_length, width, height;
	//data_length = read_image(file_name, &image_buffer, &width, &height);

	//int k = 46;
	//char* message = "The vicious wolf scares the scary urchin";
	//int count = rot_k(message, k);
	//printf("The number of changed characters is: %d\n", count);
	
	char *encoded = "Omdnovi Gjr";
	char *known_word = "Tristan";
	char *message;
	int k;
	
	k = crack(encoded, known_word, &message);
	
	printf("It took %d rotations to find the %c\n", k, *known_word);

	
}//end main

//int read_image(char* file_name, char** image_data, int* width, int* height) { 
//	
//	int p_type, maximum, data_length;
//	int increment = 0;
//	char data[] = {};
//	char get;
//	
//	FILE* filePointer = fopen(file_name, "rb");
//	
//	if (filePointer != NULL) {
//		fscanf(filePointer, "P%d %d %d %d\n", &p_type, width, height, &maximum);
//		
//		//printf("the type %d\n", p_type);
//		//printf("the width %d\n", *width);
//		//printf("the height %d\n", *height);
//		//printf("the maximum %d\n", maximum);
//		
//		while (!feof(filePointer)) {
//			get = fgetc(filePointer);
//			data[increment] = get;
//			increment = increment + 1;
//		}//end while
//		
//		*image_data = data;
//		
//		data_length = sizeof(data);
//		
//		//printf("data length %d", data_length);
//		
//		return data_length;
//	}//end if
//	
//	return -1;
//	}//end read_image

int rot_k(char* message, int k) {
	
	int count = 0; 
	
	int msg_len = strlen(message);
	int index = 0;
	char byte = 0;
	int temp_byte = 0;
	
												//printf("The message length is: %d\n", msg_len);
	
	while(k > 26) {
		k = k - 26;
	}//end while
			
	while(k == 26) {
		return 0;
	}//end while
	
	while(k % 26 == 0) {
		return 0;
	}//end while
	
	for(index = 0; index < msg_len; index = index + 1) {
		byte = message[index];
												//printf("Original character in byte [%c], [%d]\n", byte, byte);
		
		if (byte >= 97 && byte <= 122 ) {
			temp_byte = byte;
			temp_byte = temp_byte + k;
			while (temp_byte > 122) {
				temp_byte = temp_byte - 26;
			}//end while
			while (temp_byte < 97) {
				temp_byte = 123 - (97 - temp_byte);
			}//end while
			byte = temp_byte;
			count = count + 1;
		}// end if
		
		if (byte >= 65 && byte <= 90 ) {
				temp_byte = byte;
				temp_byte = temp_byte + k;
				while (temp_byte > 90) {
					temp_byte = temp_byte - 26;
				}//end while
				while (temp_byte < 65) {
					temp_byte = 91 - (65 - temp_byte);
				}//end while
				byte = temp_byte;
				count = count + 1;
		}// end if
					
												//printf("New character in byte [%c], [%d]\n", byte, byte);
												message[index] = byte;
	}//end for
	
	return count;
}//end rot_k

int crack(const char* encoded, char* known_word, char** message) {
	int k = 0;
	int index = 0;
	int temp_index = 0;
	int word_index = 0;
	int msg_len = strlen(encoded);
	int word_len = strlen(known_word);
	char byte = 0;
	//byte = malloc(sizeof(char) * msg_len);
	int temp_byte = 0;
	
	//char new_message[msg_len];
	
												//printf("The encoded length is: %d\n", msg_len);
												//printf("The word length is: %d\n", word_len);
	
	for(k = 0; k < 26; k = k +1) {
		for(index = 0; index < msg_len; index = index + 1) {
				byte = encoded[index];
												//printf("Original character in byte [%c], [%d]\n", byte, byte);
				
				if (byte >= 97 && byte <= 122 ) {
					temp_byte = byte;
					temp_byte = temp_byte + k;
					while (temp_byte > 122) {
						temp_byte = temp_byte - 26;
					}//end while
					
					while (temp_byte < 97) {
						temp_byte = 123 - (97 - temp_byte);
					}//end while
					
					byte = temp_byte;
				}// end if
							
				if (byte >= 65 && byte <= 90 ) {
						temp_byte = byte;
						temp_byte = temp_byte + k;
						
						while (temp_byte > 90) {
							temp_byte = temp_byte - 26;
						}//end while
						
						while (temp_byte < 65) {
							temp_byte = 91 - (65 - temp_byte);
						}//end while
						
						byte = temp_byte;
				}// end if
							
												//printf("New character in byte [%c], [%d]\n", byte, byte);
				message[index] = byte;

		}//end for
		
												//printf("The current rotation is: [%d]\n", k);
	
	for(temp_index = 0; temp_index < msg_len; temp_index = temp_index + 1) {
		byte = message[temp_index];
		
		if (message[temp_index] == known_word[word_index]) {
			word_index = word_index + 1;
		}//end if
		
		else {
			word_index = 0;
		}//end else
		
		if (word_index == word_len) {
			return k;
		}//end if
	}//end for
	}//end for
	
	return -1;
}//end crack