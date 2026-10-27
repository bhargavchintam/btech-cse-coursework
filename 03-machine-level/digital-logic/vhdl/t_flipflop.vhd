-- T flip-flop, rising edge, async reset. t=1 toggles.
-- ghdl -a t_flipflop.vhd t_flipflop_tb.vhd && ghdl -e t_flipflop_tb && ghdl -r t_flipflop_tb
library ieee;
use ieee.std_logic_1164.all;

entity t_flipflop is
  port (t, clk, rst : in std_logic; q : out std_logic);
end t_flipflop;

architecture behavioural of t_flipflop is
  signal state : std_logic := '0';
begin
  process (clk, rst)
  begin
    if rst = '1' then
      state <= '0';
    elsif rising_edge(clk) then
      if t = '1' then state <= not state; end if;
    end if;
  end process;
  q <= state;
end behavioural;
