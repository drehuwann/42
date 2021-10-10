unsigned int pf_length(char * s)
{
  unsigned int out = 0;
  while (*s++)
    out++;
  return out;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)  
{  
  const char *odst = dest;  
  const char *osrc = src;  
  unsigned int n = size;  
  unsigned int dlen;  
     
  /* Find the end of dst and adjust bytes left but don't go past end. */  
  while (n-- != 0 && *dest != '\0')  
    dest++;  
  dlen = dest - odst;  
  n = size - dlen;  
     
  if (n-- == 0)  
    return(dlen + pf_length(src));  
  while (*src != '\0') {  
    if (n != 0) {  
      *dest++ = *src;  
      n--;  
    }  
    src++;  
  }  
  *dest = '\0';  
     
  return(dlen + (src - osrc)); /* count does not include NUL */  
}  
