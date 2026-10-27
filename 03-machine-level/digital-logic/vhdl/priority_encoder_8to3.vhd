-- 8:3 priority encoder (highest input wins) with valid.
-- ghdl -a priority_encoder_8to3.vhd priority_encoder_8to3_tb.vhd && ghdl -e priority_encoder_8to3_tb && ghdl -r priority_encoder_8to3_tb
library ieee;
use ieee.std_logic_1164.all;

entity priority_encoder_8to3 is
  port (d : in std_logic_vector(7 downto 0);
        y : out std_logic_vector(2 downto 0);
        valid : out std_logic);
end priority_encoder_8to3;

architecture behavioural of priority_encoder_8to3 is
begin
  process (d)
  begin
    if    d(7) = '1' then y <= "111";
    elsif d(6) = '1' then y <= "110";
    elsif d(5) = '1' then y <= "101";
    elsif d(4) = '1' then y <= "100";
    elsif d(3) = '1' then y <= "011";
    elsif d(2) = '1' then y <= "010";
    elsif d(1) = '1' then y <= "001";
    else                  y <= "000";
    end if;
    if d = "00000000" then valid <= '0'; else valid <= '1'; end if;
  end process;
end behavioural;
