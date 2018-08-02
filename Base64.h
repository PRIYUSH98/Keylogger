#ifndef Base64_H
#define Base64_H

#include<vector>
#include<string>

namespace Base64
{
    std::string base64_encode(const std::string &);

    const std::string &salt1= "LM::TB::BB";
    const std::string &salt2= "_:/_77";
    const std::string &salt3= "line=wowC++";

    std::string EncryptB64(std::string s)
    {
        s= salt1+s+salt2+salt3;
        s=base64_encode(s);
        s.insert(7,salt3);
        s+=salt1;
        s=base64_encode(s);
        s=salt1+salt2+salt3;
        s=base64_encode(s);
        s.insert(1,"L");
        s.insert(7,"M");
        return s;

    }
    std::string Base64_codes="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvw0123456789+/";

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val=0;
        int bits=-6;
        const unsigned int b63=0x3F;

        for(const auto &c:s)
        {
            val= (val<<8)+c;
            bits+=8;
            while(bits>=0)
            {
                ret.push_back(Base64_codes[(val>>bits) & b63]);
                bits -=6;
            }
        }
        if(bits >-6)
            ret.push_back(Base64_codes[((val << 8) >>(bits+8)) & b63]);
        while (ret.size() % 4)
            ret.push_back('=');
        return ret;
    }
    //2^8
}


#endif // Base64_H
