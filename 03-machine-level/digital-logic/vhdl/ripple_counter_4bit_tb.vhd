library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity ripple_counter_4bit_tb is end ripple_counter_4bit_tb;
architecture tb of ripple_counter_4bit_tb is
  signal clk, rst : std_logic;
  signal q : std_logic_vector(3 downto 0);
begin
  dut : entity work.ripple_counter_4bit port map (clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; wait for 12 ns; assert q="0000" report "reset fail" severity error;
    rst <= '0';
    for i in 1 to 17 loop
      wait until rising_edge(clk); wait for 1 ns;
      assert q = std_logic_vector(to_unsigned(i mod 16, 4)) report "count fail" severity error;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
