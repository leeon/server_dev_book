#ifndef _PL_CPP_COUNTRY_H
#define _PL_CPP_COUNTRY_H 
#include <iostream>
#include <cstring>

using namespace std;

namespace plant
{

class Country
{
public:
    Country(const string &strName):m_strName(strName)
    {
        m_iCode = 0;
    }

    ~Country(){}

    void introduce();

private:
    int m_iCode;
    string m_strName;
    
};


}

#endif