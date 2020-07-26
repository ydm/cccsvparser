#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CsvRow {
    char **fields_;
    int numOfFields_;
    int: 32;                    // padding
} CsvRow;

typedef struct CsvParser {
    char *filePath_;
    char *errMsg_;
    CsvRow *header_;
    FILE *fileHandler_;
    char *csvString_;
    int firstLineIsHeader_;
	int fromString_;
	int csvStringIter_;
    char delimiter_;
    int: 24;                    // 3 bytes padding
} CsvParser;


// Public
CsvParser *CsvParser_new(const char *filePath, const char *delimiter, int firstLineIsHeader);
CsvParser *CsvParser_new_from_string(const char *csvString, const char *delimiter, int firstLineIsHeader);
void CsvParser_destroy(CsvParser *csvParser);
void CsvParser_destroy_row(CsvRow *csvRow);
const CsvRow *CsvParser_getHeader(CsvParser *csvParser);
CsvRow *CsvParser_getRow(CsvParser *csvParser);
int CsvParser_getNumFields(const CsvRow *csvRow);
const char *const *CsvParser_getFields(const CsvRow *csvRow);
const char* CsvParser_getErrorMessage(CsvParser *csvParser);

// Private
CsvRow *_CsvParser_getRow(CsvParser *csvParser);    
int _CsvParser_delimiterIsAccepted(const char *delimiter);
void _CsvParser_setErrorMessage(CsvParser *csvParser, const char *errorMessage);

#ifdef __cplusplus
}
#endif

#endif
