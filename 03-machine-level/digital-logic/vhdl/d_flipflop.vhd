-- D flip-flop, rising edge, async reset.  ghdl -a d_flipflop.vhd d_flipflop_tb.vhd && ghdl -e d_flipflop_tb && ghdl -r d_flipflop_tb
library ieee;
use ieee.std_logic_1164.all;

entity d_flipflop is
  port (d, clk, rst : in std_logic; q : out std_logic);
end d_flipflop;

architecture behavioural of d_flipflop is
begin
  process (clk, rst)
  begin
    if rst = '1' then
      q <= '0';
    elsif rising_edge(clk) then
      q <= d;
    end if;
  end process;
end behavioural;
