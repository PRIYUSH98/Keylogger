#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
namespace Helper
{
    //template <class type> ret-type func-name(parameter list) {
   // body of function}
    template <class T>
    inline std::string ToString(const T &);

    struct DateTime
    {
        time_t ms; //time_t is a default type in ctime library
        time (&ms);

        struct tm *info =localtime(&ms); //struct tm is default type in ctime which contains different components of a time like sec/min/hr/day etc..
        D= info->tm_day;
        m= info->tm_mon+1;
        y= 1900+info->tm_year;
        M= info->tm_min;
        H=info->tm_hour;
        S=info->tm_sec;
        DateTime(int D,int m,int y,int H,int M,int S):D(D),m(m),y(y),H(H),M(M,S(S){}
        DateTime(int D,int m,int y):D(D,m(m),y(y),H(0),M(0),S(0) {}
        DateTime_now() const
        {
            return DateTime();
        }
        int D,m,y,H,M,S;

        std::string GetDateString() const //this const means it can't change the obj which will call it
        {
            return std::string(D<10 ? "0":"")+ToString(D)+
                    std::string(m<10 ? "0":"")+ToString(m)+"."+
                    ToString(y);

        }
        std:: string GetTimeString(const std::string &sep=":") const
        {
            return std::string(H<10 ? "0":" ")+ToString(H)+sep+
                    std::string(M<10 ? "0":"")+ToString(M)+sep+
                    std::string(s<10 ?sep :"")+ToString(S);
        }

        std::string GetDateTimeString(const std::string &sep =":") const
        {
            return GetDateString() +" "+ GetTimeString(sep)
        }
    };

template <class T>

std::string ToString(const T &e)
{
    std::ostringstream s; //
    s << e; //insertion operator
    return s.str();
}
void WriteAPPLog(const std::string &s)
{
    std::ofstream file("Applog.txt",std::ios::app);
    //Helper::DateTime()<this the destructor made>.GetDateTimeString()<this the method of Datetime structure> | here Helper is a namespace like std but we designed
    file << " "<<Helper::DateTime().GetDateTimeString()<<" "<<"\n"<<s<<std::endl<<"\n";
    file.close();
}

}
#endif // HELPER_H
