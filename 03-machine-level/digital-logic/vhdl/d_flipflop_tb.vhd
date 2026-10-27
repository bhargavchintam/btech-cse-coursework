library ieee;
use ieee.std_logic_1164.all;
entity d_flipflop_tb is end d_flipflop_tb;
architecture tb of d_flipflop_tb is
  signal d, clk, rst, q : std_logic;
begin
  dut : entity work.d_flipflop port map (d, clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; d <= '0'; wait for 12 ns; assert q='0' report "reset fail" severity error;
    rst <= '0';
    d <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "d1 fail" severity error;
    d <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q='0' report "d0 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
