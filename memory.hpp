#pragma once

#include <array>
#include <cstdint>
#include <algorithm>
#include <iterator>


const std::uint16_t zeroPageStart = 0x0000;
const std::uint16_t zeroPageEnd = 0x00FF;

const std::uint16_t stackStart = 0x00FF;
const std::uint16_t stackEnd = 0x01FF;

const std::uint16_t mainMemorySize = 0xFFFF - 0x6;

const std::uint16_t nonMaskableVector = 0xFFFA;
const std::uint16_t resetVector = 0xFFFC;
const std::uint16_t interruptReqVector = 0xFFFE;


class Memory{
  public:
    Memory();

    void pushStack(const std::uint8_t data, std::uint8_t& SP);
    std::uint8_t popStack(std::uint8_t& SP);
  
    std::uint8_t readByte(const std::uint16_t addr) const; 
    void writeByte(const std::uint16_t addr, const std::uint8_t data); 
    
    std::uint16_t readWord(const std::uint16_t addr) const;

  private:
    std::array<std::uint8_t, mainMemorySize> memory;
};
