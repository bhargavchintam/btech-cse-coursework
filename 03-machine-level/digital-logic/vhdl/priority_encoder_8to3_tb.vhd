library ieee;
use ieee.std_logic_1164.all;
entity priority_encoder_8to3_tb is end priority_encoder_8to3_tb;
architecture tb of priority_encoder_8to3_tb is
  signal d : std_logic_vector(7 downto 0);
  signal y : std_logic_vector(2 downto 0);
  signal valid : std_logic;
begin
  dut : entity work.priority_encoder_8to3 port map (d, y, valid);
  process
  begin
    d <= "00000000"; wait for 5 ns; assert valid='0' report "valid fail" severity error;
    d <= "00000001"; wait for 5 ns; assert y="000" and valid='1' report "d0 fail" severity error;
    d <= "00010000"; wait for 5 ns; assert y="100" report "d4 fail" severity error;
    d <= "10000000"; wait for 5 ns; assert y="111" report "d7 fail" severity error;
    d <= "10010110"; wait for 5 ns; assert y="111" report "priority fail" severity error;
    d <= "00110000"; wait for 5 ns; assert y="101" report "d5 over d4 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
