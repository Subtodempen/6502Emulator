#include "CPU.hpp"


cpu::cpu(){
  registers.PC = mem.readWord(resetVector);
  registers.SP = stackEnd;
  
  registers.A = 0;
  registers.X = 0;
  registers.Y = 0;
  registers.PS = 0;
}


void cpu::fillOpcodeTable(){
  opcodeTable[0x0] = {
    &cpu::BRK,
    AddressingMode::Implied,
    1,
    7
  };
}
