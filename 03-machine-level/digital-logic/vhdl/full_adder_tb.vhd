library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity full_adder_tb is end full_adder_tb;

architecture tb of full_adder_tb is
  signal a, b, cin, sum, cout : std_logic;
begin
  dut : entity work.full_adder port map (a, b, cin, sum, cout);
  process
    variable v : std_logic_vector(2 downto 0);
    variable exp : unsigned(1 downto 0);
  begin
    for i in 0 to 7 loop
      v := std_logic_vector(to_unsigned(i, 3));
      a <= v(2); b <= v(1); cin <= v(0);
      wait for 5 ns;
      exp := ('0' & v(2)) + ('0' & v(1)) + ('0' & v(0));
      assert sum = exp(0) report "sum fail" severity error;
      assert cout = exp(1) report "cout fail" severity error;
    end loop;
    report "all cases passed" severity note;
    wait;
  end process;
end tb;
