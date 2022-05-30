#include "string_conversion.h"

#define NULL '\0'
#define DELIMITER_CHAR ' '
#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3
#define DELIMITER_CHAR ' '

enum KeywordCode {LD, ST, RST};

struct Keyword {
    enum KeywordCode eCode;
    char cString[MAX_KEYWORD_STRING_LTH + 1];
};

struct Keyword asKeywordList[MAX_KEYWORD_NR]=
{
    {RST, "reset"},
    {LD, "load"},
    {ST, "store"}
};

union TokenValue {
    enum KeywordCode eKeyword;
    unsigned int uiNumber;
    char *pcString;
};

enum TokenType {KEYWORD, NUMBER, STRING};

struct Token {
    enum TokenType eType;
    union TokenValue uValue;
};

struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;


unsigned char ucFindTokensInString(char *pcString){
	enum FinderState {TOKEN, DELIMITER};
	enum FinderState eFinderState = DELIMITER;
	unsigned char ucCharCounter;
	char cCurrentChar;
	unsigned char ucCurrentToken = 0;

	for (ucCharCounter = 0; ; ucCharCounter++){
		cCurrentChar = pcString[ucCharCounter];
		
		switch (eFinderState) {

			case TOKEN:
				if (cCurrentChar == NULL || ucCurrentToken == MAX_TOKEN_NR){
					return ucCurrentToken;
				}
				else if (cCurrentChar == DELIMITER_CHAR){
					eFinderState = DELIMITER;
				}
				else{
					eFinderState = TOKEN;
				}
				break;
			
			case DELIMITER:
				if (cCurrentChar == NULL){
					return ucCurrentToken;
				}
				else if (cCurrentChar == DELIMITER_CHAR){
					eFinderState = DELIMITER;
				}
				else {
					asToken[ucCurrentToken].uValue.pcString = (pcString + ucCharCounter);
					ucCurrentToken++;
					eFinderState = TOKEN;
				}
				
				break;
		}
	}
}

enum Result eSringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode){
	
}


int main(){
	
	ucTokenNr = ucFindTokensInString("load 0x1234 Aakasz");
	
	
	return 0;
}

