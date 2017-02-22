#ifndef MYSTRING_H
#define MYSTRING_H

#define MYLENGTH 63

class Mystring
{
	public:
		Mystring();
		Mystring(const char* str);
		~Mystring();
		Mystring(const Mystring& obj);
		Mystring& operator=(const Mystring& obj);
		void Assign(const char* str);
		char* c_str();
	private:
		char m_tablestr[MYLENGTH + 1];
		char* m_pStr;
};

#endif
