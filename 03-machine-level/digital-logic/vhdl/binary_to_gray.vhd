-- 4-bit binary to gray code.  ghdl -a binary_to_gray.vhd binary_to_gray_tb.vhd && ghdl -e binary_to_gray_tb && ghdl -r binary_to_gray_tb
library ieee;
use ieee.std_logic_1164.all;

entity binary_to_gray is
  port (b : in std_logic_vector(3 downto 0);
        g : out std_logic_vector(3 downto 0));
end binary_to_gray;

architecture dataflow of binary_to_gray is
begin
  g(3) <= b(3);
  g(2) <= b(3) xor b(2);
  g(1) <= b(2) xor b(1);
  g(0) <= b(1) xor b(0);
end dataflow;
