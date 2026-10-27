library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity up_down_counter_tb is end up_down_counter_tb;
architecture tb of up_down_counter_tb is
  signal up_down, clk, rst : std_logic;
  signal q : std_logic_vector(3 downto 0);
begin
  dut : entity work.up_down_counter port map (up_down, clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; up_down <= '1'; wait for 12 ns; assert q="0000" report "reset fail" severity error;
    rst <= '0';
    for i in 1 to 3 loop wait until rising_edge(clk); wait for 1 ns; end loop;
    assert q="0011" report "up fail" severity error;
    up_down <= '0';
    wait until rising_edge(clk); wait for 1 ns; assert q="0010" report "down1 fail" severity error;
    wait until rising_edge(clk); wait for 1 ns; assert q="0001" report "down2 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
