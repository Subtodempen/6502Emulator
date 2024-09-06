#include "CPU.hpp"
#include <cstdint>


std::uint16_t cpu::ImmediateAddressing(){
  return registers.PC;
} 

std::uint16_t cpu::ZeroPageAddressing(){
  return mem.readByte(registers.PC);
}

std::uint16_t cpu::RelativeAddressing(){
  return (registers.PC + 1) + mem.readByte(registers.PC);
}

std::uint16_t cpu::AbsoluteAddressing(){
  std::uint16_t high = mem.readByte(registers.PC);
  std::uint16_t low = mem.readByte(registers.PC + 1);

  return ((low << 8) | high);
}

std::uint16_t cpu::IndirectAddressing(){
  return mem.readByte(AbsoluteAddressing());
}

std::uint16_t cpu::decodeAddressing(AddressingMode addressing){ // return the address
  std::uint16_t addr = 0;

  switch (addressing) {
    case AddressingMode::Immediate:
      addr = ImmediateAddressing();
      break;  

    case AddressingMode::ZeroPage:
      addr = ZeroPageAddressing();
      break;

    case AddressingMode::ZeroPageX:
      addr = ZeroPageAddressing() + registers.X;
      break;

    case AddressingMode::ZeroPageY:
      addr = ZeroPageAddressing() + registers.Y;
      break;
      
    case AddressingMode::Relative:
      addr = RelativeAddressing();
      break;

    case AddressingMode::Absolute:
      addr = AbsoluteAddressing();
      break;

    case AddressingMode::AbsoluteX:
      addr = AbsoluteAddressing() + registers.X;
      break;

    case AddressingMode::AbsoluteY:
      addr = AbsoluteAddressing() + registers.Y;
      break;

    case AddressingMode::Indirect:
      addr = IndirectAddressing();
      break;

    case AddressingMode::IndirectX:
      addr = IndirectAddressing() + registers.X;
      break;

    case AddressingMode::IndirectY:
      addr = IndirectAddressing() + registers.Y;

    case AddressingMode::Implicit:
    case AddressingMode::Accumulator:
    default:
      break;
  }
  
  return addr;
}


