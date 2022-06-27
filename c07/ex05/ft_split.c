#include <stdlib.h>

static int pf_charIsSepa(const char cara, const char *charset)
/// returns int as bool 0=false, 1=true;
{
  char *p_charset = (char*)charset;
  while (*p_charset != 0) {
    if (*p_charset == cara)
      return 1;
    p_charset ++;
  }
  return 0;
}

static unsigned int pf_splitCount(const char *str, const char *charset)
{
  unsigned int result = 0;
  int inWord = 0; /// int as bool 0=false, 1=true
  while (*str) {
    if (pf_charIsSepa(*str, charset) == 1) {  // true
	    inWord = 0;
    } else {
      if (inWord == 0) {
        ++ result;
        inWord = 1;
      }
    }
    ++ str;
  }
  return result;
}

typedef struct {
  char *first;
  char *last;
} borns;

static borns DoFirstSplitAndReturnBorns(const char *strToSplit,
				   const char *charset)
{
  borns result;
  int wordHit = 0; // as bool false = 0; true = 1;
  while (*strToSplit)
    {
      if (pf_charIsSepa(*strToSplit, charset) == 1) {  // true
        if (wordHit == 1) {
          result.last = (char *)strToSplit;
          return result;
        }
        ++ strToSplit;
      } else {
        if (wordHit == 0) {
          result.first = (char *)strToSplit;
          wordHit = 1;
        }
        ++ strToSplit;
      }
    }
  return result;
}

char **ft_split(char *str, char *charset)
{
  const char *p_charset = (const char *)charset;
  const char *p_str = (const char *)str;
  unsigned int arraySize = pf_splitCount((const char*)str, p_charset);
  char **toRet = (char**)malloc((arraySize + 1) * sizeof(toRet));
  for (unsigned int i = 0; i < arraySize; ++i) {
    borns wordBorns = DoFirstSplitAndReturnBorns(p_str, p_charset);
    char *strInArray = (char*)malloc((wordBorns.last - wordBorns.first)
			* sizeof(*strInArray));
    char *p_strInArray = strInArray;
    for (const char *p_c = wordBorns.first; p_c < wordBorns.last; p_c ++) {
      *p_strInArray ++ = *p_c;
    }
    *p_strInArray = 0; //null-terminates
    toRet[i] = strInArray;
    p_str = (const char *)wordBorns.last;
  }
  toRet[arraySize] = 0;
  return toRet;
}
