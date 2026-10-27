library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity mux_4to1_tb is end mux_4to1_tb;
architecture tb of mux_4to1_tb is
  signal d : std_logic_vector(3 downto 0);
  signal sel : std_logic_vector(1 downto 0);
  signal y : std_logic;
begin
  dut : entity work.mux_4to1 port map (d, sel, y);
  process
  begin
    d <= "1010";
    for s in 0 to 3 loop
      sel <= std_logic_vector(to_unsigned(s, 2));
      wait for 5 ns;
      assert y = d(s) report "mux route fail" severity error;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
