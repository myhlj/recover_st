#ifndef MYSTRING_H
#define MYSTRING_H


class Mystring
{
	public:
		enum{ MAX_LOCAL_STRING = 63 };
		Mystring();
		Mystring(const char* pStr,int nLen = -1);
		Mystring(const Mystring& src);
		~Mystring();
		
		const Mystring& operator=(const Mystring& src);

		int Getlength();

		char* c_str();
	private:
		void Assign(const char* pStr,int cchMax = -1);
		void Myfree();
	private:
		char* m_pStr;
		char m_szBuffer[MAX_LOCAL_STRING + 1];
};


class MystringArray
{
	public:
		MystringArray();
		~MystringArray();

		void Append(const Mystring& src);
		bool GetAt(int nIndex,Mystring& dest);
		int GetSize(void)const; 

	private:
		Mystring* m_pStr;

		int m_nMaxSize;//数组的最大个数
		int m_nActSize;//数组中实际元素个数
	private:
		void FreestringArray();
};

#endif
