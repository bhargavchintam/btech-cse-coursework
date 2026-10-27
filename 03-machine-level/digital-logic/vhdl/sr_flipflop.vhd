-- SR flip-flop, rising edge, async reset. 11 is invalid so we hold.
-- ghdl -a sr_flipflop.vhd sr_flipflop_tb.vhd && ghdl -e sr_flipflop_tb && ghdl -r sr_flipflop_tb
library ieee;
use ieee.std_logic_1164.all;

entity sr_flipflop is
  port (s, r, clk, rst : in std_logic; q : out std_logic);
end sr_flipflop;

architecture behavioural of sr_flipflop is
  signal state : std_logic := '0';
begin
  process (clk, rst)
  begin
    if rst = '1' then
      state <= '0';
    elsif rising_edge(clk) then
      if s = '0' and r = '1' then
        state <= '0';
      elsif s = '1' and r = '0' then
        state <= '1';
      end if;   -- 00 hold, 11 invalid -> hold
    end if;
  end process;
  q <= state;
end behavioural;
