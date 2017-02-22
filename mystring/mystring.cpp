#include "mystring.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Mystring::Mystring() : m_pStr(m_szBuffer)
{
	m_szBuffer[0] = '\0';
}


Mystring::Mystring(const char* pStr,int nLen) : m_pStr(m_szBuffer)
{
	if(pStr == NULL) 
		m_szBuffer[0] = '\0';
	
	Assign(pStr,nLen);
}



Mystring::Mystring(const Mystring& src) : m_pStr(m_szBuffer)
{
	m_szBuffer[0] = '\0';
	Assign(src.m_pStr);
}

const Mystring& Mystring::operator=(const Mystring& src)
{
	if(this == &src)return *this;
	Assign(src.m_pStr);
	return *this;
}

Mystring::~Mystring()
{
	Myfree();
}

void Mystring::Assign(const char* pStr,int cchMax)
{
	if(pStr == NULL)return;

	cchMax = cchMax < 0 ? strlen(pStr) : cchMax;

	if(cchMax > MAX_LOCAL_STRING){
		if(m_pStr != m_szBuffer){
			m_pStr = static_cast<char*>(realloc(m_pStr, (cchMax + 1) * sizeof(char)) );
		}
		else{
			m_pStr = static_cast<char*>(malloc( (cchMax + 1) * sizeof(char) ));
		}
		
		strncpy(m_pStr,pStr,cchMax);
		m_pStr[cchMax] = '\0';
	}
	else{
		if(m_pStr != m_szBuffer){
			free(m_pStr);
			m_pStr = m_szBuffer;
		}
		strncpy(m_szBuffer,pStr,cchMax);
		m_szBuffer[cchMax] = '\0';
	}
}

int Mystring::Getlength()
{
	return strlen(m_pStr);
}


char* Mystring::c_str()
{
	return m_pStr;	
}

void Mystring::Myfree()
{
	if(m_pStr != m_szBuffer)
		free(m_pStr);
}


MystringArray::MystringArray() : m_pStr(NULL)
{
	m_nMaxSize = 10;
	m_nActSize = 0;

//	m_pStr = (Mystring*) new char[m_nMaxSize * sizeof(Mystring)];
	m_pStr = new Mystring[m_nMaxSize];//(Mystring*)malloc(m_nMaxSize * sizeof(Mystring));
}

MystringArray::~MystringArray()
{
//	FreestringArray();
	delete [] m_pStr;
}

void MystringArray::FreestringArray()
{
	for(int i=0;i<m_nMaxSize;i++)
	{
		m_pStr[i].~Mystring();
	}
}

void MystringArray::Append(const Mystring& src)
{
	if(m_nActSize == m_nMaxSize)
	{
//		int newMaxSize = m_nMaxSize + 10;
//		Mystring* pTemp = new Mystring[newMaxSize];
//		assert(pTemp);
		
//		memcpy(pTemp,m_pStr,sizeof(Mystring) * m_nMaxSize);

//		FreestringArray();
//		delete [] m_pStr;
		
//		m_nMaxSize = newMaxSize;
//		m_nMaxSize += 10;
//		m_pStr = (Mystring*)realloc(m_pStr,m_nMaxSize * sizeof(Mystring));

//		FreestringArray();
		int newMaxSize = m_nMaxSize + 10;
		Mystring* pTemp = new Mystring[newMaxSize];//(Mystring*)new char[newMaxSize * sizeof(Mystring)];//new Mystring[newMaxSize];
		for(int i=0;i<m_nActSize;i++)
		{
			pTemp[i] = m_pStr[i];
		}
//		FreestringArray();
		delete [] m_pStr;
		m_pStr = NULL;
		m_pStr = pTemp;//(Mystring*)malloc(m_nMaxSize * sizeof(Mystring));
		m_nMaxSize = newMaxSize;
	}
	m_pStr[m_nActSize++] = src;
}

bool MystringArray::GetAt(int nIndex,Mystring& dest)
{
	if(nIndex < 0 || nIndex >= m_nActSize)
		return false;
	dest = m_pStr[nIndex];
}

int MystringArray::GetSize(void)const
{
	return m_nActSize;
}

int main()
{
//	Mystring str("123456fsdfsdfsdgfsgsdfgklfl;skfdjsjkdfjsdfhjsdfsjfdsahjfdfuiweruwreyw6787w8jsjdfhsjkdfjsdjfjfksakjfdhasdfjsdjfnjh");

//	char* pStr = str.c_str();

//	Mystring str1(str);

//	Mystring str2("1234fsfskdfkskdfjksdkfkksafdk");

	
//	str1 = str2;

//	cout<<(str1.c_str())<<endl;

	MystringArray array;
	
	Mystring str1("123");
	Mystring str2("2");
	Mystring str3("3");
	Mystring str4("4");
	Mystring str5("5");
	Mystring str6("6");
	Mystring str7("7");
	Mystring str8("8");
	Mystring str9("9");
	Mystring str10("10");
	Mystring str11("11");
//	cout<<str1.c_str()<<" "<<str2.c_str()<<" "<<str3.c_str()<<" "<<endl;

	array.Append(str1);
	array.Append(str2);
	array.Append(str3);
	array.Append(str4);
	array.Append(str5);
	array.Append(str6);
	array.Append(str7);
	array.Append(str8);
	array.Append(str9);
	array.Append(str10);
	array.Append(str11);

	Mystring strDest;

	int size = array.GetSize();
	for(int i=0;i<size;i++)
	{
		array.GetAt(i,strDest);
		cout<<strDest.c_str()<<endl;
	}

	
	/*
	Mystring str1 = "123";
	Mystring str2 = "456";

	Mystring* pStr = new Mystring[2];
	pStr[0] = str1;
	pStr[1] = str2;


	delete [] pStr;
	*/
    strDest.Getlength();
	return 0;
}
