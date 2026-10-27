-- 4-bit Johnson (twisted ring) counter.  ghdl -a johnson_counter.vhd johnson_counter_tb.vhd && ghdl -e johnson_counter_tb && ghdl -r johnson_counter_tb
library ieee;
use ieee.std_logic_1164.all;

entity johnson_counter is
  port (clk, rst : in std_logic; q : out std_logic_vector(3 downto 0));
end johnson_counter;

architecture behavioural of johnson_counter is
  signal reg : std_logic_vector(3 downto 0) := "0000";
begin
  process (clk, rst)
  begin
    if rst = '1' then
      reg <= "0000";
    elsif rising_edge(clk) then
      reg <= (not reg(0)) & reg(3 downto 1);
    end if;
  end process;
  q <= reg;
end behavioural;
