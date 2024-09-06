#include <cstdint>
#include <unordered_map>
#include <functional>

#include "../Memory/memory.hpp"

class cpu;

enum class AddressingMode{
  Absolute,
  AbsoluteX,
  AbsoluteY,
  Accumulator,
  Relative,
  Immediate,
  Implied,
  Implicit,
  ZeroPage,
  ZeroPageX,
  ZeroPageY,
  Indirect,
  IndirectX,
  IndirectY
};



struct Instruction{
  std::function<void(cpu&, std::uint16_t)> code;
  AddressingMode addressing;
  
  uint8_t bytes;
  uint8_t clockCycles;
};


struct Registers{
  Registers() { clear(); }
  void clear();

  std::uint16_t PC;
  std::uint8_t SP;
  std::uint8_t A;

  std::uint8_t X;
  std::uint8_t Y;
  
  std::uint8_t SF;

  enum StatusLocation{
    Carry = 0,
    Zero = 1,
    Interrupt = 2,
    Decimal = 3,
    Break = 4,
    Empty = 5,
    Overflow = 6,
    Negative = 7
  };
};


class cpu{
  public:
    cpu();
    cpu(Memory&);

    void exec();
    void print();
  
  protected:
    Registers registers;
    Memory mem;
    
    void init();

    std::unordered_map<std::uint8_t, Instruction> opcodeTable;
    void fillOpcodeTable(); 
    
    void setStatusFlag(std::uint8_t index, bool data);
    bool getStatusFlag(std::uint8_t index);

    std::uint16_t decodeAddressing(AddressingMode);

    std::uint16_t ImmediateAddressing();
    std::uint16_t ZeroPageAddressing();
    std::uint16_t RelativeAddressing();
    std::uint16_t AbsoluteAddressing();
    std::uint16_t IndirectAddressing();

    void ADC(std::uint16_t);
    void AND(std::uint16_t);
    void ASL(std::uint16_t);
    void ACCASL(std::uint16_t);
    void BCC(std::uint16_t);
    void BCS(std::uint16_t);
    void BEQ(std::uint16_t);
    void BIT(std::uint16_t);
    void BMI(std::uint16_t);
    void BNE(std::uint16_t);
    void BPL(std::uint16_t);
    void BRK(std::uint16_t);
    void BVC(std::uint16_t);
    void BVS(std::uint16_t);
    void CLC(std::uint16_t);
    void CLD(std::uint16_t);
    void CLI(std::uint16_t);
    void CLV(std::uint16_t);
    void CMP(std::uint16_t);
    void CPX(std::uint16_t);
    void CPY(std::uint16_t);
    void DEC(std::uint16_t);
    void DEX(std::uint16_t);
    void DEY(std::uint16_t);  
    void EOR(std::uint16_t);
    void INC(std::uint16_t);
    void INX(std::uint16_t);
    void INY(std::uint16_t);
    void JMP(std::uint16_t);
    void JSR(std::uint16_t);
    void LDA(std::uint16_t);
    void LDX(std::uint16_t);
    void LDY(std::uint16_t);
    void LSR(std::uint16_t);
    void NOP(std::uint16_t);
    void ORA(std::uint16_t);
    void PHA(std::uint16_t);
    void PHP(std::uint16_t);
    void PLA(std::uint16_t);
    void PLP(std::uint16_t);
    void ROL(std::uint16_t);
    void ROR(std::uint16_t);
    void RTI(std::uint16_t);
    void RTS(std::uint16_t);
    void SBC(std::uint16_t);
    void SEC(std::uint16_t);
    void SED(std::uint16_t);
    void SEI(std::uint16_t);
    void STA(std::uint16_t);
    void STX(std::uint16_t);
    void STY(std::uint16_t);
    void TAX(std::uint16_t);
    void TAY(std::uint16_t);
    void TSX(std::uint16_t);
    void TXA(std::uint16_t);
    void TXS(std::uint16_t);
    void TYA(std::uint16_t);
};
