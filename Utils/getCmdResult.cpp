#include "getCmdResult.h"
 
string getCmdResult(const string &strCmd)
{
	char buf[10240] = {0};
	FILE *pf = NULL;
	
	if( (pf = popen(strCmd.c_str(), "r")) == NULL )
	{
		return "";
	}
 
	string strResult;
	while(fgets(buf, sizeof buf, pf))
	{
		strResult += buf;
	}
	
	pclose(pf);
 
	unsigned int iSize =  strResult.size();
	if(iSize > 0 && strResult[iSize - 1] == '\n')  // linux
	{
		strResult = strResult.substr(0, iSize - 1);
	}
 
	return strResult;
}