library ieee;
use ieee.std_logic_1164.all;
entity t_flipflop_tb is end t_flipflop_tb;
architecture tb of t_flipflop_tb is
  signal t, clk, rst, q : std_logic;
begin
  dut : entity work.t_flipflop port map (t, clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; t <= '0'; wait for 12 ns; assert q='0' report "reset fail" severity error;
    rst <= '0';
    t <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "t1 fail" severity error;
    wait until rising_edge(clk); wait for 1 ns; assert q='0' report "t2 fail" severity error;
    t <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q='0' report "hold fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
