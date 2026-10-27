library ieee;
use ieee.std_logic_1164.all;
entity bcd_to_7segment_tb is end bcd_to_7segment_tb;
architecture tb of bcd_to_7segment_tb is
  signal bcd : std_logic_vector(3 downto 0);
  signal seg : std_logic_vector(6 downto 0);
begin
  dut : entity work.bcd_to_7segment port map (bcd, seg);
  process
  begin
    bcd <= "0000"; wait for 5 ns; assert seg="1111110" report "0 fail" severity error;
    bcd <= "0001"; wait for 5 ns; assert seg="0110000" report "1 fail" severity error;
    bcd <= "1000"; wait for 5 ns; assert seg="1111111" report "8 fail" severity error;
    bcd <= "1001"; wait for 5 ns; assert seg="1111011" report "9 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
