-- full subtractor.  ghdl -a full_subtractor.vhd full_subtractor_tb.vhd && ghdl -e full_subtractor_tb && ghdl -r full_subtractor_tb
library ieee;
use ieee.std_logic_1164.all;

entity full_subtractor is
  port (a, b, bin : in std_logic; diff, borrow : out std_logic);
end full_subtractor;

architecture dataflow of full_subtractor is
begin
  diff   <= a xor b xor bin;
  borrow <= ((not a) and b) or ((not a) and bin) or (b and bin);
end dataflow;
