library ieee;
use ieee.std_logic_1164.all;

entity half_adder_tb is end half_adder_tb;

architecture tb of half_adder_tb is
  signal a, b, sum, carry : std_logic;
begin
  dut : entity work.half_adder port map (a, b, sum, carry);
  process
  begin
    a <= '0'; b <= '0'; wait for 5 ns; assert sum='0' and carry='0' report "00 fail" severity error;
    a <= '0'; b <= '1'; wait for 5 ns; assert sum='1' and carry='0' report "01 fail" severity error;
    a <= '1'; b <= '0'; wait for 5 ns; assert sum='1' and carry='0' report "10 fail" severity error;
    a <= '1'; b <= '1'; wait for 5 ns; assert sum='0' and carry='1' report "11 fail" severity error;
    report "all cases passed" severity note;
    wait;
  end process;
end tb;
