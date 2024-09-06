#include "CPU.hpp"

void cpu::fillOpcodeTable(){
  //ADC
  opcodeTable[0x69] = {
    &cpu::ADC,
    AddressingMode::Immediate,
    2,
    2
  };

  opcodeTable[0x65] = {
    &cpu::ADC,
    AddressingMode::ZeroPage,
    2,
    3
  };

  opcodeTable[0x75] = {
    &cpu::ADC,
    AddressingMode::ZeroPageX,
    2,
    4
  };

  opcodeTable[0x6D] = {
    &cpu::ADC,
    AddressingMode::Absolute,
    3,
    4
  };

  opcodeTable[0x7D] = {
    &cpu::ADC,
    AddressingMode::AbsoluteX,
    3,
    4
  };

  opcodeTable[0x79] = {
    &cpu::ADC,
    AddressingMode::AbsoluteY,
    3,
    4
  };

  opcodeTable[0x61] = {
    &cpu::ADC,
    AddressingMode::IndirectX,
    2,
    6
  };

  opcodeTable[0x71] = {
    &cpu::ADC,
    AddressingMode::IndirectY,
    2, 
    5
  };


  // AND
  opcodeTable[0x29] = {
    &cpu::AND,
    AddressingMode::Immediate,
    2,
    2
  };

  opcodeTable[0x25] = {
    &cpu::AND,
    AddressingMode::ZeroPage,
    2,
    3
  }; 

  opcodeTable[0x35] = {
    &cpu::AND,
    AddressingMode::ZeroPageX,
    2,
    4
  };

  opcodeTable[0x2D] = {
    &cpu::AND,
    AddressingMode::Absolute,
    3,
    4
  };

  opcodeTable[0x3D] = {
    &cpu::AND,
    AddressingMode::AbsoluteX,
    3,
    4
  };

  opcodeTable[0x39] = {
    &cpu::AND,
    AddressingMode::AbsoluteY,
    3,
    4
  };

  opcodeTable[0x21] = {
    &cpu::AND,
    AddressingMode::IndirectX,
    2,
    6
  };

  opcodeTable[0x31] = {
    &cpu::AND,
    AddressingMode::IndirectY,
    2,
    5
  };

  // ASL
  
  opcodeTable[0x0A] = {
    &cpu::ACCASL,
    AddressingMode::Accumulator,
    1,
    2
  };

  opcodeTable[0x06] = {
    &cpu::ASL,
    AddressingMode::ZeroPage,
    2,
    5
  };

  opcodeTable[0x16] = {
    &cpu::ASL,
    AddressingMode::ZeroPageX,
    2,
    6
  };


  opcodeTable[0x0E] = {
    &cpu::ASL,
    AddressingMode::Absolute,
    3,
    6
  };

  opcodeTable[0x1E] = {
    &cpu::ASL,
    AddressingMode::AbsoluteX,
    3,
    7
  };
}
