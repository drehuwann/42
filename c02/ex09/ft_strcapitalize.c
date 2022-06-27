static int pf_isUpcase(char c)
{
  return ( (c >= 'A') && (c <='Z') );
}

static int pf_isLowcase(char c)
{
  return ( (c >= 'a') && (c <= 'z') );
}

static int pf_isSep(char c)
{
  return ( ( c == 0  ) || (c == 0x20) || ( c == '-') || ( c == '+') );
}

static int pf_isAlpha(char c)
{
  return ( pf_isLowcase(c) || pf_isUpcase(c) );
}

char *ft_strcapitalize(char *str)
{
  char *words = str;
  char c = *str;
  char previousChar = 0;
  int inWord = -1;

  while ( c != 0 )
    {
      while ( pf_isSep(c) ) // skip leading separators
	{
	  previousChar = c;
	  c = *(++str);
	} 
      while ( ! pf_isSep(c) )
	{
	  inWord ++;

	  if ( pf_isAlpha(c) )
	    {
	      if ( pf_isSep(previousChar) )
		{
		  if ( (inWord == 0) && pf_isLowcase(c) )
		    *str -= 0x20;
		  else *str += 0x20;
		}
	    }
	  str ++;
	  previousChar = c;
	  c = *str;
	}
      inWord = -1;
    }
  return words;
}
