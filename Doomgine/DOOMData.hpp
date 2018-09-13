//
//  DOOMData.hpp
//  Doomgine
//
//  Created by Matthew Harris on 13/09/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#ifndef DOOMData_hpp
#define DOOMData_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

const int WADFILE_WAD_TYPE_LENGTH = 4; // bytes
const int WADFILE_SIZEOF_UNSIGNED_INTEGER = 4;

// WadHeader
struct WADHeader
{
    std::string type;
    unsigned int directoryEntries;
    unsigned int directoryOffset;
};

class DOOMData
{
public:
    DOOMData();
    ~DOOMData();
    
    int ReadWADHeader(const uint8_t *pData);
    int LoadMission(std::string wadFilePath, std::string missionName);
    
private:
//    std::string m_WADFilePath, m_WADMissionName;
    WADHeader m_wadHeader;
};

#endif /* DOOMData_hpp */
