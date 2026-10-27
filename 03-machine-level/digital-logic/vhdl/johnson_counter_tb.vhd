library ieee;
use ieee.std_logic_1164.all;
entity johnson_counter_tb is end johnson_counter_tb;
architecture tb of johnson_counter_tb is
  signal clk, rst : std_logic;
  signal q : std_logic_vector(3 downto 0);
  type seq_t is array (0 to 7) of std_logic_vector(3 downto 0);
  constant seq : seq_t := ("1000","1100","1110","1111","0111","0011","0001","0000");
begin
  dut : entity work.johnson_counter port map (clk, rst, q);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; wait for 12 ns; assert q="0000" report "reset fail" severity error;
    rst <= '0';
    for i in 0 to 7 loop
      wait until rising_edge(clk); wait for 1 ns;
      assert q = seq(i) report "johnson step fail" severity error;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
