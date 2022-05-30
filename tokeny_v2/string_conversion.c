#include "string_conversion.h"

#define NULL '\0'
#define MAX_LENGTH 254

void CopyString(char pcSource[], char pcDestination[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcSource[cCharCounter] != NULL; cCharCounter++){
		pcDestination[cCharCounter] = pcSource[cCharCounter];
	}
	
	pcDestination[cCharCounter] = NULL;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcStr1[cCharCounter] != NULL; cCharCounter++){
		if (pcStr1[cCharCounter] != pcStr2[cCharCounter]){
			return DIFFRENT;
		}
	}
	if (pcStr2[cCharCounter] != NULL){
		return DIFFRENT;
	}
	return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcDestinationStr[cCharCounter] != NULL; cCharCounter++){}
		
	CopyString(pcSourceStr, (pcDestinationStr + cCharCounter));
}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	char cCharCounter;
	
	for (cCharCounter = 0; pcString[cCharCounter] != NULL; cCharCounter++){
		if (pcString[cCharCounter] == cOldChar){
			pcString[cCharCounter] = cNewChar;
		}
	}
}

void UIntToHexStr(unsigned int uiValue, char pcString[]){
	
	char cNybbleCounter;
	char cNybble;
	
	pcString[0] = '0';
	pcString[1] = 'x';
	
	for (cNybbleCounter = 0; cNybbleCounter < 4; cNybbleCounter++){
		
		cNybble = (uiValue >> (cNybbleCounter * 4)) & 0xf;
		
		if (cNybble > 9){
			pcString[5 - cNybbleCounter] = cNybble + ('A' - 10);
		}
		else{
			pcString[5 - cNybbleCounter] = cNybble + '0';
		}
	}
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	char cCharCounter;
	char cNybble;
	
	if (pcStr[0] != '0') { return ERROR; }
	if (pcStr[1] != 'x') { return ERROR; }
	if (pcStr[2] == NULL) { return ERROR; }

	*puiValue = 0x00;

	for (cCharCounter = 2; pcStr[cCharCounter] != NULL; cCharCounter++){
		cNybble = pcStr[cCharCounter];
		
		if (cCharCounter > 5){
			return ERROR;
		}
		
		*puiValue = *puiValue << 4;
		
		if (cNybble >= 'A'){
			*puiValue = *puiValue | (cNybble - ('A' - 10));
		}
		else{
			*puiValue = *puiValue | (cNybble - '0');
		}
	}
	return OK;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	char cStringLength;
	
	for (cStringLength = 0; pcDestinationStr[cStringLength] != NULL; cStringLength++){}
		
	UIntToHexStr(uiValue, &pcDestinationStr[cStringLength]);
}


