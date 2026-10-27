-- decade (mod-10) counter 0..9.  ghdl -a mod10_counter.vhd mod10_counter_tb.vhd && ghdl -e mod10_counter_tb && ghdl -r mod10_counter_tb
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mod10_counter is
  port (clk, rst : in std_logic; q : out std_logic_vector(3 downto 0));
end mod10_counter;

architecture behavioural of mod10_counter is
  signal cnt : unsigned(3 downto 0) := "0000";
begin
  process (clk, rst)
  begin
    if rst = '1' then
      cnt <= "0000";
    elsif rising_edge(clk) then
      if cnt = 9 then cnt <= "0000"; else cnt <= cnt + 1; end if;
    end if;
  end process;
  q <= std_logic_vector(cnt);
end behavioural;
