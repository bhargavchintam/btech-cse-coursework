-- all basic gates for a,b.  ghdl -a logic_gates.vhd logic_gates_tb.vhd && ghdl -e logic_gates_tb && ghdl -r logic_gates_tb
library ieee;
use ieee.std_logic_1164.all;

entity logic_gates is
  port (a, b : in  std_logic;
        g_and, g_or, g_not, g_nand, g_nor, g_xor, g_xnor : out std_logic);
end logic_gates;

architecture dataflow of logic_gates is
begin
  g_and  <= a and b;
  g_or   <= a or b;
  g_not  <= not a;
  g_nand <= a nand b;
  g_nor  <= a nor b;
  g_xor  <= a xor b;
  g_xnor <= a xnor b;
end dataflow;
