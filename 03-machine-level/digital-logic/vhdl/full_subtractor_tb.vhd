library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity full_subtractor_tb is end full_subtractor_tb;
architecture tb of full_subtractor_tb is
  signal a, b, bin, diff, borrow : std_logic;
begin
  dut : entity work.full_subtractor port map (a, b, bin, diff, borrow);
  process
    variable v : std_logic_vector(2 downto 0);
    variable d : integer;
  begin
    for i in 0 to 7 loop
      v := std_logic_vector(to_unsigned(i, 3));
      a <= v(2); b <= v(1); bin <= v(0);
      wait for 5 ns;
      d := (to_integer(unsigned'("" & v(2)))) - to_integer(unsigned'("" & v(1))) - to_integer(unsigned'("" & v(0)));
      assert diff = (a xor b xor bin) report "diff fail" severity error;
      if d < 0 then
        assert borrow = '1' report "borrow fail" severity error;
      else
        assert borrow = '0' report "borrow fail" severity error;
      end if;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
