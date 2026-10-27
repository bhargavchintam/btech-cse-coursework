-- 2:4 decoder, active high, with enable.  ghdl -a decoder_2to4.vhd decoder_2to4_tb.vhd && ghdl -e decoder_2to4_tb && ghdl -r decoder_2to4_tb
library ieee;
use ieee.std_logic_1164.all;

entity decoder_2to4 is
  port (a : in std_logic_vector(1 downto 0);
        en : in std_logic;
        y : out std_logic_vector(3 downto 0));
end decoder_2to4;

architecture behavioural of decoder_2to4 is
begin
  process (a, en)
  begin
    y <= "0000";
    if en = '1' then
      case a is
        when "00" => y(0) <= '1';
        when "01" => y(1) <= '1';
        when "10" => y(2) <= '1';
        when others => y(3) <= '1';
      end case;
    end if;
  end process;
end behavioural;
