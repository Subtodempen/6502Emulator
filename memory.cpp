#include "memory.hpp"
#include <stdexcept>


Memory::Memory(){
  std::fill(std::begin(memory), std::end(memory), 0);
}


std::uint8_t Memory::readByte(const std::uint16_t addr) const{
  if(mainMemorySize < addr)
    throw std::runtime_error("out of bounds memory?");

  return memory.at(addr);
}

void Memory::writeByte(const std::uint16_t addr, const std::uint8_t data){
  if(mainMemorySize < addr)
    throw std::runtime_error("accessing out of bounds memory");

  memory.at(addr) = data;
}

std::uint16_t Memory::readWord(const std::uint16_t addr) const {
  std::uint16_t word = 0;
  
  word += readByte(addr); 
  word |= (readByte(addr + 1) << 4);

  return word;
}


void Memory::pushStack(const std::uint8_t data, std::uint8_t& SP){
  if(stackStart > SP)
	return;

  writeByte(stackEnd - SP, data);
  SP--;
}

std::uint8_t Memory::popStack(std::uint8_t& SP){
  if(stackEnd < SP)
	return 0;

  std::uint8_t data = readByte(stackEnd - SP); 

  SP++;
  return data;
}
