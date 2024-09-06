#include "CPU.hpp"
#include <ios>
#include <iostream>


void Registers::clear(){  
  A = 0;
  X = 0;
  Y = 0;
  PC = 0;
  SP = 0;
  SF = 0;
}


void cpu::init(){ 
  registers.clear();
  registers.SP = stackEnd & 0xFF; 
  fillOpcodeTable();
}

cpu::cpu(){
  init();
}

cpu::cpu(Memory& memory): mem(memory){
  init();
  registers.PC = mem.readWord(resetVector);
}


void cpu::exec(){
  //fetch
  std::uint16_t opcode = mem.readByte(registers.PC);
  registers.PC++;

  //decode
  Instruction instr = opcodeTable.at(opcode); 
  std::uint16_t addr = decodeAddressing(instr.addressing);
  
  //exec
  instr.code(*this, addr);

  registers.PC += instr.bytes - 1;
}


void cpu::print(){
  std::cout<<"PC: "<< std::hex <<(int)registers.PC << '\n'; 
  std::cout<<"Curr Memory: "<< std::hex <<(int)mem.readByte(registers.PC) << '\n'; 
  std::cout<<"A: "<< std::hex <<(int) registers.A << '\n'; 
  std::cout<<"X: "<< std::hex <<(int) registers.X << '\n'; 
  std::cout<<"Y: "<< std::hex <<(int) registers.Y << '\n'; 
}

void cpu::setStatusFlag(std::uint8_t index, bool data){
  if(data){ registers.SF |= (1 << index); }
  else    { registers.SF &= ~(1 << index); } 
}

bool cpu::getStatusFlag(std::uint8_t index){
  return (registers.SF >> index) & 1;
}
