//
//  DOOMData.cpp
//  Doomgine
//
//  Created by Matthew Harris on 13/09/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#include "DOOMData.hpp"

// Reads a signed short from a byte stream
static short ReadShort(const uint8_t *pData, int offset)
{
    return (pData[offset + 1] << 8) | pData[offset];
}

static unsigned short ReadUnsignedShort(const uint8_t *pData, const int offset)
{
    return (pData[offset + 1] << 8) | pData[offset];
}

static int ReadInteger(const uint8_t *pData, int offset)
{
    return (pData[offset + 3] << 24) |
    (pData[offset + 2] << 16) |
    (pData[offset + 1] << 8) |
    pData[offset];
}

static unsigned int ReadUnsignedInteger(const uint8_t *pData, int offset)
{
    return (pData[offset + 3] << 24) |
    (pData[offset + 2] << 16) |
    (pData[offset + 1] << 8) |
    pData[offset];
}

static void CopyAndCapitalizeBuffer(std::string &destination, const uint8_t *pSrc, unsigned int offset, unsigned int srcLength)
{
    destination = "";
    unsigned int i = 0;
    
    // copy capitalized characters to destination buffer
    while(i < srcLength && pSrc[offset + i] != 0) {
        destination += toupper(pSrc[offset + i++]);
    }
}

DOOMData::DOOMData() {}

DOOMData::~DOOMData() {}

int DOOMData::ReadWADHeader(const uint8_t *pData) {
    unsigned int offset = 0;
    
    // Read WAD type
    CopyAndCapitalizeBuffer(m_wadHeader.type, pData, offset, WADFILE_WAD_TYPE_LENGTH);
    offset += WADFILE_WAD_TYPE_LENGTH;
    
    // Read the number of directories
    m_wadHeader.directoryEntries = ReadUnsignedInteger(pData, offset);
    offset += WADFILE_SIZEOF_UNSIGNED_INTEGER;
    
    // Read the offset which specifies how far into data buffer we need to go to find first directory entry
    m_wadHeader.directoryOffset = ReadUnsignedInteger(pData, offset);
    
    std::cout << "Type: " + m_wadHeader.type << std::endl;
    std::cout << "Directory entry count (lumps): " + std::to_string(m_wadHeader.directoryEntries) << std::endl;
    std::cout << "Offset to directory: " + std::to_string(m_wadHeader.directoryOffset) << std::endl;
    
    return 1;
}

int DOOMData::LoadMission(std::string wadFilePath, std::string missionName) {
    return 1;
}
