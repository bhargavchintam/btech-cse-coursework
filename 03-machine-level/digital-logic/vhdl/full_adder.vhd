-- full adder (dataflow).  ghdl -a full_adder.vhd full_adder_tb.vhd && ghdl -e full_adder_tb && ghdl -r full_adder_tb
library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
  port (a, b, cin : in std_logic; sum, cout : out std_logic);
end full_adder;

architecture dataflow of full_adder is
begin
  sum  <= a xor b xor cin;
  cout <= (a and b) or (b and cin) or (a and cin);
end dataflow;
