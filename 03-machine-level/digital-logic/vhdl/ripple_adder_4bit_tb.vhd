library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity ripple_adder_4bit_tb is end ripple_adder_4bit_tb;
architecture tb of ripple_adder_4bit_tb is
  signal a, b, sum : std_logic_vector(3 downto 0);
  signal cin, cout : std_logic;
begin
  dut : entity work.ripple_adder_4bit port map (a, b, cin, sum, cout);
  process
    variable ea, eb : integer;
    variable res : unsigned(4 downto 0);
  begin
    cin <= '0';
    for ea in 0 to 15 loop
      for eb in 0 to 15 loop
        a <= std_logic_vector(to_unsigned(ea, 4));
        b <= std_logic_vector(to_unsigned(eb, 4));
        wait for 2 ns;
        res := to_unsigned(ea + eb, 5);
        assert sum = std_logic_vector(res(3 downto 0)) report "sum fail" severity error;
        assert cout = res(4) report "cout fail" severity error;
      end loop;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
