#include <iostream>  
#ifndef MYSTRING_H  
#define MYSTRING_H


class myString 
{
    private:

	    int size; 
	    char* data;  
	    int calculateLength(const char* str) const;
	    void copyString(char* dest, const char* src) const;

    public:

  
	    myString(const char* str);
	    myString();
	    
	    virtual ~myString();
	   
	    myString(const myString& other);
	    
	    
	    
	    int getSize() const;
	    const char* getData() const;
};
#endif  
    
    
    
    
    
    
    
    
    
