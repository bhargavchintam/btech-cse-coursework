-- 4-bit magnitude comparator.  ghdl -a comparator_4bit.vhd comparator_4bit_tb.vhd && ghdl -e comparator_4bit_tb && ghdl -r comparator_4bit_tb
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity comparator_4bit is
  port (a, b : in std_logic_vector(3 downto 0);
        a_gt_b, a_eq_b, a_lt_b : out std_logic);
end comparator_4bit;

architecture behavioural of comparator_4bit is
begin
  process (a, b)
  begin
    if unsigned(a) > unsigned(b) then
      a_gt_b <= '1'; a_eq_b <= '0'; a_lt_b <= '0';
    elsif unsigned(a) = unsigned(b) then
      a_gt_b <= '0'; a_eq_b <= '1'; a_lt_b <= '0';
    else
      a_gt_b <= '0'; a_eq_b <= '0'; a_lt_b <= '1';
    end if;
  end process;
end behavioural;
