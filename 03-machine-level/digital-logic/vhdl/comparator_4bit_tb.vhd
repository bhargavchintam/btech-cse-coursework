library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity comparator_4bit_tb is end comparator_4bit_tb;
architecture tb of comparator_4bit_tb is
  signal a, b : std_logic_vector(3 downto 0);
  signal gt, eq, lt : std_logic;
begin
  dut : entity work.comparator_4bit port map (a, b, gt, eq, lt);
  process
  begin
    for i in 0 to 15 loop
      for j in 0 to 15 loop
        a <= std_logic_vector(to_unsigned(i, 4));
        b <= std_logic_vector(to_unsigned(j, 4));
        wait for 1 ns;
        if i > j then assert gt='1' and eq='0' and lt='0' report "gt fail" severity error;
        elsif i = j then assert gt='0' and eq='1' and lt='0' report "eq fail" severity error;
        else assert gt='0' and eq='0' and lt='1' report "lt fail" severity error; end if;
      end loop;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
