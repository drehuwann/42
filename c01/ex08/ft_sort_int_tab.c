void pf_fusion(int *tab, int *triagedTab, int indexBegin, int indexMid, \
	       int indexEnd)
{
  int indexTabA = indexBegin;
  int indexTabB = indexMid + 1;
  int indexTriagedTab = indexBegin;
  for (indexTriagedTab = indexBegin; indexTriagedTab <= indexEnd; \
       indexTriagedTab ++)
    {
      if ( indexTabA == indexMid + 1 )
	{
	  triagedTab[indexTriagedTab] = tab[indexTabB];
	  indexTabB ++;
	}
      else if ( indexTabB == indexEnd + 1 )
	{
	  triagedTab[indexTriagedTab] = tab[indexTabA];
	  indexTabA ++;
	}
      else if ( tab[indexTabA] < tab[indexTabB] )
	{
	  triagedTab[indexTriagedTab] = tab[indexTabA];
	  indexTabA ++;
	}
      else
	{
	  triagedTab[indexTriagedTab] = tab[indexTabB];
	  indexTabB ++;
	}
    }
}

void pf_triFusion(int *tab, int *triagedTab, int indexBegin, int indexEnd)
{
  if (indexBegin < indexEnd)
    {
      int indexMid = (indexBegin + indexEnd) / 2;
      pf_triFusion(tab, triagedTab, indexBegin, indexMid);
      pf_triFusion(tab, triagedTab, indexMid + 1, indexEnd);
      pf_fusion(tab, triagedTab, indexBegin, indexMid, indexEnd);
      for (int i = indexBegin; i <= indexEnd; i++)
	tab[i] = triagedTab[i];
    }
}

void ft_sort_int_tab(int *tab, int size)
{
  int triagedTab[size];
  pf_triFusion(tab, triagedTab, 0, size -1);
}
