-- 4:1 multiplexer.  ghdl -a mux_4to1.vhd mux_4to1_tb.vhd && ghdl -e mux_4to1_tb && ghdl -r mux_4to1_tb
library ieee;
use ieee.std_logic_1164.all;

entity mux_4to1 is
  port (d : in std_logic_vector(3 downto 0);
        sel : in std_logic_vector(1 downto 0);
        y : out std_logic);
end mux_4to1;

architecture behavioural of mux_4to1 is
begin
  with sel select
    y <= d(0) when "00",
         d(1) when "01",
         d(2) when "10",
         d(3) when others;
end behavioural;
