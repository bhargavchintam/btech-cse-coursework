-- JK flip-flop, rising edge, async reset. 11 toggles.
-- ghdl -a jk_flipflop.vhd jk_flipflop_tb.vhd && ghdl -e jk_flipflop_tb && ghdl -r jk_flipflop_tb
library ieee;
use ieee.std_logic_1164.all;

entity jk_flipflop is
  port (j, k, clk, rst : in std_logic; q : out std_logic);
end jk_flipflop;

architecture behavioural of jk_flipflop is
  signal state : std_logic := '0';
begin
  process (clk, rst)
  begin
    if rst = '1' then
      state <= '0';
    elsif rising_edge(clk) then
      if j = '0' and k = '1' then
        state <= '0';
      elsif j = '1' and k = '0' then
        state <= '1';
      elsif j = '1' and k = '1' then
        state <= not state;   -- toggle
      end if;
    end if;
  end process;
  q <= state;
end behavioural;
