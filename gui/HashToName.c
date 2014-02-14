#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>

#include "HashToName.h"

static char decryptLastCharTable[0x80] = 
{0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x4b, 0x00, 0x16, 0x1c, 0x49, 0x01, 0x1d, 0x2a, 0x42, 0x00, 0x11, 0x12, 0x27, 0x00, 0x00,
 0x20, 0x4d, 0x33, 0x4f, 0x43, 0x0a, 0x44, 0x39, 0x1b, 0x4a, 0x00, 0x3e, 0x00, 0x3b, 0x00, 0x00,
 0x46, 0x28, 0x25, 0x18, 0x31, 0x48, 0x23, 0x38, 0x2d, 0x14, 0x19, 0x3a, 0x1f, 0x52, 0x04, 0x0e,
 0x21, 0x3d, 0x40, 0x3f, 0x02, 0x15, 0x10, 0x37, 0x2c, 0x0f, 0x2e, 0x4e, 0x00, 0x22, 0x00, 0x03,
 0x0c, 0x35, 0x3c, 0x4c, 0x06, 0x24, 0x50, 0x36, 0x2f, 0x13, 0x47, 0x17, 0x45, 0x51, 0x26, 0x09,
 0x2b, 0x1a, 0x0d, 0x05, 0x41, 0x29, 0x0b, 0x30, 0x08, 0x32, 0x53, 0x07, 0x00, 0x34, 0x1e, 0x00};

static char decryptTablePhase2[0x80] =
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x21, 0x64, 0x00, 0x33, 0x37, 0x2d, 0x23, 0x62, 0x5a, 0x47, 0x00, 0x5f, 0x25, 0x36, 0x2c, 0x00,
 0x43, 0x35, 0x57, 0x70, 0x58, 0x7e, 0x4b, 0x2b, 0x30, 0x4c, 0x00, 0x79, 0x00, 0x52, 0x00, 0x00,
 0x44, 0x48, 0x68, 0x63, 0x61, 0x4d, 0x4e, 0x45, 0x6e, 0x66, 0x65, 0x40, 0x71, 0x59, 0x27, 0x29,
 0x34, 0x6f, 0x53, 0x46, 0x7d, 0x69, 0x38, 0x50, 0x28, 0x3b, 0x74, 0x39, 0x00, 0x32, 0x3d, 0x31,
 0x6a, 0x5e, 0x51, 0x7b, 0x67, 0x2e, 0x6c, 0x20, 0x56, 0x75, 0x42, 0x5b, 0x26, 0x5d, 0x72, 0x73,
 0x6d, 0x6b, 0x76, 0x77, 0x55, 0x78, 0x54, 0x24, 0x49, 0x4a, 0x7a, 0x4f, 0x00, 0x41, 0x60, 0x00};

void decryptPhase1(char *hash, int size) {
	char val1, val2;
	int medianPt13 = (int)floor(0.33*size);
	int medianPt23 = (int)floor(0.66*size);

	val1 = hash[medianPt23];
	val2 = hash[medianPt13];

	hash[medianPt23] = hash[0];
	hash[medianPt13] = hash[1];

	hash[0] = val1;
	hash[1] = val2;
}

int decryptLastChar(char c) {
	return decryptLastCharTable[(unsigned char)c];
}

void decryptPhase2(char *hash, int size, int decodeSeed) {
	int i, j;
	char computeVar;
	int computeLoop = decodeSeed;
	int hashSize = size;

	for(i=0; i < hashSize; i++) {
		//d�codage du caractere
		computeVar = hash[i];
		for(j=0; j < computeLoop; j++) {
			computeVar = decryptTablePhase2[(unsigned char)computeVar];
			if(!computeVar) computeVar = 0xFF;
		}
		hash[i] = computeVar;
		computeLoop = (1+computeLoop + 17*computeVar)&0x1F;
		if(!computeLoop) computeLoop = 0x20;
	}
}

/**
 * Converti un hash en son nom compr�hensible par l'�tre humain.
 * \param hash Le hash a convertir
 * \param name buffer qui contiendra le nom associ� au hash apr�s la convertion (hash et name peuvent pointer vers le m�me espace m�moire)
 * \return Code de l'erreur:
 * \li \c 0 Pas d'erreur.
 * \li \c EINVAL hash ou name est NULL.
 * \sa convertNameToHash
 */
int convertHashToName(const char *hash, char *name) {
	int hashSize;

	if(!hash || !name) return EINVAL;

	hashSize = strlen(hash);
	if(hashSize > 2) {
		int reducedHashSize = hashSize - 2;
		char *reducedHash = (char*) alloca(reducedHashSize);  //no null terminator inside


		memcpy(reducedHash, hash+1, reducedHashSize); //copie de 1 � n-1  (ie: 2 char en moins du hash)

		decryptPhase1(reducedHash, reducedHashSize);
		decryptPhase2(reducedHash, reducedHashSize, decryptLastChar(hash[hashSize-1]));
		memcpy(name, reducedHash, reducedHashSize);
		name[reducedHashSize] = 0;

		return 0;
	} else {
		return EINVAL;
	}
}

/**
 * R�cup�re le num�ro du data.00x ou sont les donn�es du fichier associ� au hash.
 * \param hash Le hash du fichier
 * \return Le num�ro du fichier de donn�e (1 pour data.001, 2 pour data.002 etc ...).
 */
int getAssociatedDataFileNumber(const char *hash) {
	int checksum=0;
	
	if(!hash) return 1;

	while(*hash) {
		checksum = checksum*31 + tolower(*hash);
		hash++;
	}

	if(checksum < 0) checksum = -checksum;
	return (checksum & 0x07)+1;
}

