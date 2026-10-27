library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity demux_1to4_tb is end demux_1to4_tb;
architecture tb of demux_1to4_tb is
  signal din : std_logic;
  signal sel : std_logic_vector(1 downto 0);
  signal y : std_logic_vector(3 downto 0);
begin
  dut : entity work.demux_1to4 port map (din, sel, y);
  process
  begin
    din <= '1';
    for s in 0 to 3 loop
      sel <= std_logic_vector(to_unsigned(s, 2));
      wait for 5 ns;
      for k in 0 to 3 loop
        if k = s then assert y(k)='1' report "demux hi fail" severity error;
        else assert y(k)='0' report "demux lo fail" severity error; end if;
      end loop;
    end loop;
    report "all cases passed" severity note; wait;
  end process;
end tb;
