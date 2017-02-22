#include "mystring.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Mystring::Mystring() : m_pStr(m_tablestr)
{
	Assign(NULL);
}

Mystring::Mystring(const char* str) : m_pStr(m_tablestr)
{
	Assign(str);
}


Mystring::~Mystring()
{
	if(m_pStr!=m_tablestr){
		free(m_pStr);
		m_pStr=NULL;
	}
}

Mystring::Mystring(const Mystring& obj) : m_pStr(m_tablestr)
{
	Assign(obj.m_pStr);
}

Mystring& Mystring::operator=(const Mystring& obj)
{
	if(this == &obj){
		return *this;
	}

	Assign(obj.m_pStr);
	return *this;
}

void Mystring::Assign(const char* str)
{
	if(str==NULL){
		m_tablestr[0]='\0';
		return;
	}
	
	int len = strlen(str);
	if(len <= MYLENGTH){
		strncpy(m_tablestr,str,len);
		m_tablestr[len]='\0';
	}
	else{
		if(m_pStr!=m_tablestr){
			m_pStr = static_cast<char*>(realloc(m_pStr,(len+1) * sizeof(char)));
		}
		else{
			m_pStr = static_cast<char*>(malloc((len+1) * sizeof(char)));
		}
		strncpy(m_pStr,str,len);
		m_pStr[len]='\0';
	}
}

char* Mystring::c_str()
{
	return m_pStr;
}

int main()
{
	Mystring str1("123456");
	cout<<str1.c_str()<<endl;

	Mystring str2 = str1;
	Mystring str3(str1);
	cout<<str2.c_str()<<"   "<<str3.c_str()<<endl;
	
	char* str = str2.c_str();	
}
