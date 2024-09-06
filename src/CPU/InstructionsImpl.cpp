#include "CPU.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>


//add bcd
void cpu::ADC(std::uint16_t src){
  int result = 0;
  
  result = registers.A + mem.readByte(src) + getStatusFlag(registers.Carry);
  registers.A = result;
  
  setStatusFlag(registers.Negative, (result & 0x80));
  setStatusFlag(registers.Carry, 0xFF < result);
  setStatusFlag(registers.Zero, ~(result));
}


void cpu::AND(std::uint16_t src){
  std::uint8_t data = mem.readByte(src);
  
  registers.A &= data;

  setStatusFlag(registers.Negative, (registers.A & 0x80));
  setStatusFlag(registers.Zero, !registers.A);
}


void cpu::ACCASL(std::uint16_t ACC){
  setStatusFlag(registers.Carry, (registers.A & 0x80));

  registers.A = registers.A << 1;

  setStatusFlag(registers.Zero, registers.A);
  setStatusFlag(registers.Negative, (registers.A & 0x80)); // gets last bit
}


void cpu::ASL(std::uint16_t src){
  std::uint8_t data = mem.readByte(src);

  setStatusFlag(registers.Carry, (data & 0x80));

  data = data << 1;
  mem.writeByte(src, data);

  setStatusFlag(registers.Zero, !data);
  setStatusFlag(registers.Negative, (data & 0x80));
}

void cpu::BCC(std::uint16_t src){
  if(!getStatusFlag(registers.Carry))
    registers.PC = src;
}

void cpu::BCS(std::uint16_t src){
  if(getStatusFlag(registers.Carry))
    registers.PC = src; 
}

void cpu::BEQ(std::uint16_t src){
  if(getStatusFlag(registers.Zero))
    registers.PC = src;
}


void cpu::BIT(std::uint16_t src){
  std::uint8_t operand = mem.readByte(src);
  std::uint8_t result = operand & registers.A;

  setStatusFlag(registers.Zero, !result);
  setStatusFlag(registers.Negative, (operand & 0x80));
  setStatusFlag(registers.Overflow, (operand & 0x40));
}


void cpu::BMI(std::uint16_t src){
  if(getStatusFlag(registers.Negative))
    registers.PC = src;
}

void cpu::BNE(std::uint16_t src){
  if(!getStatusFlag(registers.Zero))
    registers.PC = src;
}

void cpu::BPL(std::uint16_t src){
  if(!getStatusFlag(registers.Negative))
    registers.PC = src;
}


void cpu::BRK(std::uint16_t src){
  mem.pushStack(registers.PC, registers.SP);
  mem.pushStack(registers.SF, registers.SP);

  registers.PC = mem.readWord(interruptReqVector);

  setStatusFlag(registers.Break, 1);
}

void cpu::BVC(std::uint16_t src){
  if(!getStatusFlag(registers.Overflow))
    registers.PC = src;
}

void cpu::BVS(std::uint16_t src){
  if(getStatusFlag(registers.Overflow))
    registers.PC = src;
}


void cpu::CLC(std::uint16_t src){
  setStatusFlag(registers.Carry, 0);
}

void cpu::CLD(std::uint16_t src){
  setStatusFlag(registers.Decimal, 0);
}

void cpu::CLI(std::uint16_t src){
  setStatusFlag(registers.Interrupt, 0);
}

void cpu::CLV(std::uint16_t src){
  setStatusFlag(registers.Overflow, 0);
}

void cpu::CMP(std::uint16_t src){
  std::uint8_t M = mem.readByte(src);

  setStatusFlag(registers.Carry, registers.A >= M);
  setStatusFlag(registers.Zero, registers.A == M);
  setStatusFlag(registers.Negative, (registers.A - M) & 0x80);
}

void cpu::CPX(std::uint16_t src){
  std::uint8_t M = mem.readByte(src);

  setStatusFlag(registers.Carry, registers.X >= M);
  setStatusFlag(registers.Zero, registers.X == M);
  setStatusFlag(registers.Negative, (registers.X - M) & 0x80);
}

void cpu::CPY(std::uint16_t src){
  std::uint8_t M = mem.readByte(src);

  setStatusFlag(registers.Carry, registers.Y >= M);
  setStatusFlag(registers.Zero, registers.Y == M);
  setStatusFlag(registers.Negative, (registers.Y - M) & 0x80);
}


void cpu::DEC(std::uint16_t src){
  std::uint8_t M = mem.readByte(src);
  M--;
  mem.writeByte(src, M);
  
  setStatusFlag(registers.Zero, !M);
  setStatusFlag(registers.Negative, M & 0x80);
}

void cpu::DEX(std::uint16_t src){
  registers.X--;
  
  setStatusFlag(registers.Zero, !registers.X);
  setStatusFlag(registers.Negative, registers.X & 0x80);
}

void cpu::DEY(std::uint16_t src){
  registers.Y--;
  
  setStatusFlag(registers.Zero, !registers.Y);
  setStatusFlag(registers.Negative, registers.Y & 0x80);
}

void cpu::EOR(std::uint16_t src){
  registers.A ^= mem.readByte(src);

  setStatusFlag(registers.Zero, !registers.A);
  setStatusFlag(registers.Negative, registers.A & 0x80);
}


