library ieee;
use ieee.std_logic_1164.all;
entity sr_flipflop_tb is end sr_flipflop_tb;
architecture tb of sr_flipflop_tb is
  signal s, r, clk, rst, q : std_logic;
begin
  dut : entity work.sr_flipflop port map (s, r, clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; s <= '0'; r <= '0'; wait for 12 ns; assert q='0' report "reset fail" severity error;
    rst <= '0';
    s <= '1'; r <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "set fail" severity error;
    s <= '0'; r <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q='1' report "hold fail" severity error;
    s <= '0'; r <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q='0' report "clr fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
