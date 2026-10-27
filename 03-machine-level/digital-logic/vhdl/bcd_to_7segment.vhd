-- BCD to 7-segment (common cathode, active high). segments a..g = seg(6..0)
-- ghdl -a bcd_to_7segment.vhd bcd_to_7segment_tb.vhd && ghdl -e bcd_to_7segment_tb && ghdl -r bcd_to_7segment_tb
library ieee;
use ieee.std_logic_1164.all;

entity bcd_to_7segment is
  port (bcd : in std_logic_vector(3 downto 0);
        seg : out std_logic_vector(6 downto 0));
end bcd_to_7segment;

architecture behavioural of bcd_to_7segment is
begin
  process (bcd)
  begin
    case bcd is
      when "0000" => seg <= "1111110";
      when "0001" => seg <= "0110000";
      when "0010" => seg <= "1101101";
      when "0011" => seg <= "1111001";
      when "0100" => seg <= "0110011";
      when "0101" => seg <= "1011011";
      when "0110" => seg <= "1011111";
      when "0111" => seg <= "1110000";
      when "1000" => seg <= "1111111";
      when "1001" => seg <= "1111011";
      when others => seg <= "0000000";
    end case;
  end process;
end behavioural;
