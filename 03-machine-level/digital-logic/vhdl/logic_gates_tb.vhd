-- testbench for logic_gates
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity logic_gates_tb is end logic_gates_tb;

architecture tb of logic_gates_tb is
  signal a, b : std_logic;
  signal g_and, g_or, g_not, g_nand, g_nor, g_xor, g_xnor : std_logic;
begin
  dut : entity work.logic_gates
    port map (a, b, g_and, g_or, g_not, g_nand, g_nor, g_xor, g_xnor);

  process
    variable v : std_logic_vector(1 downto 0);
  begin
    for i in 0 to 3 loop
      v := std_logic_vector(to_unsigned(i, 2));
      a <= v(1); b <= v(0);
      wait for 5 ns;
      assert g_and  = (a and b)  report "and fail"  severity error;
      assert g_or   = (a or b)   report "or fail"   severity error;
      assert g_not  = (not a)    report "not fail"  severity error;
      assert g_nand = (a nand b) report "nand fail" severity error;
      assert g_nor  = (a nor b)  report "nor fail"  severity error;
      assert g_xor  = (a xor b)  report "xor fail"  severity error;
      assert g_xnor = (a xnor b) report "xnor fail" severity error;
    end loop;
    report "all cases passed" severity note;
    wait;
  end process;
end tb;
