library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity binary_to_gray_tb is end binary_to_gray_tb;
architecture tb of binary_to_gray_tb is
  signal b, g : std_logic_vector(3 downto 0);
begin
  dut : entity work.binary_to_gray port map (b, g);
  process
    variable exp : std_logic_vector(3 downto 0);
  begin
    for i in 0 to 15 loop
      b <= std_logic_vector(to_unsigned(i, 4));
      wait for 2 ns;
      exp := std_logic_vector(to_unsigned(i, 4) xor to_unsigned(i/2, 4));
      assert g = exp report "gray fail" severity error;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
