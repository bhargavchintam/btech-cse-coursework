-- 4-bit up/down counter (up_down=1 up, 0 down).  ghdl -a up_down_counter.vhd up_down_counter_tb.vhd && ghdl -e up_down_counter_tb && ghdl -r up_down_counter_tb
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity up_down_counter is
  port (up_down, clk, rst : in std_logic; q : out std_logic_vector(3 downto 0));
end up_down_counter;

architecture behavioural of up_down_counter is
  signal cnt : unsigned(3 downto 0) := "0000";
begin
  process (clk, rst)
  begin
    if rst = '1' then
      cnt <= "0000";
    elsif rising_edge(clk) then
      if up_down = '1' then cnt <= cnt + 1; else cnt <= cnt - 1; end if;
    end if;
  end process;
  q <= std_logic_vector(cnt);
end behavioural;
