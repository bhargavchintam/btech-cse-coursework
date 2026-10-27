-- 4-bit up counter (0..15 wrap).  ghdl -a ripple_counter_4bit.vhd ripple_counter_4bit_tb.vhd && ghdl -e ripple_counter_4bit_tb && ghdl -r ripple_counter_4bit_tb
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ripple_counter_4bit is
  port (clk, rst : in std_logic; q : out std_logic_vector(3 downto 0));
end ripple_counter_4bit;

architecture behavioural of ripple_counter_4bit is
  signal cnt : unsigned(3 downto 0) := "0000";
begin
  process (clk, rst)
  begin
    if rst = '1' then
      cnt <= "0000";
    elsif rising_edge(clk) then
      cnt <= cnt + 1;
    end if;
  end process;
  q <= std_logic_vector(cnt);
end behavioural;
