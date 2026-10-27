-- half adder.  ghdl -a half_adder.vhd half_adder_tb.vhd && ghdl -e half_adder_tb && ghdl -r half_adder_tb
library ieee;
use ieee.std_logic_1164.all;

entity half_adder is
  port (a, b : in std_logic; sum, carry : out std_logic);
end half_adder;

architecture dataflow of half_adder is
begin
  sum   <= a xor b;
  carry <= a and b;
end dataflow;
