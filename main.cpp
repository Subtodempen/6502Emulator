#include "CPU/CPU.hpp"
#include "Memory/memory.hpp"
#include <cstdint>
#include <iostream>
#include <vector>


int main(){
  Memory mem;
  std::vector<std::uint8_t> vecMemory;
  
  vecMemory.push_back(0x69);
  vecMemory.push_back(0xFF);

  mem.setMemoryArray(vecMemory);
     
  cpu mosCpu(mem);
  mosCpu.print(); 
  mosCpu.exec();
  mosCpu.print();
  //mosCpu.exec();

}
