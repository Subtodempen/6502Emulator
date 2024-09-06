#include <gtest/gtest.h>

#include <numeric>

#include "../src/CPU/CPU.hpp"
#include "../src/Memory/memory.hpp"



class cpuTest : public testing::Test, public cpu{
  protected:
    void SetUp() override{
      std::vector<std::uint8_t> consecVec(0xFFFF);
      std::iota(consecVec.begin(), consecVec.end(), 0);
      
      mem.setMemoryArray(consecVec); 
      init();
  };
};


TEST_F(cpuTest, AddressingModes){
  registers.PC = 0xFFF0;

  std::uint16_t valueLocation = ImmediateAddressing();
  EXPECT_EQ(registers.PC, valueLocation);

  registers.PC = 0x10;
  
  mem.writeByte(0x10, 0xF);

  valueLocation = ZeroPageAddressing();
  EXPECT_EQ(valueLocation, 0xF);

  registers.PC = 0x2;
  
  valueLocation = RelativeAddressing();
  EXPECT_EQ(valueLocation, 0x5);

  registers.PC = 0x1;
  
  valueLocation = AbsoluteAddressing();
  EXPECT_EQ(valueLocation, 0x0201);

}

TEST_F(cpuTest, stackCheck){
  const uint8_t x = 2;
  mem.pushStack(x, registers.SP);
  EXPECT_EQ(mem.popStack(registers.SP), x);
}

TEST_F(cpuTest, basicUsageADC){
  ADC(0x1);
  EXPECT_EQ(registers.A, 0x1);
}

TEST_F(cpuTest, basicUsageAND){
  registers.A = 0x5;
  AND(0x5);

  EXPECT_EQ(registers.A, 0x5 & 0x5);
}
