library ieee;
use ieee.std_logic_1164.all;
entity shift_register_4bit_tb is end shift_register_4bit_tb;
architecture tb of shift_register_4bit_tb is
  signal serial_in, clk, rst, serial_out : std_logic;
  signal q : std_logic_vector(3 downto 0);
begin
  dut : entity work.shift_register_4bit port map (serial_in, clk, rst, q, serial_out);
  clk_gen : process begin clk <= '0'; wait for 5 ns; clk <= '1'; wait for 5 ns; end process;
  process
  begin
    rst <= '1'; serial_in <= '0'; wait for 12 ns; assert q="0000" report "reset fail" severity error;
    rst <= '0';
    serial_in <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q="1000" report "s1 fail" severity error;
    serial_in <= '0'; wait until rising_edge(clk); wait for 1 ns; assert q="0100" report "s2 fail" severity error;
    serial_in <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q="1010" report "s3 fail" severity error;
    serial_in <= '1'; wait until rising_edge(clk); wait for 1 ns; assert q="1101" report "s4 fail" severity error;
    report "all cases passed" severity note; wait;
  end process;
end tb;
