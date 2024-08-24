#include <cstdint>
#include <unordered_map>
#include <functional>

#include "memory.hpp"

class cpu;

enum class AddressingMode{
  Implied,
  IndirectX
};

struct Instruction{
  std::function<void(cpu&, std::uint16_t)> code;
  AddressingMode addressing;
  
  uint8_t bytes;
  uint8_t clockCycles;
};

struct cpuRegisters{
  std::uint16_t PC;
  std::uint8_t SP;
  std::uint8_t A;

  std::uint8_t X;
  std::uint8_t Y;
  std::uint8_t PS;
};


class cpu{
  public:
    cpu();
    void exec();  

  private:
    cpuRegisters registers;
    Memory mem;

    std::unordered_map<std::uint8_t, Instruction> opcodeTable;
    inline void fillOpcodeTable(); 

    void BRK(std::uint16_t);
};
