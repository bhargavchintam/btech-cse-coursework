library ieee;
use ieee.std_logic_1164.all;
entity jk_flipflop_tb is end jk_flipflop_tb;
architecture tb of jk_flipflop_tb is
  signal j, k, clk, rst, q : std_logic;
begin
  dut : entity work.jk_flipflop port map (j, k, clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; j <= '0'; k <= '0'; wait for 12 ns; assert q='0' report "reset fail" severity error;
    rst <= '0';
    j <= '1'; k <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "set fail" severity error;
    j <= '0'; k <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='0' report "clr fail" severity error;
    j <= '1'; k <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "toggle1 fail" severity error;
    j <= '1'; k <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='0' report "toggle2 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
