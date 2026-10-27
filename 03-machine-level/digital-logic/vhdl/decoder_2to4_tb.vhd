library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity decoder_2to4_tb is end decoder_2to4_tb;
architecture tb of decoder_2to4_tb is
  signal a : std_logic_vector(1 downto 0);
  signal en : std_logic;
  signal y : std_logic_vector(3 downto 0);
begin
  dut : entity work.decoder_2to4 port map (a, en, y);
  process
  begin
    en <= '0'; a <= "00"; wait for 5 ns;
    assert y = "0000" report "disabled fail" severity error;
    en <= '1';
    for i in 0 to 3 loop
      a <= std_logic_vector(to_unsigned(i, 2));
      wait for 5 ns;
      for k in 0 to 3 loop
        if k = i then assert y(k)='1' report "dec hi fail" severity error;
        else assert y(k)='0' report "dec lo fail" severity error; end if;
      end loop;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
