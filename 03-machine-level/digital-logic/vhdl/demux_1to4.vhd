-- 1:4 demultiplexer.  ghdl -a demux_1to4.vhd demux_1to4_tb.vhd && ghdl -e demux_1to4_tb && ghdl -r demux_1to4_tb
library ieee;
use ieee.std_logic_1164.all;

entity demux_1to4 is
  port (din : in std_logic;
        sel : in std_logic_vector(1 downto 0);
        y : out std_logic_vector(3 downto 0));
end demux_1to4;

architecture behavioural of demux_1to4 is
begin
  process (din, sel)
  begin
    y <= "0000";
    case sel is
      when "00" => y(0) <= din;
      when "01" => y(1) <= din;
      when "10" => y(2) <= din;
      when others => y(3) <= din;
    end case;
  end process;
end behavioural;
