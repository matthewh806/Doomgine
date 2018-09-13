//
//  main.cpp
//  Doomgine
//
//  Created by Matthew Harris on 12/09/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#include <iostream>
#include "DOOMData.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, Doomgine!" << std::endl;
    
    DOOMData* data = new DOOMData();
    
    // TODO: Don't hardcode this.
    std::ifstream wadFile("/Users/matthewharris/Projects/personal/Doomgine/Doomgine/Doom1.WAD", std::ios::binary | std::ios::ate);
    
    if(!wadFile.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 0;
    }
    
    std::streamsize size = wadFile.tellg();
    
    uint8_t *pData = new uint8_t[(unsigned int) size];
    wadFile.seekg(0, std::ios::beg);
    wadFile.read((char *)pData, size);
    
    data->ReadWADHeader(pData);
    
    // free buffer
    if(pData)
        delete[] pData;
    
    std::cout << "Goodbye, Doomgine!" << std::endl;
    
    return 0;
}
