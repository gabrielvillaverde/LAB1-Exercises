/*
 * validations.h
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int isValidCompoundName(char* string, int len);
int isValidLetters(char* string, int len);
int isValidNumber(char* num, int len);
int isValidNumberFloat(char* num,int len);
int isValidAlphaNumeric(char* string, int len);
int isValidDocumentNumber(char* string, int len);
int isValidMail(char* string, int len);

#endif /* VALIDATIONS_H_ */
